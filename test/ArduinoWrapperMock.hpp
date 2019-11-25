#ifndef IARDUINOWRAPPERMOCK_HPP
#define IARDUINOWRAPPERMOCK_HPP

#include <gmock/gmock.h>
#include "IArduinoWrapper.hpp"


class ArduinoWrapperMock : public IArduinoWrapper 
{

    public:
        MOCK_CONST_METHOD2(pinMode, void(int, int));
        MOCK_CONST_METHOD2(analogWrite, void(int, int));
        MOCK_CONST_METHOD2(digitalWrite, void(int, int));
};

#endif // IARDUINOWRAPPERMOCK_HPP
