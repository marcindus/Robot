#include "Robot.hpp"

Robot::Robot(Driver& p_driver) : m_driver(p_driver)
{
}

void Robot::setLeftCorrection(unsigned int corr)
{
    m_driver.m_leftMotor.setCorrection(corr);
}
void Robot::setRightCorrection(unsigned int corr)
{
    m_driver.m_rightMotor.setCorrection(corr);
}

void Robot::goBackward(unsigned int speed)
{
    m_driver.backward(speed);
}
void Robot::goBackward()
{
    m_driver.backward();
}


void Robot::goForward(unsigned int speed)
{
    m_driver.forward(speed);
}
void Robot::goForward()
{
    m_driver.forward();
}


void Robot::turnRight()
{
    m_driver.turnRight();
}

void Robot::turnLeft()
{
    m_driver.turnLeft();
}

void Robot::stepForward()
{
}

void Robot::stepBackward()
{
}

void Robot::run()
{
}

void Robot::stay()
{
    m_driver.stay();
}

