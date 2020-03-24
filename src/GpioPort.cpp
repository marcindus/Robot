#include "GpioPort.hpp"
#include "GpioException.hpp"
#include "Utils.hpp"

#include "Arduino.h"

GpioPort::GpioPort(IArduinoWrapper& p_arduinoWrapper, GpioNodemcuV2 p_pin, GpioMode p_mode)
    : m_arduinoWrapper(p_arduinoWrapper), m_gpioPin(p_pin), m_gpioMode(p_mode)
{
//    LOG(" Pin:", p_pin,   " mode set: ",  p_mode);
    m_arduinoWrapper.pinMode(p_pin, p_mode);

}

GpioPort::~GpioPort()
{
//    LOG << " Pin:  " << m_gpioPin   << "  mode set: " <<  GpioMode::Input  << std::endl;
    m_arduinoWrapper.pinMode(m_gpioPin, GpioMode::Input);
}

void GpioPort::write(GpioDigitalValue p_value) const
{
    if (m_gpioMode != GpioMode::Output)
    {
        throw GpioException("Trying to write to input port type", m_gpioPin, m_gpioMode);
    }

//    LOG << " Pin:  " << m_gpioPin   << " digital write: " << p_value   << std::endl;
    m_arduinoWrapper.digitalWrite(m_gpioPin, p_value);
}

void GpioPort::write(unsigned int p_signal) const
{
    if (m_gpioMode != GpioMode::Pwm)
    {
        throw GpioException("Port is not PWM", m_gpioPin, m_gpioMode);
    }

//    LOG << " Pin:  " << m_gpioPin   << " analog write: " << p_signal   << std::endl;
    m_arduinoWrapper.analogWrite(m_gpioPin, p_signal);
}

GpioNodemcuV2 GpioPort::getGpioPort() const
{
    return m_gpioPin;
}

GpioMode GpioPort::getMode() const
{
    return m_gpioMode;
}
