#pragma once

#include "Types.hpp"

class IArduinoGpioWrapper
{
public:
    virtual ~IArduinoGpioWrapper(){};
    virtual void pinMode(GpioNodemcuV2 p_pin, GpioMode p_mode) const = 0;
    virtual void analogWrite(GpioNodemcuV2 p_pin, unsigned int p_signal) const = 0;
    virtual void digitalWrite(GpioNodemcuV2 p_pin, GpioDigitalValue p_value) const = 0;
};


class IArduinoStringWrapper
{
public:
    virtual ~IArduinoStringWrapper(){};
    virtual void reserve(size_t size) const = 0;
};


