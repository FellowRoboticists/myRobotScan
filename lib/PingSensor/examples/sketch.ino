// -*- c -*- 
#include <PingSensor.h>

// We're going to use a Ping))) sensor connected to
// Pin 5.
PingSensor pinger(5);

void setup()
{
  // Just get the distance
  int distance = pinger.getDistance();
  // Get a a distance averaged over 4 samples.
  distance = pinger.getAverageDistance(4);
}

void loop()
{
}
