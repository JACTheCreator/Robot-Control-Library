This is C++ library for Arduino for controlling various types of motors(Servo
motor, DC motor, Stepper Motor) on a robot.

#Installation
--------------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in your
Arduino/lib/targets/libraries folder.

When installed, this library should look like:

Arduino/lib/targets/libraries/MotorControl                   (this library's folder)
Arduino/lib/targets/libraries/MotorControl/MotorControl.cpp  (the library implementation file)
Arduino/lib/targets/libraries/MotorControl/MotorControl.h    (the library description file)
Arduino/lib/targets/libraries/MotorControl/keywords.txt      (the syntax coloring file)
Arduino/lib/targets/libraries/MotorControl/examples          (the examples in the "open" menu)
Arduino/lib/targets/libraries/MotorControl/readme.txt        (this file)

#Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select Test.  This will add a corresponding line to the top of your sketch:
#include <MotorControl.h>

To stop using this library, delete that line from your sketch.

Geeky information:
After a successful build of this library, a new file named "MotorControl.o" will appear
in "Arduino/lib/targets/libraries/MotorControl". This file is the built/compiled library
code.

If you choose to modify the code for this library (i.e. "MotorControl.cpp" or "MotorControl.h"),
then you must first 'unbuild' this library by deleting the "MotorControl.o" file. The
new "MotorControl.o" with your code will appear after the next press of "verify"

#Disclaimer
--------------------------------------------------------------------------------
At this time the project is incomplete and on untested therefore contains errors
or/and bugs.
