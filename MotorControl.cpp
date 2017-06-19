#include "MotorControl.h"

/**********************
        DC Motor
 **********************/
DC_Motor::DC_Motor(int in1, int in2) : _leftIn1(in1), _leftIn2(in2)
{
  isOneWheel = true;
  isTwoWheel = false;
  _usesPWM = false;
}

DC_Motor::DC_Motor(int in1, int in2, int pwm) : _leftIn1(in1), _leftIn2(in2), _pwmLeft(pwm)
{
  isOneWheel = true;
  isTwoWheel = false;
  _usesPWM = true;
}

DC_Motor::DC_Motor(int leftIn1, int leftIn2, int rightIn1, int rightIn2) : _leftIn1(leftIn1), _leftIn2(leftIn2), _rightIn1(rightIn1), _rightIn2(rightIn2)
{
  isOneWheel = false;
  isTwoWheel = true;
  _usesPWM = false;
}

DC_Motor::DC_Motor(int leftIn1, int leftIn2, int pwmLeft, int rightIn1, int rightIn2, int pwmRight) : _leftIn1(leftIn1), _leftIn2(leftIn2), _pwmLeft(pwmLeft), _rightIn1(rightIn1), _rightIn2(rightIn2), _pwmRight(pwmRight)
{
  isOneWheel = false;
  isTwoWheel = true;
  _usesPWM = true;
}

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


void DC_Motor::forward(int speed) : _speed(speed)
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

void DC_Motor::reverse(int speed) : _speed(speed)
{
  //Anti-clockwise
  digitalWrite(_leftIn1, LOW);
  digitalWrite(_leftIn2, HIGH);
  analogWrite(_pwmLeft, _speed);

  //Anti-clockwise
  digitalWrite(_rightIn1, LOW);
  digitalWrite(_rightIn2, HIGH);
  analogWrite(_pwmRight,_speed);
}

void DC_Motor::left(int speed) : _speed(speed)
{
  //Clockwise
  digitalWrite(_leftIn1, LOW);
  digitalWrite(_leftIn2, HIGH);
  analogWrite(_pwmLeft, _speed);

  //Anti-clockwise
  digitalWrite(_rightIn1, HIGH);
  digitalWrite(_rightIn2, LOW);
  analogWrite(_pwmRight, _speed)
}

void DC_Motor::right(int speed) : _speed(speed)
{
  //Anti-clockwise
  digitalWrite(_leftIn1, LOW);
  digitalWrite(_leftIn2, HIGH);
  analogWrite(_pwmLeft, _speed);

  //Clockwise
  digitalWrite(_rightIn1, HIGH);
  digitalWrite(_rightIn2, LOW);
  analogWrite(_pwmRight, _speed)
}

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
  analogWrite(_pwmRight, _speed)
}

/****************************
  ROBOT CONTROL - DC MOTOR
*****************************/
DC_Motor::drive(direction)
{
  switch(direction)
  {
    case FORWARD:
      DC_Motor::forward(void);
    break;

    case REVERSE:
      DC_Motor::reverse(void);
    break;

    case LEFT:
      DC_Motor::left(void);
    break;

    case RIGHT:
      DC_Motor::right(void);
    break;

    case STOP:
      DC_Motor::stop(void);
    break;
  }
}

DC_Motor::drive(direction, speed)
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
      DC_Motor::stop(speed);
    break;
  }
}
