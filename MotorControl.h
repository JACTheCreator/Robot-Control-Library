/**
* @file MotorControl.h
* @author Jermaine Coates @JACTheCreator
* @brief This is C++ library for Arduino for controlling various motors of the same type simultaneously(Servo motor, DC motor, Stepper Motor) on a robot.
*/

#ifndef __MOTORCONTROL_H__
#define __MOTORCONTROL_H__

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#define FORWARD 1
#define REVERSE 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

/**
 * @brief      Defines the direction the Robot (motor(s)) will move in.
 */
class MotorControl
{
public:
    MotorControl(){}
    virtual ~MotorControl(){}
    virtual void forward(void)=0;
    virtual void reverse(void)=0;
    virtual void left(void)=0;
    virtual void right(void)=0;
    virtual void forward(int speed)=0;
    virtual void reverse(int speed)=0;
    virtual void left(int speed)=0;
    virtual void right(int speed)=0;
    virtual void stop(void)=0;
};

/**
 * @brief      Controls a DC Motor movement.
 */
class DC_Motor : public MotorControl
{
  public:
    /**
     * @brief      Initialize the pins for a DC motor.
     *
     * @param[in]  in1   The pin on the arduino that controls the positive polarity of the motor.
     * @param[in]  in2   The pin on the arduino that controls the negative polarity of the motor.
     */
    DC_Motor(int in1, int in2);

    /**
     * @brief      Initialize the pins for a DC motor with speed control.
     *
     * @param[in]  in1   The pin on the arduino that controls the positive polarity of the motor.
     * @param[in]  in2   The pin on the arduino that controls the negative polarity of the motor.
     * @param[in]  pwm   The Pulse Width Modulation(PWM) pin on the arduino for the motor.
     */
    DC_Motor(int in1, int in2, int pwm);

    /**
     * @brief      Initialize the pins for two DC motor.
     *
     * @param[in]  leftIn1   The pin on the arduino that controls the positive polarity of the (left) motor.
     * @param[in]  leftIn2   The pin on the arduino that controls the negative polarity of the (left) motor.
     * @param[in]  rightIn1  The pin on the arduino that controls the positive polarity of the (right) motor.
     * @param[in]  rightIn2  The pin on the arduino that controls the negative polarity of the (right) motor.
     */
    DC_Motor(int leftIn1, int leftIn2, int rightIn1, int rightIn2);

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
    DC_Motor(int leftIn1, int leftIn2, int pwmLeft, int rightIn1, int rightIn2, int pwmRight);

    /**
     * @brief      Destroys the object.
     */
    ~DC_Motor(void){};

    /**
     * @brief      Configures a specified pin to behave either as an input or an output.
     */
    void init(void);

    /**
     * @brief      Operating and controlling the direction of the motor(s).
     *
     * @param[in]  direction  The course along which the robot (motor(s)) moves.
     */
    void drive(int direction);

    /**
     * @brief      Operating and controlling the direction and speed of the motor(s).
     *
     * @param[in]  direction  The course along which the robot (motor(s)) moves.
     * @param[in]  speed      The rate at which the motor(s) moves.
     */
    void drive(int direction, int speed);

  private:
    int _leftIn1;
    int _leftIn2;
    int _rightIn1;
    int _rightIn2;
    int _pwmLeft;
    int _pwmRight;
    int _speed;
    bool _usesPWM = false;
    bool isOneWheel = false;
    bool isTwoWheel = false;

    /**
     * @brief      Moves the robot (motor(s)) forward.
     */
    void forward(void) override;

    /**
     * @brief      Moves the robot (motor(s)) forward at a set rate.
     *
     * @param[in]  speed  The rate at which the motor(s) moves.
     */
    void forward(int speed) override;

    /**
     * @brief      Moves the robot (motor(s)) backwards.
     */
    void reverse(void) override;

    /**
     * @brief      Moves the robot (motor(s)) backwards at a set rate.
     *
     * @param[in]  speed  The rate at which the motor(s) moves.
     */
    void reverse(int speed) override;

    /**
     * @brief      {Moves the robot (motor(s)) left.
     */
    void left(void) override;

    /**
     * @brief      Moves the robot (motor(s)) left at a set rate.
     *
     * @param[in]  speed  The rate at which the motor(s) moves.
     */
    void left(int speed) override;

    /**
     * @brief      Moves the robot (motor(s)) right.
     */
    void right(void) override;

    /**
     * @brief      Moves the robot (motor(s)) right at a set rate.
     *
     * @param[in]  speed  The rate at which the motor(s) moves.
     */
    void right(int speed) override;

    /**
     * @brief      Stops the motor if it is moving
     */
    void stop(void) override;
};

#endif //__MOTORCONTROL_H__
