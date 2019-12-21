#pragma once

#include "Types.hpp"

class IDriver
{
public:
    virtual ~IDriver(){};
    virtual void forward(unsigned int speed) = 0;
    virtual void turnLeft() = 0;
    virtual void backward(unsigned int speed) = 0;
    virtual void stay() = 0;
    virtual void turnRight() = 0;
};
