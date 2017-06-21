#include <MotorControl.h>

//Pins the Motor is connected to -> 8 and 9
DC_Motor oneMotor(8, 9); // also MotorControl oneMotor = MotorControl(8, 9)

void setup()
{
  oneMotor.init();
}

void loop()
{
  oneMotor.drive(FORWARD); // Spin the motor forward
  delay(1000);
  oneMotor.drive(REVERSE); // Spin the motor backwards
}
