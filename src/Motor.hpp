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
    void runForward()  override;
    void runForward(unsigned int speed)  override;
    void stop()  override;
    void runBackward()  override;
    void runBackward(unsigned int speed)  override;
    bool isRunning()  override;
    MotorDirection getDirection() override;
    unsigned int getCorrection() override;

private:
    std::unique_ptr<IGpioPort> m_speedPin;
    std::unique_ptr<IGpioPort> m_directionPin;
    bool m_isRunning = false;
    unsigned int m_correction = 0;

};

#endif // MOTOR_HPP
