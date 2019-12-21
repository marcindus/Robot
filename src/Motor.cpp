#include "Motor.hpp"

Motor::Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin)
    : m_speedPin(std::move(p_speedPin)), m_directionPin(std::move(p_directionPin))
{
}

Motor::Motor(std::unique_ptr<IGpioPort> p_speedPin,
             std::unique_ptr<IGpioPort> p_directionPin,
             int p_correction,
             int p_minSpeed,
             int p_maxSpeed)
    : m_speedPin(std::move(p_speedPin)),
      m_directionPin(std::move(p_directionPin)),
      m_correction(p_correction),
      m_minSpeed(p_minSpeed),
      m_maxSpeed(p_maxSpeed)
{
}
void Motor::setSpeed(int speed)
{
    if (((speed - m_correction) > m_minSpeed) && speed <= m_maxSpeed)
    {
        m_speedPin->write(speed - m_correction);
    }
    else if (speed == 0)
    {
        m_speedPin->write(0);
    }
    else if (speed >= m_maxSpeed)
    {
        m_speedPin->write(m_maxSpeed);
    }
    else
    {
        m_speedPin->write(m_minSpeed);
    }
}

void Motor::runForward(int speed)
{
    setSpeed(speed);
    m_directionPin->write(GpioDigitalValue::GpioValue_Low);
    m_direction = MotorDirection::Forward;
    m_isRunning = true;
}

void Motor::stop()
{
    m_speedPin->write(0);
    m_isRunning = false;
    m_direction = MotorDirection::Forward;
}

void Motor::runBackward(int speed)
{
    m_directionPin->write(GpioDigitalValue::GpioValue_High);
    setSpeed(speed);
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
