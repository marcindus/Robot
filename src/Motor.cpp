#include "Motor.hpp"

Motor::Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin) :
        m_speedPin(std::move(p_speedPin)),
        m_directionPin(std::move(p_directionPin))
{}

Motor::Motor(std::unique_ptr<IGpioPort> p_speedPin,
             std::unique_ptr<IGpioPort> p_directionPin,
             unsigned int p_correction,
             unsigned int p_minSpeed) :
        m_speedPin(std::move(p_speedPin)),
        m_directionPin(std::move(p_directionPin)),
        m_correction(p_correction),
        m_minSpeed(p_minSpeed)
{
}


void Motor::runForward(unsigned int speed)
{
    m_directionPin->write(GpioDigitalValue::GpioValue_Low);
    if((speed - m_correction) >= m_minSpeed)
    {
        m_speedPin->write(speed - m_correction);
    }
    else if(speed == 0)
    {
        m_speedPin->write(0);
    }
    else
    {
       m_speedPin->write(m_minSpeed);
    }
    m_direction = MotorDirection::Forward;
    m_isRunning = true;
}

void Motor::stop()
{
    m_speedPin->write(0);
    m_isRunning = false;
    m_direction = MotorDirection::Forward;

}

void Motor::runBackward(unsigned int speed)
{
    m_directionPin->write(GpioDigitalValue::GpioValue_High);
    if((speed - m_correction) >= m_minSpeed)
    {
        m_speedPin->write(speed - m_correction);
    }
    else if(speed == 0)
    {
        m_speedPin->write(0);
    }
    else
    {
       m_speedPin->write(m_minSpeed);
    }
    m_direction = MotorDirection::Backward;
    m_isRunning = true;
}

void Motor::runForwardSlowly()
{
   runForward(m_minSpeed);
}

void Motor::runBackwardSlowly()
{
   runBackward(m_minSpeed);
}

bool Motor::isRunning()
{
    return m_isRunning;
}

MotorDirection Motor::getDirection()
{
    return m_direction;
}

unsigned int Motor::getCorrection()
{
    return m_correction;
}

unsigned int Motor::getMinimalSpeed()
{
    return m_minSpeed;
}

