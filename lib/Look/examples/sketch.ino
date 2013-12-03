// -*- c -*-
// Look library
// copyright Dave Sieh, 2013
// This code is public domain, enjoy!
#include <Look.h>
#include <IrSensors.h>
#include <SoftServo.h>
#include <PingSensor.h>

SoftServo servo(9);
IrSensors sensors(1, 2, 3);
PingSensor ping(8);
Look looker(&servo, &sensors, &ping);

void setup()
{
  looker.begin();
}

void loop()
{
}
