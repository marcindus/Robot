#include "GpioPort.hpp"
#include "GpioException.hpp"
#include <iostream>

GpioPort::GpioPort(IArduinoWrapper& p_arduinoWrapper, GpioNodemcuV2 p_pin, GpioMode p_mode) :
    m_arduinoWrapper(p_arduinoWrapper),
    m_gpioPin(p_pin),
    m_gpioMode(p_mode)
{
    m_arduinoWrapper._pinMode(p_pin, p_mode);
}


GpioPort::~GpioPort()
{
    m_arduinoWrapper._pinMode(m_gpioPin, GpioMode::GpioMode_Input);
}


void GpioPort::write(GpioDigitalValue p_value) const
{
    if(m_gpioMode != GpioMode::GpioMode_Output)
    {
        throw GpioException("Trying to write to input port type", m_gpioPin, m_gpioMode);
    }
    m_arduinoWrapper._digitalWrite(m_gpioPin, p_value);

}

void GpioPort::write(unsigned int p_signal) const
{
    std::cout << "signal : " << p_signal << std::endl;
    if(m_gpioMode != GpioMode::GpioMode_Pwm)
    {
        throw GpioException("Port is not PWM", m_gpioPin, m_gpioMode);
    }
    m_arduinoWrapper._analogWrite(m_gpioPin, p_signal);

}

GpioNodemcuV2  GpioPort::getGpioPort() const
{
    return m_gpioPin;
}

GpioMode  GpioPort::getMode() const
{
    return m_gpioMode;
}

