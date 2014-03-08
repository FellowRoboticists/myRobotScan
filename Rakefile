# -*- ruby -*-
# myRobotScan Arduino sketch
#
# Copyright (c) 2012 Michael Margolis
# Copyright (c) 2013,2014 Dave Sieh
#
# See LICENSE.txt for details.
#
# Put the parent directory on the Ruby Load path
$: << File.dirname(File.dirname(__FILE__))

# Bring in the task support
require 'arduino-tasks/tasks'
include ArduinoTasks

BASE_DIR = '..'

env = ArduinoEnvironment.new BASE_DIR

LIBS = [
  library('AFMotor', 'Adafruit-Motor-Shield-library', 'robot_kit'),
  library('RobotMotor'),
  library('SoftServo'),
  library('pspc_support')
]

create_all_library_tasks env, LIBS, :default
