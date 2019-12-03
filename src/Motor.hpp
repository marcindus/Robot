#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "IMotor.hpp"

class Motor : public IMotor
{
public:
    Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin);
    RunForward()  override;
    void RunForward(Speed)  override;
    void Stop()  override;
    void RunBackward()  override;
    bool isRunning()  override;
    MotorDirection getDirection() override;

}

#endif // MOTOR_HPP
