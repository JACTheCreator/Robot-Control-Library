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
    virtual void forward(uint8_t speed)=0;
    virtual void reverse(uint8_t speed)=0;
    virtual void left(uint8_t speed)=0;
    virtual void right(uint8_t speed)=0;
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
    DC_Motor(uint8_t in1, uint8_t in2);

    /**
     * @brief      Initialize the pins for a DC motor with speed control.
     *
     * @param[in]  in1   The pin on the arduino that controls the positive polarity of the motor.
     * @param[in]  in2   The pin on the arduino that controls the negative polarity of the motor.
     * @param[in]  pwm   The Pulse Width Modulation(PWM) pin on the arduino for the motor.
     */
    DC_Motor(uint8_t in1, uint8_t in2, uint8_t pwm);

    /**
     * @brief      Initialize the pins for two DC motor.
     *
     * @param[in]  leftIn1   The pin on the arduino that controls the positive polarity of the (left) motor.
     * @param[in]  leftIn2   The pin on the arduino that controls the negative polarity of the (left) motor.
     * @param[in]  rightIn1  The pin on the arduino that controls the positive polarity of the (right) motor.
     * @param[in]  rightIn2  The pin on the arduino that controls the negative polarity of the (right) motor.
     */
    DC_Motor(uint8_t leftIn1, uint8_t leftIn2, uint8_t rightIn1, uint8_t rightIn2);

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
    DC_Motor(uint8_t leftIn1, uint8_t leftIn2, uint8_t pwmLeft, uint8_t rightIn1, uint8_t rightIn2, uint8_t pwmRight);

    /**
     * @brief      Initialize the pins for four DC motor.
     *
     * @param[in]  frontLeftIn1   The pin on the arduino that controls the positive polarity of the (front left) motor.
     * @param[in]  frontLeftIn2   The pin on the arduino that controls the negative polarity of the (front left) motor.
     * @param[in]  frontRightIn1  The pin on the arduino that controls the positive polarity of the (front right) motor.
     * @param[in]  frontRightIn2  The pin on the arduino that controls the negative polarity of the (front right) motor.
     * @param[in]  backLeftIn1  The pin on the arduino that controls the positive polarity of the (back left) motor.
     * @param[in]  backLeftIn2  The pin on the arduino that controls the negative polarity of the (back left) motor.
     * @param[in]  backRightIn1  The pin on the arduino that controls the positive polarity of the (back right) motor.
     * @param[in]  backRightIn2  The pin on the arduino that controls the negative polarity of the (back right) motor.
     */
    DC_Motor(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t backRightIn1, uint8_t backRightIn2);

    /**
     * @brief      Initialize the pins for four DC motor with speed control
     *
     * @param[in]  frontLeftIn1   The pin on the arduino that controls the positive polarity of the (front left) motor.
     * @param[in]  frontLeftIn2   The pin on the arduino that controls the negative polarity of the (front left) motor.
     * @param[in]  pwmFrontLeft   The Pulse Width Modulation(PWM) pin on the arduino for the (front left) motor.
     * @param[in]  frontRightIn1  The pin on the arduino that controls the positive polarity of the (front right) motor.
     * @param[in]  frontRightIn2  The pin on the arduino that controls the negative polarity of the (front right) motor.
     * @param[in]  pwmFrontRight  The Pulse Width Modulation(PWM) pin on the arduino for the (front right) motor.
     * @param[in]  backLeftIn1  The pin on the arduino that controls the positive polarity of the (back left) motor.
     * @param[in]  backLeftIn2  The pin on the arduino that controls the negative polarity of the (back left) motor.
     * @param[in]  pwmBackLeft The Pulse Width Modulation(PWM) pin on the arduino for the (back left) motor.
     * @param[in]  backRightIn1  The pin on the arduino that controls the positive polarity of the (back right) motor.
     * @param[in]  backRightIn2  The pin on the arduino that controls the negative polarity of the (back right) motor.
     * @param[in]  pwmBackRight  The Pulse Width Modulation(PWM) pin on the arduino for the (back right) motor.
     */
    DC_Motor(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t pwmFrontLeft, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t pwmFrontRight, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t pwmBackLeft, uint8_t backRightIn1, uint8_t backRightIn2, uint8_t pwmBackRight);

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
    void drive(uint8_t direction);

    /**
     * @brief      Operating and controlling the direction and speed of the motor(s).
     *
     * @param[in]  direction  The course along which the robot (motor(s)) moves.
     * @param[in]  speed      The rate at which the motor(s) moves.
     */
    void drive(uint8_t direction, uint8_t speed);

  private:
    uint8_t _frontLeftIn1;
    uint8_t _frontLeftIn2;
    uint8_t _frontRightIn1;
    uint8_t _frontRightIn2;
    uint8_t _pwmFrontLeft;
    uint8_t _pwmFrontRight;

    uint8_t _backLeftIn1;
    uint8_t _backLeftIn2;
    uint8_t _backRightIn1;
    uint8_t _backRightIn2;
    uint8_t _pwmBackLeft;
    uint8_t _pwmBackRight;
    uint8_t _speed;

    uint8_t _noOfWheels;
    bool _usesPWM = false;

    /**
     * @brief      Moves the robot (motor(s)) forward.
     */
    void forward(void) override;

    /**
     * @brief      Moves the robot (motor(s)) forward at a set rate.
     *
     * @param[in]  speed  The rate at which the motor(s) moves.
     */
    void forward(uint8_t speed) override;

    /**
     * @brief      Moves the robot (motor(s)) backwards.
     */
    void reverse(void) override;

    /**
     * @brief      Moves the robot (motor(s)) backwards at a set rate.
     *
     * @param[in]  speed  The rate at which the motor(s) moves.
     */
    void reverse(uint8_t speed) override;

    /**
     * @brief      Moves the robot (motor(s)) left.
     */
    void left(void) override;

    /**
     * @brief      Moves the robot (motor(s)) left at a set rate.
     *
     * @param[in]  speed  The rate at which the motor(s) moves.
     */
    void left(uint8_t speed) override;

    /**
     * @brief      Moves the robot (motor(s)) right.
     */
    void right(void) override;

    /**
     * @brief      Moves the robot (motor(s)) right at a set rate.
     *
     * @param[in]  speed  The rate at which the motor(s) moves.
     */
    void right(uint8_t speed) override;

    /**
     * @brief      Stops the motor if it is moving
     */
    void stop(void) override;
};

#endif //__MOTORCONTROL_H__