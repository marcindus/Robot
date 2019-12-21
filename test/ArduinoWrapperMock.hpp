#pragma once

#include <gmock/gmock.h>
#include "IArduinoWrapper.hpp"

class ArduinoWrapperMock : public IArduinoWrapper
{
public:
    MOCK_CONST_METHOD2(_pinMode, void(GpioNodemcuV2, GpioMode));
    MOCK_CONST_METHOD2(_analogWrite, void(GpioNodemcuV2, unsigned int));
    MOCK_CONST_METHOD2(_digitalWrite, void(GpioNodemcuV2, GpioDigitalValue));
};
