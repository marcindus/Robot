#pragma once

#include "IArduinoWrapper.hpp"

class ArduinoWrapper : public IArduinoWrapper
{
    public:
        void _pinMode(GpioNodemcuV2 p_pin, GpioMode p_mode) const override;
        void _analogWrite(GpioNodemcuV2 p_pin, unsigned int p_signal) const override;
        void _digitalWrite(GpioNodemcuV2 p_pin, GpioDigitalValue p_value) const override;
};

