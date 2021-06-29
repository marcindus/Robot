#include "ArduinoWrapper.hpp"
#include "Arduino.h"


void ArduinoGpioWrapper::pinMode(GpioNodemcuV2 p_pin, GpioMode p_mode) const
{
    Serial.print("Digital write pin:value ");
    Serial.print(static_cast<unsigned>(p_pin));
    Serial.print(static_cast<unsigned>(p_mode));
    ::pinMode(static_cast<unsigned>(p_pin), static_cast<unsigned>(p_mode));
    if(p_mode == GpioMode::Output)
    {
        ::digitalWrite(static_cast<unsigned>(p_pin), 0);
    }
    else if(p_mode == GpioMode::Pwm)
    {
        ::analogWrite(static_cast<unsigned>(p_pin), 0);
    }
};

void ArduinoGpioWrapper::analogWrite(GpioNodemcuV2 p_pin, unsigned int p_signal) const
{
    Serial.print("Analog write pin:value ");
    Serial.print(static_cast<unsigned>(p_pin));
    Serial.print(p_signal);
    ::analogWrite(static_cast<unsigned>(p_pin), p_signal);
};

void ArduinoGpioWrapper::digitalWrite(GpioNodemcuV2 p_pin, GpioDigitalValue p_value) const
{
    Serial.print("Digital write pin:value ");
    Serial.print(static_cast<unsigned>(p_pin));
    Serial.print(static_cast<unsigned>(p_value));

    ::digitalWrite(static_cast<unsigned>(p_pin), static_cast<unsigned>(p_value));
};

void ArduinoStringWrapper::reserve(size_t size) const
{
};
