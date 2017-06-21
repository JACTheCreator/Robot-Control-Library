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

class MotorControl
{
public:
    MotorControl(){}
    virtual ~MotorControl(){}
    virtual void forward(void)=0;
    virtual void reverse(void)=0;
    virtual void left(void)=0;
    virtual void right(void)=0;
    virtual void forward(int)=0;
    virtual void reverse(int)=0;
    virtual void left(int)=0;
    virtual void right(int)=0;
    virtual void stop(void)=0;
};

class DC_Motor : public MotorControl
{
  public:
    DC_Motor(int in1, int in2);
    DC_Motor(int in1, int in2, int pwm);
    DC_Motor(int leftIn1, int leftIn2, int rightIn1, int rightIn2);
    DC_Motor(int leftIn1, int leftIn2, int pwmLeft, int rightIn1, int rightIn2, int pwmRight);
    ~DC_Motor(void){};
    void init(void);
    void drive(int direction);
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
    void forward(void) override;
    void forward(int) override;
    void reverse(void) override;
    void reverse(int) override;
    void left(void) override;
    void left(int) override;
    void right(void) override;
    void right(int) override;
    void stop(void) override;
};

#endif //__MOTORCONTROL_H__
