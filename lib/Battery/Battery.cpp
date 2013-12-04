// Battery library
// copyright Dave Sieh, 2013
// This code is public domain, enjoy!

#include <Arduino.h>
#include "Battery.h"
#include "LEDBlinker.h"
#include "Move.h"

Battery::Battery(int monitorPin, int chargerPin, LEDBlinker *ledBlinker) {
  pin = monitorPin;
  chargePin = chargerPin;
  led = ledBlinker;
}

void Battery::begin() {
  if (led) {
    led->begin();
  }
}

void Battery::check(Move *mover) {
  int mv = batteryMv(); // Get battery level in millivolts
  Serial.print("mv = ");
  Serial.print(mv);
  if (chargePin >= 0 && digitalRead(chargePin) == HIGH) {
    // Got here if charger detect is enabled and charger is plugged in
    while (digitalRead(chargePin) == HIGH) {
      // While charger is plugged in
      if (mover) {
	mover->stop();
      }
      mv = batteryMv();
      Serial.print(", charger detected, voltage = ");
      int percent = map(mv, batteryCritical, batteryFull, 50, 100);
      percent = constrain(percent, 0, 100);
      Serial.println(percent);
      led->flash(percent);
    }
  } else {
    if (mv < batteryCritical) {
      Serial.println("Critical");
      if (mover) {
	// Shut down the robot
	mover->stop();
      }
      while (1) {
        led->flashCritical();
        // Check if the charger is plugged in 
        if (chargePin >= 0 && digitalRead(chargePin) == HIGH) {
          return; // Exit if charging
        }
        delay(5000); // Wait 5 seconds
      }
    } else if (mv < batteryWarning) {
      int percent = map(mv, batteryCritical, batteryWarning, 10, 50);
      led->flash(percent);
    }
  }
  delay(1000);
  Serial.println();
}

int Battery::batteryMv() {
#if defined(__AVR_ATmega32U4__) // Is this a Leonardo board?
  const long INTERNAL_REFERENCE_MV = 2560; // Leo reference is 2.56 volts
#else
  const long INTERNAL_REFERENCE_MV = 1100; // ATmega328 is 1.1 volts
#endif
  const float R1 = 18.0; // Voltage divider values
  const float R2 = 2.2;
  const float DIVISOR = R2 / (R1 + R2);
  
  analogReference(INTERNAL); // Set reference to internal (1.1V)
  analogRead(pin); // Allow the ADC to settle
  delay(10);
  
  int value = 0;
  for (int i=0; i < 8; i++) {
      value = value + analogRead(pin);
  }
  value = value / 8; // Get the average of 8 readings
  int mv = map(value, 0, 1023, 0, INTERNAL_REFERENCE_MV / DIVISOR);
  
  analogReference(DEFAULT); // Set the reference back to default (Vcc)
  analogRead(pin);  // Just to let the ADC settle ready for next reading
  delay(10); // Allow reference to stabilise
  
  return mv;
}
