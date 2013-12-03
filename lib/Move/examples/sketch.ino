// -*- c -*-
// Move library
// copyright Dave Sieh, 2013
// This code is public domain, enjoy!

#include <Move.h>
#include <Look.h>
#include <IrSensors.h>
#include <SoftServo.h>
#include <PingSensor.h>

SoftServo servo(9);
IrSensors sensors(1, 2, 3);
PingSensor ping(8);
Look looker(&servo, &sensors, &ping);
Move mover(&looker);

void setup()
{
  mover.begin();
  mover.left();
}

void loop()
{
}
