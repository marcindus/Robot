#pragma once

#include "IArduinoWrapper.hpp"

class ArduinoGpioWrapper : public IArduinoGpioWrapper
{
public:
    void pinMode(GpioNodemcuV2 p_pin, GpioMode p_mode) const override;
    void analogWrite(GpioNodemcuV2 p_pin, unsigned int p_signal) const override;
    void digitalWrite(GpioNodemcuV2 p_pin, GpioDigitalValue p_value) const override;
};

