#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "IMotor.hpp"
#include "GpioPort.hpp"
#include <memory>

class Motor : public IMotor
{
public:
    Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin);
    Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin, unsigned int correction);
    void RunForward()  override;
    void RunForward(unsigned int speed)  override;
    void Stop()  override;
    void RunBackward()  override;
    void RunBackward(unsigned int speed)  override;
    bool isRunning()  override;
    MotorDirection getDirection() override;
    unsigned int getCorrection() override;

private:
    std::unique_ptr<IGpioPort> m_speedPin;
    std::unique_ptr<IGpioPort> m_directionPin;
    bool isRunning = false;
    unsigned int m_correction = 0;

}

#endif // MOTOR_HPP
