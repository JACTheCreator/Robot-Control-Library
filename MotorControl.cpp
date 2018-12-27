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
DC_Motor::DC_Motor(uint8_t in1, uint8_t in2) : _frontLeftIn1(in1), _frontLeftIn2(in2)
{
  _noOfWheels = 1;
  _usesPWM = false;
}

/**
* @brief      Initialize the pins for a DC motor with speed control.
*
* @param[in]  in1   The pin on the arduino that controls the positive polarity of the motor.
* @param[in]  in2   The pin on the arduino that controls the negative polarity of the motor.
* @param[in]  pwm   The Pulse Width Modulation(PWM) pin on the arduino for the motor.
*/
DC_Motor::DC_Motor(uint8_t in1, uint8_t in2, uint8_t pwm) : _frontLeftIn1(in1), _frontLeftIn2(in2), _pwmFrontLeft(pwm)
{
  _noOfWheels = 1;
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
DC_Motor::DC_Motor(uint8_t leftIn1, uint8_t leftIn2, uint8_t rightIn1, uint8_t rightIn2) : _frontLeftIn1(leftIn1), _frontLeftIn2(leftIn2), _frontRightIn1(rightIn1), _frontRightIn2(rightIn2)
{
  _noOfWheels = 2;
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
DC_Motor::DC_Motor(uint8_t leftIn1, uint8_t leftIn2, uint8_t pwmLeft, uint8_t rightIn1, uint8_t rightIn2, uint8_t pwmRight) : _frontLeftIn1(leftIn1), _frontLeftIn2(leftIn2), _pwmFrontLeft(pwmLeft), _frontRightIn1(rightIn1), _frontRightIn2(rightIn2), _pwmFrontRight(pwmRight)
{
  _noOfWheels = 2;
  _usesPWM = true;
}

DC_Motor::DC_Motor(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t backRightIn1, uint8_t backRightIn2) : _frontLeftIn1(frontLeftIn1), _frontLeftIn2(frontLeftIn2),  _pwmFrontLeft(pwmFrontLeft), _frontRightIn1(frontRightIn1), _frontRightIn2(frontRightIn2), _pwmFrontRight(pwmFrontRight),_backLeftIn1(backLeftIn1), _backLeftIn2(backLeftIn2), _pwmBackLeft(pwmBackLeft), _backRightIn1(backRightIn1), _backRightIn2(backRightIn2), _pwmBackRight(pwmBackRight)
{
  _noOfWheels = 4;
  _usesPWM = false;
}

DC_Motor::DC_Motor(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t pwmFrontLeft, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t pwmFrontRight, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t pwmBackLeft, uint8_t backRightIn1, uint8_t backRightIn2, uint8_t pwmBackRight) : _frontLeftIn1(frontLeftIn1), _frontLeftIn2(frontLeftIn2),  _pwmFrontLeft(pwmFrontLeft), _frontRightIn1(frontRightIn1), _frontRightIn2(frontRightIn2), _pwmFrontRight(pwmFrontRight),_backLeftIn1(backLeftIn1), _backLeftIn2(backLeftIn2), _pwmBackLeft(pwmBackLeft), _backRightIn1(backRightIn1), _backRightIn2(backRightIn2), _pwmBackRight(pwmBackRight)
{
  _noOfWheels = 4;
  _usesPWM = true;
}

/**
* @brief      Configures a specified pin to behave either as an input or an output.
*/
void DC_Motor::init(void)
{
  switch(_noOfWheels)
	{
		case 4:
			pinMode(_backLeftIn1, OUTPUT);
			pinMode(_backLeftIn2, OUTPUT);.

			pinMode(_backRightIn1, OUTPUT);
			pinMode(_backRightIn2, OUTPUT);
			if(_usesPWM)
			{
				pinMode(_pwmBackLeft, OUTPUT);
				pinMode(_pwmBackRight, OUTPUT);
			}

		case 2:
			pinMode(_frontRightIn1, OUTPUT);
			pinMode(_frontRightIn2, OUTPUT);
			if(_usesPWM)
			{
				pinMode(_pwmFrontRight, OUTPUT);
			}

		case 1:
			pinMode(_frontLeftIn1, OUTPUT);
			pinMode(_frontLeftIn2, OUTPUT);
			if(_usesPWM)
			{
				pinMode(_pwmFrontLeft, OUTPUT);
			}
	}
}

/**
* @brief      Moves the robot (motor(s)) forward.
*/
void DC_Motor::forward(void)
{
	switch(_noOfWheels)
	{
		case 4:
			digitalWrite(_backLeftIn1, HIGH);
			digitalWrite(_backLeftIn2, LOW);

			digitalWrite(_backRightIn1, HIGH);
			digitalWrite(_backRightIn2, LOW);

		case 2:
			digitalWrite(_frontRightIn1, HIGH);
			digitalWrite(_frontRightIn2, LOW);

		case 1:
			digitalWrite(_frontLeftIn1, HIGH);
			digitalWrite(_frontLeftIn2, LOW);
	}
}

/**
* @brief      Moves the robot (motor(s)) backwards.
*/
void DC_Motor::reverse(void)
{
	switch(_noOfWheels)
	{
		case 4:
			digitalWrite(_backLeftIn1, LOW);
			digitalWrite(_backLeftIn2, HIGH);

			digitalWrite(_backRightIn1, LOW);
			digitalWrite(_backRightIn2, HIGH);

		case 2:
			digitalWrite(_frontRightIn1, LOW);
			digitalWrite(_frontRightIn2, HIGH);

		case 1:
			digitalWrite(_frontLeftIn1, LOW);
			digitalWrite(_frontLeftIn2, HIGH);
	}
}

/**
* @brief      Moves the robot (motor(s)) left.
*/
void DC_Motor::left(void)
{
	switch(_noOfWheels)
	{
		case 4:
			digitalWrite(_backLeftIn1, HIGH);
			digitalWrite(_backLeftIn2, LOW);

			digitalWrite(_backRightIn1, LOW);
			digitalWrite(_backRightIn2, HIGH);

		case 2:
			digitalWrite(_frontRightIn1, HIGH);
			digitalWrite(_frontRightIn2, LOW);

			digitalWrite(_frontLeftIn1, LOW);
			digitalWrite(_frontLeftIn2, HIGH);
	}
}

/**
* @brief      Moves the robot (motor(s)) right.
*/
void DC_Motor::right(void)
{
	switch(_noOfWheels)
	{
		case 4:
			digitalWrite(_backLeftIn1, LOW);
			digitalWrite(_backLeftIn2, HIGH);

			digitalWrite(_backRightIn1, HIGH);
			digitalWrite(_backRightIn2, LOW);

		case 2:
			digitalWrite(_frontRightIn1, LOW);
			digitalWrite(_frontRightIn2, HIGH);

			digitalWrite(_frontLeftIn1, HIGH);
			digitalWrite(_frontLeftIn2, LOW);
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
  switch(_noOfWheels)
	{
		case 4:
			digitalWrite(_backLeftIn1, HIGH);
			digitalWrite(_backLeftIn2, LOW);
			analogWrite(_pwmBackLeft, _speed);

			digitalWrite(_backRightIn1, HIGH);
			digitalWrite(_backRightIn2, LOW);
			analogWrite(_pwmBackRight, _speed);

		case 2:
			digitalWrite(_frontRightIn1, HIGH);
			digitalWrite(_frontRightIn2, LOW);
			analogWrite(_pwmFrontRight, _speed);

		case 1:
			digitalWrite(_frontLeftIn1, HIGH);
			digitalWrite(_frontLeftIn2, LOW);
			analogWrite(_pwmFrontLeft, _speed);
	}
}

/**
* @brief      Moves the robot (motor(s)) backwards at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::reverse(uint8_t speed)
{
  _speed = speed;
  switch(_noOfWheels)
	{
		case 4:
			digitalWrite(_backLeftIn1, LOW);
			digitalWrite(_backLeftIn2, HIGH);
			analogWrite(_pwmBackLeft, _speed);

			digitalWrite(_backRightIn1, LOW);
			digitalWrite(_backRightIn2, HIGH);
			analogWrite(_pwmBackRight, _speed);

		case 2:
			digitalWrite(_frontRightIn1, LOW);
			digitalWrite(_frontRightIn2, HIGH);
			analogWrite(_pwmFrontRight, _speed);

		case 1:
			digitalWrite(_frontLeftIn1, LOW);
			digitalWrite(_frontLeftIn2, HIGH);
			analogWrite(_pwmFrontLeft, _speed);
	}
}

/**
* @brief      Moves the robot (motor(s)) left at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::left(uint8_t speed)
{
  _speed = speed;
  switch(_noOfWheels)
	{
		case 4:
			digitalWrite(_backLeftIn1, HIGH);
			digitalWrite(_backLeftIn2, LOW);
			analogWrite(_pwmBackLeft, _speed);

			digitalWrite(_backRightIn1, LOW);
			digitalWrite(_backRightIn2, HIGH);
			analogWrite(_pwmBackRight, _speed);

		case 2:
			digitalWrite(_frontRightIn1, HIGH);
			digitalWrite(_frontRightIn2, LOW);
			analogWrite(_pwmFrontRight, _speed);

			digitalWrite(_frontLeftIn1, LOW);
			digitalWrite(_frontLeftIn2, HIGH);
			analogWrite(_pwmFrontLeft, _speed);
	}
}

/**
* @brief      Moves the robot (motor(s)) right at a set rate.
*
* @param[in]  speed  The rate at which the motor(s) moves.
*/
void DC_Motor::right(uint8_t speed)
{
  _speed = speed;
  switch(_noOfWheels)
	{
		case 4:
			digitalWrite(_backLeftIn1, LOW);
			digitalWrite(_backLeftIn2, HIGH);
			analogWrite(_pwmBackLeft, _speed);

			digitalWrite(_backRightIn1, HIGH);
			digitalWrite(_backRightIn2, LOW);
			analogWrite(_pwmBackRight, _speed);

		case 2:
			digitalWrite(_frontRightIn1, LOW);
			digitalWrite(_frontRightIn2, HIGH);
			analogWrite(_pwmFrontRight, _speed);

			digitalWrite(_frontLeftIn1, HIGH);
			digitalWrite(_frontLeftIn2, LOW);
			analogWrite(_pwmFrontLeft, _speed); 
	}
}

/**
* @brief      Stops the motor if it is moving
*/
void DC_Motor::stop()
{
  _speed = 0;

  switch(_noOfWheels)
	{
		case 4:
			digitalWrite(_backLeftIn1, LOW);
			digitalWrite(_backLeftIn2, LOW);
			
			digitalWrite(_backRightIn1, LOW);
			digitalWrite(_backRightIn2, LOW);
			if(_usesPWM)
			{
				analogWrite(_pwmBackLeft, _speed);
				analogWrite(_pwmBackRight, _speed);
			}

		case 2:
			digitalWrite(_frontRightIn1, LOW);
			digitalWrite(_frontRightIn2, LOW);

			digitalWrite(_frontLeftIn1, LOW);
			digitalWrite(_frontLeftIn2, LOW);

			if(_usesPWM)
			{
				analogWrite(_pwmFrontRight, _speed);
				analogWrite(_pwmFrontLeft, _speed); 
			}
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