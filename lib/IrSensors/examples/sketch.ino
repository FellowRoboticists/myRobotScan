// -*- c -*-
#include <IrSensors.h>

// Set up the IR Sensors with the following pins:
// Left - 0
// Center - 2
// Right - 1
IrSensors sensors(0, 2, 1);

void setup()
{
  // Initialize the sensors
  sensors.begin();
  // Determine if the left sensor detected a high reflectance
  boolean detected = sensors.highReflectionDetected(IrLeft);
  // Determine if the center sensor detected a lower reflectance
  detected = sensors.lowReflectionDetected(IrCenter);
}

void loop()
{
}
