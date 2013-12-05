# -*- ruby -*-

LIBDIR = 'lib'
SKETCHBOOK = File.join(ENV['HOME'], 'sketchbook')
LIBRARIES = File.join(SKETCHBOOK, 'libraries')

# Any libraries defined in this project should be
# specified below
LIBS = %w{ Battery IrSensors LEDBlinker Look Move PingSensor SoftServo }

task :default => :libraries

task :libraries do
  LIBS.each do | library |
    cp_r File.join(LIBDIR, library), LIBRARIES
  end
end


