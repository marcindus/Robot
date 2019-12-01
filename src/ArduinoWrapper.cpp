#include "ArduinoWrapper.hpp"
#include "Arduino.h"

void ArduinoWrapper::_pinMode(GpioNodemcuV2 p_pin, GpioMode p_mode) const 
{
    pinMode(static_cast<unsigned>(p_pin), static_cast<unsigned>(p_mode));
};

void ArduinoWrapper::_analogWrite(GpioNodemcuV2 p_pin, unsigned int p_signal) const
{
    analogWrite(static_cast<unsigned>(p_pin), p_signal);
};

void ArduinoWrapper::_digitalWrite(GpioNodemcuV2 p_pin, GpioDigitalValue p_value) const 
{
    digitalWrite(static_cast<unsigned>(p_pin),
                   static_cast<unsigned>(p_value));
};

