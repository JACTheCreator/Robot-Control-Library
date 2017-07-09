/**
* @file MotorControl.cpp
* @author Jermaine Coates @JACTheCreator
* @brief This is C++ library for Arduino for controlling various motors of the
* same type simultaneously(Servo motor, DC motor, Stepper Motor) on a robot.
*/
#include "MotorControl.h"

const uint8_t FORWARD_ACTION[3] = {HIGH, LOW, FORWARD};
const uint8_t BACKWARD_ACTION[3] = {LOW, HIGH, BACKWARD};
const uint8_t STOP_ACTION[3] = {HIGH, HIGH, BRAKE};

/**********************
        DC Motor
 **********************/

DC_Motor::DC_Motor(uint8_t noOfWheels, char* motorShieldOption) :
_noOfWheels(noOfWheels)
{
    char _motorShieldOption = *motorShieldOption;
    switch (noOfWheels)
    {
      case 4:
        backLeftMotor = AF_DCMotor(4);
        backRightMotor = AF_DCMotor(3);

      case 2:
        frontRightMotor = AF_DCMotor(2);

      case 1:
        frontLeftMotor = AF_DCMotor(1);
      break;

      default:
        // Serial.println("Sorry we do NOT support " + noOfWheels + "wheels")
      break;
    }

    if(noOfWheels == 4)  isFourWheel = true;
    if(noOfWheels == 2)  isTwoWheel = true;
    if(noOfWheels == 1)  isOneWheel = true;
}

/**
* @brief      Initialize the pins for a DC motor.
*
* @param[in]  in1   The pin on the arduino that controls the positive polarity
* of the motor.
* @param[in]  in2   The pin on the arduino that controls the negative polarity
* of the motor.
*/
DC_Motor::DC_Motor(uint8_t in1, uint8_t in2) : _frontLeftIn1(in1),
_frontLeftIn2(in2)
{
  isOneWheel = true;
}

/**
* @brief      Initialize the pins for a DC motor with speed control.
*
* @param[in]  in1   The pin on the arduino that controls the positive polarity
* of the motor.
* @param[in]  in2   The pin on the arduino that controls the negative polarity
* of the motor.
* @param[in]  pwm   The Pulse Width Modulation(PWM) pin on the arduino for the
* motor.
*/
DC_Motor::DC_Motor(uint8_t in1, uint8_t in2, uint8_t pwm) : _frontLeftIn1(in1),
_frontLeftIn2(in2), _pwmFrontLeft(pwm)
{
  isOneWheel = true;
  _usesPWM = true;
}

/**
* @brief      Initialize the pins for two DC motor.
*
* @param[in]  leftIn1   The pin on the arduino that controls the positive
* polarity of the (left) motor.
* @param[in]  leftIn2   The pin on the arduino that controls the negative
* polarity of the (left) motor.
* @param[in]  rightIn1  The pin on the arduino that controls the positive
* polarity of the (right) motor.
* @param[in]  rightIn2  The pin on the arduino that controls the negative
* polarity of the (right) motor.
*/
DC_Motor::DC_Motor(uint8_t leftIn1, uint8_t leftIn2, uint8_t rightIn1,
uint8_t rightIn2) : _frontLeftIn1(leftIn1), _frontLeftIn2(leftIn2),
_frontRightIn1(rightIn1), _frontRightIn2(rightIn2)
{
  isTwoWheel = true;
}

/**
* @brief      Initialize the pins for two DC motor with speed control
*
* @param[in]  leftIn1   The pin on the arduino that controls the positive
* polarity of the (left) motor.
* @param[in]  leftIn2   The pin on the arduino that controls the negative
* polarity of the (left) motor.
* @param[in]  pwmLeft   The Pulse Width Modulation(PWM) pin on the arduino for
*  the (left) motor.
* @param[in]  rightIn1  The pin on the arduino that controls the positive
* polarity of the (right) motor.
* @param[in]  rightIn2  The pin on the arduino that controls the negative
* polarity of the (right) motor.
* @param[in]  pwmRight  The Pulse Width Modulation(PWM) pin on the arduino for
* the (right) motor.
*/
DC_Motor::DC_Motor(uint8_t leftIn1, uint8_t leftIn2, uint8_t pwmLeft,
uint8_t rightIn1, uint8_t rightIn2, uint8_t pwmRight) : _frontLeftIn1(leftIn1),
_frontLeftIn2(leftIn2), _pwmFrontLeft(pwmLeft), _frontRightIn1(rightIn1),
_frontRightIn2(rightIn2), _pwmFrontRight(pwmRight)
{
  isTwoWheel = true;
  _usesPWM = true;
}


DC_Motor::DC_Motor(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t backRightIn1, uint8_t backRightIn2) : _frontLeftIn1(frontLeftIn1), _frontLeftIn2(frontLeftIn2), _frontRightIn1(frontRightIn1), _frontRightIn2(frontRightIn2), _backLeftIn1(backLeftIn1), _backLeftIn2(backLeftIn2), _backRightIn1(backRightIn1), _backRightIn2(backRightIn2)
{
  isTwoWheel = true;
}

DC_Motor::DC_Motor(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t pwmFrontLeft, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t pwmFrontRight, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t pwmBackLeft, uint8_t backRightIn1, uint8_t backRightIn2, uint8_t pwmBackRight) : _frontLeftIn1(frontLeftIn1), _frontLeftIn2(frontLeftIn2),  _pwmFrontLeft(pwmFrontLeft), _frontRightIn1(frontRightIn1), _frontRightIn2(frontRightIn2), _pwmFrontRight(pwmFrontRight),_backLeftIn1(backLeftIn1), _backLeftIn2(backLeftIn2), _pwmBackLeft(pwmBackLeft), _backRightIn1(backRightIn1), _backRightIn2(backRightIn2), _pwmBackRight(pwmBackRight)
{
  isFourWheel = true;
  _usesPWM = true;
}

/**
* @brief      Configures a specified pin to behave either as an input or an output.
*/
void DC_Motor::init(void)
{
  switch (_motorShieldOption)
  {
    case NONE:
      if(isOneWheel)
      {
        pinMode(_frontLeftIn1, OUTPUT);
        pinMode(_frontLeftIn2, OUTPUT);
        if(_usesPWM)
        {
          pinMode(_pwmFrontLeft, OUTPUT);
        }
      }
      else if(isTwoWheel)
      {
        pinMode(_frontLeftIn1, OUTPUT);
        pinMode(_frontLeftIn2, OUTPUT);

        pinMode(_frontRightIn1, OUTPUT);
        pinMode(_frontRightIn1, OUTPUT);
        if(_usesPWM)
        {
          pinMode(_pwmFrontLeft, OUTPUT);
          pinMode(_pwmFrontRight, OUTPUT);
        }
        else if(isFourWheel)
        {
        }
      }
    break;

    case ADAFRUIT_V1:
    break;

    case ADAFRUIT_V2:
    break;

    default:
    break;
  }
}

/**
* @brief      Moves the robot (motor(s)) forward.
*/
void DC_Motor::forward(void)
{
  if(isOneWheel)
  {
    oneDCMotor(FORWARD_ACTION);
  }
  else if(isTwoWheel)
  {
    DC_Motor::twoDCMotors(FORWARD_ACTION, FORWARD_ACTION);
  }
}

/**
* @brief      Moves the robot (motor(s)) backwards.
*/
void DC_Motor::reverse(void)
{
  if(isOneWheel)
  {
    oneDCMotor(BACKWARD_ACTION);
  }
  else if(isTwoWheel)
  {
    DC_Motor::twoDCMotors(BACKWARD_ACTION, BACKWARD_ACTION);
  }
}

/**
* @brief      Moves the robot (motor(s)) left.
*/
void DC_Motor::left(void)
{
  if(isTwoWheel)
  {
    DC_Motor::twoDCMotors(BACKWARD_ACTION, FORWARD_ACTION);
  }
}

/**
* @brief      Moves the robot (motor(s)) right.
*/
void DC_Motor::right(void)
{
  if(isTwoWheel)
  {
    DC_Motor::twoDCMotors(BACKWARD_ACTION, FORWARD_ACTION);
  }
}

/**
* @brief      Moves the robot (motor(s)) forward at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::forward(uint8_t speed)
{
  _speed = speed;
  DC_Motor::forward();
}

/**
* @brief      Moves the robot (motor(s)) backwards at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::reverse(uint8_t speed)
{
  _speed = speed;
  DC_Motor::reverse();
}

/**
* @brief      Moves the robot (motor(s)) left at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::left(uint8_t speed)
{
  _speed = speed;
  DC_Motor::left();
}

/**
* @brief      Moves the robot (motor(s)) right at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::right(uint8_t speed)
{
  _speed = speed;
  DC_Motor::right();
}

/**
* @brief      Stops the motor if it is moving
*/
void DC_Motor::stop()
{
  _speed = 0;
  if(isOneWheel)
  {
    oneDCMotor(STOP_ACTION);
  }
  if(isTwoWheel)
  {
    DC_Motor::twoDCMotors(STOP_ACTION, STOP_ACTION);
  }
}
/****************************

*****************************/

void DC_Motor::oneDCMotor(const uint8_t* leftMotorDirection)
{
  switch (_motorShieldOption)
  {
    case NONE:
      digitalWrite(_frontLeftIn1, leftMotorDirection[0]);
      digitalWrite(_frontLeftIn2, leftMotorDirection[1]);
      if(_usesPWM)
      {
        analogWrite(_pwmFrontLeft, _speed);
      }
    break;

    case ADAFRUIT_V1:
      frontLeftMotor.run(leftMotorDirection[2]);
    break;
  }
}

void DC_Motor::twoDCMotors(const uint8_t* leftMotorDirection, const uint8_t* rightMotorDirection)
{
  DC_Motor::oneDCMotor(leftMotorDirection);
  switch (_motorShieldOption)
  {
    case NONE:
      digitalWrite(_frontRightIn1, rightMotorDirection[0]);
      digitalWrite(_frontRightIn2, rightMotorDirection[1]);
      if(_usesPWM)
      {
        analogWrite(_pwmFrontRight, _speed);
      }
    break;

    case ADAFRUIT_V1:
      frontRightMotor.run(rightMotorDirection[2]);
    break;
  }
}

void DC_Motor::fourDCMotors()
{
  // DC_Motor::twoDCMotors();
  switch (_motorShieldOption)
  {
    case NONE:
    break;

    case ADAFRUIT_V1:
      // backLeftMotor.run(FORWARD);
      // backRightMotor.run(FORWARD);
    break;
  }
}

/****************************
  ROBOT CONTROL - DC MOTOR
*****************************/
/**
* @brief      Operating and controlling the direction of the motor(s).
*
* @param[in]  direction  The course along which the robot (motor(s)) moves.
*/
void DC_Motor::drive(uint8_t direction)
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
void DC_Motor::drive(uint8_t direction, uint8_t speed)
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
