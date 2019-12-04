#include "Motor.hpp"

Motor::Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin) :
    m_speedPin(std::move(p_speedPin)),
    m_directionPin(std::move(p_directionPin))
{

}

Motor::Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin, unsigned int correction) : Motor(std::move(p_speedPin), 
        std::move(p_directionPin), m_correction(correction)
{
}

void  Motor::RunForward()
{
}
void Motor::RunForward(unsigned int speed)
{
}

void Motor::Stop()
{
}

void Motor::RunBackward()
{
}

void Motor::RunBackward(unsigned int speed)
{
}

bool Motor::isRunning()
{
}

MotorDirection Motor::getDirection()
{
}

unsigned int Motor::getCorrection()
{
}

