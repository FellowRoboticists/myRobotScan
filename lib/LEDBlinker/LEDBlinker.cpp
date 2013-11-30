// LEDBlinker library
// copyright Dave Sieh, 2013
// This code is public domain, enjoy!

#include <Arduino.h>
#include "LEDBlinker.h"

LEDBlinker::LEDBlinker(int ledPin) {
  pin = ledPin;
}

void LEDBlinker::blinkNumber(int number) {
  pinMode(pin, OUTPUT); // enable the pin for output

  while (number--) {
    digitalWrite(pin, HIGH); 
    delay(100);
    digitalWrite(pin, LOW); 
    delay(400);
  }
}
