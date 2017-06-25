/**
* @file MotorControl.cpp
* @author Jermaine Coates @JACTheCreator
* @brief This is C++ library for Arduino for controlling various motors of the same type simultaneously(Servo motor, DC motor, Stepper Motor) on a robot.
*/

#include "MotorControl.h"

/**********************
        DC Motor
 **********************/
/**
* @brief      Initialize the pins for a DC motor.
*
* @param[in]  in1   The pin on the arduino that controls the positive polarity of the motor.
* @param[in]  in2   The pin on the arduino that controls the negative polarity of the motor.
*/
DC_Motor::DC_Motor(int in1, int in2) : _leftIn1(in1), _leftIn2(in2)
{
  isOneWheel = true;
  isTwoWheel = false;
  _usesPWM = false;
}

/**
* @brief      Initialize the pins for a DC motor with speed control.
*
* @param[in]  in1   The pin on the arduino that controls the positive polarity of the motor.
* @param[in]  in2   The pin on the arduino that controls the negative polarity of the motor.
* @param[in]  pwm   The Pulse Width Modulation(PWM) pin on the arduino for the motor.
*/
DC_Motor::DC_Motor(int in1, int in2, int pwm) : _leftIn1(in1), _leftIn2(in2), _pwmLeft(pwm)
{
  isOneWheel = true;
  isTwoWheel = false;
  _usesPWM = true;
}

/**
* @brief      Initialize the pins for two DC motor.
*
* @param[in]  leftIn1   The pin on the arduino that controls the positive polarity of the (left) motor.
* @param[in]  leftIn2   The pin on the arduino that controls the negative polarity of the (left) motor.
* @param[in]  rightIn1  The pin on the arduino that controls the positive polarity of the (right) motor.
* @param[in]  rightIn2  The pin on the arduino that controls the negative polarity of the (right) motor.
*/
DC_Motor::DC_Motor(int leftIn1, int leftIn2, int rightIn1, int rightIn2) : _leftIn1(leftIn1), _leftIn2(leftIn2), _rightIn1(rightIn1), _rightIn2(rightIn2)
{
  isOneWheel = false;
  isTwoWheel = true;
  _usesPWM = false;
}

/**
* @brief      Initialize the pins for two DC motor with speed control
*
* @param[in]  leftIn1   The pin on the arduino that controls the positive polarity of the (left) motor.
* @param[in]  leftIn2   The pin on the arduino that controls the negative polarity of the (left) motor.
* @param[in]  pwmLeft   The Pulse Width Modulation(PWM) pin on the arduino for the (left) motor.
* @param[in]  rightIn1  The pin on the arduino that controls the positive polarity of the (right) motor.
* @param[in]  rightIn2  The pin on the arduino that controls the negative polarity of the (right) motor.
* @param[in]  pwmRight  The Pulse Width Modulation(PWM) pin on the arduino for the (right) motor.
*/
DC_Motor::DC_Motor(int leftIn1, int leftIn2, int pwmLeft, int rightIn1, int rightIn2, int pwmRight) : _leftIn1(leftIn1), _leftIn2(leftIn2), _pwmLeft(pwmLeft), _rightIn1(rightIn1), _rightIn2(rightIn2), _pwmRight(pwmRight)
{
  isOneWheel = false;
  isTwoWheel = true;
  _usesPWM = true;
}

/**
* @brief      Configures a specified pin to behave either as an input or an output.
*/
void DC_Motor::init(void)
{
  if(isOneWheel)
  {
    pinMode(_leftIn1, OUTPUT);
    pinMode(_leftIn2, OUTPUT);
    if(_usesPWM)
    {
      pinMode(_pwmLeft, OUTPUT);
    }
  }
  else if(isTwoWheel)
  {
    pinMode(_leftIn1, OUTPUT);
    pinMode(_leftIn2, OUTPUT);

    pinMode(_rightIn1, OUTPUT);
    pinMode(_rightIn2, OUTPUT);
    if(_usesPWM)
    {
      pinMode(_pwmLeft, OUTPUT);
      pinMode(_pwmRight, OUTPUT);
    }
  }
}

/**
* @brief      Moves the robot (motor(s)) forward.
*/
void DC_Motor::forward(void)
{
  //Clockwise
  digitalWrite(_leftIn1, HIGH);
  digitalWrite(_leftIn2, LOW);

  if(isTwoWheel)
  {
    //Clockwise
    digitalWrite(_rightIn1, HIGH);
    digitalWrite(_rightIn2, LOW);
  }
}

/**
* @brief      Moves the robot (motor(s)) backwards.
*/
void DC_Motor::reverse(void)
{
  //Anti-clockwise
  digitalWrite(_leftIn1, LOW);
  digitalWrite(_leftIn2, HIGH);

  if(isTwoWheel)
  {
    //Anti-clockwise
    digitalWrite(_rightIn1, LOW);
    digitalWrite(_rightIn2, HIGH);
  }
}

/**
* @brief      Moves the robot (motor(s)) left.
*/
void DC_Motor::left(void)
{
  if(isTwoWheel)
  {
    //Clockwise
    digitalWrite(_leftIn1, LOW);
    digitalWrite(_leftIn2, HIGH);

    //Anti-clockwise
    digitalWrite(_rightIn1, HIGH);
    digitalWrite(_rightIn2, LOW);
  }
}

/**
* @brief      Moves the robot (motor(s)) right.
*/
void DC_Motor::right(void)
{
  if(isTwoWheel)
  {
    //Anti-clockwise
    digitalWrite(_leftIn1, LOW);
    digitalWrite(_leftIn2, HIGH);

    //Clockwise
    digitalWrite(_rightIn1, HIGH);
    digitalWrite(_rightIn2, LOW);
  }
}

/**
* @brief      Moves the robot (motor(s)) forward at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::forward(int speed)
{
  _speed = speed;
  //Clockwise
  digitalWrite(_leftIn1, HIGH);
  digitalWrite(_leftIn2, LOW);

  if(isTwoWheel)
  {
    //Clockwise
    digitalWrite(_rightIn1, HIGH);
    digitalWrite(_rightIn2, LOW);
  }
}

/**
* @brief      Moves the robot (motor(s)) backwards at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::reverse(int speed)
{
  _speed = speed;
  //Anti-clockwise
  digitalWrite(_leftIn1, LOW);
  digitalWrite(_leftIn2, HIGH);
  analogWrite(_pwmLeft, _speed);

  //Anti-clockwise
  digitalWrite(_rightIn1, LOW);
  digitalWrite(_rightIn2, HIGH);
  analogWrite(_pwmRight,_speed);
}

/**
* @brief      Moves the robot (motor(s)) left at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::left(int speed)
{
  _speed = speed;
  //Clockwise
  digitalWrite(_leftIn1, LOW);
  digitalWrite(_leftIn2, HIGH);
  analogWrite(_pwmLeft, _speed);

  //Anti-clockwise
  digitalWrite(_rightIn1, HIGH);
  digitalWrite(_rightIn2, LOW);
  analogWrite(_pwmRight, _speed);
}

/**
* @brief      Moves the robot (motor(s)) right at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::right(int speed)
{
  _speed = speed;
  //Anti-clockwise
  digitalWrite(_leftIn1, LOW);
  digitalWrite(_leftIn2, HIGH);
  analogWrite(_pwmLeft, _speed);

  //Clockwise
  digitalWrite(_rightIn1, HIGH);
  digitalWrite(_rightIn2, LOW);
  analogWrite(_pwmRight, _speed);
}

/**
* @brief      Stops the motor if it is moving
*/
void DC_Motor::stop()
{
  _speed = 0;

  //Anti-clockwise
  digitalWrite(_leftIn1, HIGH);
  digitalWrite(_leftIn2, HIGH);
  analogWrite(_pwmLeft, _speed);

  //Clockwise
  digitalWrite(_rightIn1, HIGH);
  digitalWrite(_rightIn2, HIGH);
  analogWrite(_pwmRight, _speed);
}

/****************************
  ROBOT CONTROL - DC MOTOR
*****************************/
/**
* @brief      Operating and controlling the direction of the motor(s).
*
* @param[in]  direction  The course along which the robot (motor(s)) moves.
*/
void DC_Motor::drive(int direction)
{
  switch(direction)
  {
    case FORWARD:
      DC_Motor::forward();
    break;

    case REVERSE:
      DC_Motor::reverse();
    break;

    case LEFT:
      DC_Motor::left();
    break;

    case RIGHT:
      DC_Motor::right();
    break;

    case STOP:
      DC_Motor::stop();
    break;
  }
}

/**
* @brief      Operating and controlling the direction and speed of the motor(s).
*
* @param[in]  direction  The course along which the robot (motor(s)) moves.
* @param[in]  speed      The rate at which the motor(s) moves.
*/
void DC_Motor::drive(int direction, int speed)
{
  switch(direction)
  {
    case FORWARD:
      DC_Motor::forward(speed);
    break;

    case REVERSE:
      DC_Motor::reverse(speed);
    break;

    case LEFT:
      DC_Motor::left(speed);
    break;

    case RIGHT:
      DC_Motor::right(speed);
    break;

    case STOP:
      DC_Motor::stop();
    break;
  }
}
