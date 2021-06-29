#pragma once

#include <gmock/gmock.h>
#include "IArduinoWrapper.hpp"

class ArduinoWrapperMock : public IArduinoGpioWrapper
{
public:
    MOCK_CONST_METHOD2(pinMode, void(GpioNodemcuV2, GpioMode));
    MOCK_CONST_METHOD2(analogWrite, void(GpioNodemcuV2, unsigned int));
    MOCK_CONST_METHOD2(digitalWrite, void(GpioNodemcuV2, GpioDigitalValue));
};
