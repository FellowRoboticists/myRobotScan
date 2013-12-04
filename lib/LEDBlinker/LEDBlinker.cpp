// LEDBlinker library
// copyright Dave Sieh, 2013
// This code is public domain, enjoy!

#include <Arduino.h>
#include "LEDBlinker.h"

LEDBlinker::LEDBlinker(int ledPin) {
  pin = ledPin;
}

void LEDBlinker::begin() {
  pinMode(pin, OUTPUT);
}

void LEDBlinker::blinkNumber(int number) {
  while (number--) {
    digitalWrite(pin, HIGH); 
    delay(100);
    digitalWrite(pin, LOW); 
    delay(400);
  }
}

void LEDBlinker::flash(int percent) {
  Serial.print(", flash percent = ");
  Serial.println(percent);
  const int duration = 1000;
  // Blink the LED
  digitalWrite(pin, HIGH);
  int onTime = map(percent, 0, 100, 0, duration);
  delay(onTime);
  digitalWrite(pin, LOW);
  delay(duration - onTime);
}

void LEDBlinker::flashCritical() {
  for (int i = 0; i < 3; i++) {
    flash(20);
  }
  for (int i = 0; i < 3; i++) {
    flash(60);
  }
  for (int i = 0; i < 3; i++) {
    flash(20);
  }
}
