#pragma once

#include "IDriver.hpp"
#include "Motor.hpp"
#include <memory>

class Driver : public IDriver
{
public:
    Driver(Motor& p_leftMotor, Motor& p_rightMotor);
    void backward(unsigned int speed);
    void forward(unsigned int speed);
    void backward();
    void forward();
    void turnRight();
    void turnLeft();
    void stay();

private:
    Motor& m_leftMotor;
    Motor& m_rightMotor;
};
