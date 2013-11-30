// LEDBlinker library
// copyright Dave Sieh, 2013
// This code is public domain, enjoy!

#ifndef _LEDBlinker_h_
#define _LEDBlinker_h_

/**
   This class provides methods to make it easy to notify end-users
   of stuff via an LED display. Simply initialize an LEDBlinker object with
   the pin to control. That's it.
 */
class LEDBlinker {
 public:
  /**
     Which pin to you want to blink on?
   */
  LEDBlinker(int ledPin);

  /**
     This will cause the LED to blink the number of times specified.
   */
  void blinkNumber(int number);

 private:
  int pin;
};

#endif