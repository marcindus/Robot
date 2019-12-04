#ifndef IMOTOR_HPP
#define IMOTOR_HPP

3include "Types.hpp"

class IMotor 
{
    public:
    virtual  ~IMotor {}
    virtual void RunForward() = 0;
    virtual void RunForward(Speed) = 0;
    virtual void Stop() = 0;
    virtual void RunBackward() = 0;
    virtual bool isRunning() = 0;
    virtual MotorDirection getDirection() = 0;
    unsigned int getCorrection() = 0;
}

#endif // IMOTOR_HPP
