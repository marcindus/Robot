#ifndef IMOTOR_HPP
#define IMOTOR_HPP

#include "Types.hpp"

class IMotor
{

public:
    virtual  ~IMotor() {};
    virtual void runForward(unsigned int speed) = 0;
    virtual void runForwardSlowly() = 0;
    virtual void runBackward(unsigned int speed) = 0;
    virtual void runBackwardSlowly() = 0;
    virtual void stop() = 0;
    virtual bool isRunning() = 0;
    virtual MotorDirection getDirection() = 0;
    virtual unsigned int getCorrection() = 0;
    virtual unsigned int getMinimalSpeed() = 0;
};

#endif // IMOTOR_HPP
