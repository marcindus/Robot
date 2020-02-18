#pragma once

#include "Types.hpp"

class IMotor
{
public:
    virtual ~IMotor(){};
    virtual void runForward(int speed) = 0;
    virtual void runBackward(int speed) = 0;
    virtual void runForward() = 0;
    virtual void runBackward() = 0;
    virtual void stop() = 0;
    virtual bool isRunning() = 0;
    virtual MotorDirection getDirection() = 0;
    virtual unsigned int getCorrection() = 0;
    virtual void setCorrection(unsigned int) = 0;
    virtual unsigned int getMinimalSpeed() = 0;
};
