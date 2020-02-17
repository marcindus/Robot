#include "Driver.hpp"
#include <iostream>
#include <unistd.h>

Driver::Driver(Motor& p_leftMotor, Motor& p_rightMotor) : m_leftMotor(p_leftMotor), m_rightMotor(p_rightMotor)
{
}

void Driver::backward()
{
    m_leftMotor.runBackward();
    m_rightMotor.runBackward();
}

void Driver::forward()
{
    m_leftMotor.runForward();
    m_rightMotor.runForward();
}

void Driver::backward(unsigned int speed)
{
    m_leftMotor.runBackward(speed);
    m_rightMotor.runBackward(speed);
}

void Driver::forward(unsigned int speed)
{
    m_leftMotor.runForward(speed);
    m_rightMotor.runForward(speed);
}

void Driver::turnRight()
{
//    m_rightMotor.stop();
    m_rightMotor.runBackward();
    m_leftMotor.runForward();
}
void Driver::turnLeft()
{
    //m_leftMotor.stop();
    m_leftMotor.runBackward();
    m_rightMotor.runForward();
}
void Driver::stay()
{
    m_leftMotor.stop();
    m_rightMotor.stop();
}
