#include "Motor.hpp"

Motor::Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin) :
        m_speedPin(std::move(p_speedPin)),
        m_directionPin(std::move(p_directionPin))
{
}
/*
Motor::Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin, unsigned int correction) :
                Motor(std::move(p_speedPin), std::move(p_directionPin)), m_correction(correction)
{
}
*/

Motor::Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin, unsigned int correction) :
        m_speedPin(std::move(p_speedPin)),
        m_directionPin(std::move(p_directionPin)),
        m_correction(correction)
{
}

void Motor::runForward(unsigned int speed)
{
}

void Motor::stop()
{
}

void Motor::runBackward()
{
}

void Motor::runBackward(unsigned int speed)
{
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

