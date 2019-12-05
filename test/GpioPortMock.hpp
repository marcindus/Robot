#ifndef GPIOPORTMOCK_HPP
#define GPIOPORTMOCK_HPP 

#include <gmock/gmock.h>
#include "IGpioPort.hpp"

class GpioPortMock : public IGpioPort 
{
    public:
        MOCK_CONST_METHOD1(write , void(GpioDigitalValue));
        MOCK_CONST_METHOD1(write, void(unsigned));
        MOCK_CONST_METHOD0(getGpioPort, GpioNodemcuV2());
        MOCK_CONST_METHOD0(getMode, GpioMode());

};

#endif // GPIOPORTMOCK_HPP 
