#pragma once

#include "Types.hpp"

class IArduinoWrapper
{
public:
    virtual ~IArduinoWrapper(){};
    virtual void pinMode(GpioNodemcuV2 p_pin, GpioMode p_mode) const = 0;
    virtual void analogWrite(GpioNodemcuV2 p_pin, unsigned int p_signal) const = 0;
    virtual void digitalWrite(GpioNodemcuV2 p_pin, GpioDigitalValue p_value) const = 0;
};
