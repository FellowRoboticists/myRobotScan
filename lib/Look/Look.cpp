// Look library
// copyright Dave Sieh, 2013
// This code is public domain, enjoy!

#include <Arduino.h>
#include "Look.h"
#include "SoftServo.h"
#include "IrSensors.h"
#include "PingSensor.h"

Look::Look(SoftServo *sweepServo, IrSensors *sensors, PingSensor *pingSensor) {
  servo = sweepServo;
  irSensors = sensors;
  ping = pingSensor;
}

void Look::begin() {
  if (servo) {
    servo->begin();
  }

  if (irSensors) {
    irSensors->begin();
  }

  if (ping) {
    ping->begin();
  }
}

boolean Look::irEdgeDetect(IrSensor sensor) {
  boolean detected = false;
  if (irSensors) {
    detected = irSensors->lowReflectionDetected(sensor);
  }
  return detected;
}

boolean Look::sensesObstacle(ObstacleType obstacle, int minDistance) {
  switch(obstacle) {
  case  OBST_FRONT_EDGE: 
    return irEdgeDetect(IrLeft) && irEdgeDetect(IrRight); 
  case  OBST_LEFT_EDGE:  
    return irEdgeDetect(IrLeft); 
  case  OBST_RIGHT_EDGE: 
    return irEdgeDetect(IrRight); 
  case  OBST_FRONT:     
    return lookAt(DIR_CENTER) <= minDistance;      
  }
  return false; 
}

int Look::lookAt(LookDirection direction) {
  int angle = servoAngles[direction];
  // wait for servo to get into position
  servo->write(angle, servoDelay);

  int distance = (ping) ? ping->getAverageDistance(4) : 0; // distaceToObstacle();

  if (angle != servoAngles[DIR_CENTER]) {
    // Print only if looking right/left
    Serial.print("looking at dir "); 
    Serial.print(angle), Serial.print(" distance= "); 
    Serial.println(distance); 
    
    // Re-center the servo
    servo->write(servoAngles[DIR_CENTER], servoDelay / 2);    
  } 

  return distance;   
}
