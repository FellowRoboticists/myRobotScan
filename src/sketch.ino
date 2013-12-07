// -*- c -*-
#include "RobotMotor.h"
#include <LEDBlinker.h>
#include <SoftServo.h>
#include <IrSensors.h>
#include <PingSensor.h>
#include <Look.h>
#include <Move.h>

// Analog Pins
#define LEFT_IR_SENSOR_PIN 0
#define RIGHT_IR_SENSOR_PIN 1
#define CENTER_IR_SENSOR_PIN 2

// Digital Pins
#define PING_SENSOR_PIN 10

#define SWEEP_SERVO_PIN 9
#define LED_PIN 13

LEDBlinker blinker(LED_PIN);
SoftServo sweepServo(SWEEP_SERVO_PIN);
IrSensors irSensors(LEFT_IR_SENSOR_PIN, CENTER_IR_SENSOR_PIN, RIGHT_IR_SENSOR_PIN);
PingSensor pingSensor(PING_SENSOR_PIN);
Look looker(&sweepServo, &irSensors, &pingSensor);
Move mover(&looker);

void setup()
{
  Serial.begin(9600);
  blinker.begin();
  blinker.blinkNumber(8); // We do this for Leonardo (not sure why)

  // Prep the movement system
  mover.begin();

  // Set the initial speed of the robot - 10% above minimum speed
  mover.setSpeed(MIN_SPEED + 10);

  // Center the servo
  sweepServo.write(90, 2000);

  // Seed the random number generator from the ambient light
  // level on the left sensor
  randomSeed(irSensors.getAmbientLevel(IrLeft));

  Serial.println("Ready");
}

void loop()
{
  // Each time around the loop, we will set the Robot to move forward...
  mover.forward();

  // Then look around to see which way we can really go.
  mover.roam();
}
