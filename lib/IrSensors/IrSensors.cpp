// IrSensors library
// copyright Dave Sieh, 2013
// This code is public domain, enjoy!

#include <Arduino.h>
#include "IrSensors.h"

const char *sensorNames[] = {
  "Left",
  "Center",
  "Right"
};

IrSensors::IrSensors(int leftPin, int centerPin, int rightPin) {
  irSensorPins[IrLeft] = leftPin;
  irSensorPins[IrCenter] = centerPin;
  irSensorPins[IrRight] = rightPin;
}

void IrSensors::begin() {
  for (int sensor = 0; sensor < NUM_IR_SENSORS; sensor++) {
    calibrate((IrSensor)sensor);
  }
}

boolean IrSensors::hasValidPin(IrSensor sensor) {
  return irSensorPins[sensor] >= 0;
}

boolean IrSensors::highReflectionDetected(IrSensor sensor) {
  boolean result = false; // default value

  if (! hasValidPin(sensor)) {
    return false;
  }

  int value = analogRead(irSensorPins[sensor]); // get IR light level

  if (value <= irSensorReflect[sensor]) {
    // Object detected (lower value means more reflection)
    result = true; 
    if (! isDetected[sensor]) { 
      // Only print on initial detection
      Serial.print(sensorNames[sensor]);         
      Serial.println(" object detected");
    }
  }

  isDetected[sensor] = result; 
  return result;
}

boolean IrSensors::lowReflectionDetected(IrSensor sensor) {
  boolean result = false; // default value

  if (! hasValidPin(sensor)) {
    return false;
  }

  int value = analogRead(irSensorPins[sensor]); // get IR light level

  if (value >= irSensorEdge[sensor]) {
    // edge detected (higher value means less reflection)
    result = true; 
    if (isDetected[sensor] == false) { 
      // only print on initial detection
      Serial.print(sensorNames[sensor]);         
      Serial.println(" edge detected");
    }
  }

  isDetected[sensor] = result; 
  return result;
}

void IrSensors::calibrate(IrSensor sensor) {

  if (hasValidPin(sensor)) {
    int ambient = analogRead(irSensorPins[sensor]); // get ambient level
    irSensorAmbient[sensor] = ambient; 

    // precalculate the levels for object and edge detection  
    irSensorReflect[sensor] = (ambient * (long)(100 - irReflectThreshold)) / 100;
    irSensorEdge[sensor]    = (ambient * (long)(100 + irEdgeThreshold)) / 100; 
  }
}
