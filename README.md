myRobotScan
===========

An Arduino sketch to allow a Robot to wander around and use a Ping))) sensor to look around.

Programmed Behavior
===================

When first turned on, the robot will move forward.

If an obstacle appears within 18" in the direction of forward motion, then
the robot will stop. It will look left, then right. Whichever direction has
the greatest distance to an obstacle in that direction will be chosen as the
preferred direction to move next. If the distance in that direction is
greater than 30" the robot will rotate to that direction and commence moving
forward again. If the distance was less than 15", the robot will move backward
for 1 second then will attempt a 180 rotation, then commence moving forward
again. If the distance is greater than 15", rotate left if the left had more 
clearance, rotate right if the right had more clearance, and randomly turn right
or left if the distances are equal.

Simple.

In the current implementation, edge detection is turned off so don't point the 
robot towards a stairwell.

Building/Testing
================

Preparation:

1. Determine the directory in which you will place the myRobotScan project
2. Clone the https://github.com/FellowRoboticists/arduino-tasks project. This provides the necessary ruby tasks use by the rake command.
3. Clone the https://github.com/FellowRoboticists/myRobotScan project.
4. In the myRobotScan project directory, invoke the 'rake' command. This will automatically pull all the dependency libraries from GitHub and prepare the ino project for building.

To build the example sketch:

```
ino build
```

To upload the example sketch:

```
ino upload
```

Copyright
=========

Copyright (c) 2012 Michael Margolis

Copyright (c) 2013,2014 Dave Sieh

See LICENSE.txt for details.
