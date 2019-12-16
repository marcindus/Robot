#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "IMotor.hpp"
#include "GpioPort.hpp"
#include <memory>

class Motor : public IMotor
{
public:
    Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin);
    Motor(std::unique_ptr<IGpioPort> p_speedPin,
          std::unique_ptr<IGpioPort> p_directionPin,
          unsigned int correction,
          unsigned int m_minSpeed);

    void runForward(unsigned int speed)  override;
    void runForwardSlowly() override;
    void stop()  override;
    void runBackward(unsigned int speed)  override;
    void runBackwardSlowly()  override;
    bool isRunning()  override;
    MotorDirection getDirection() override;
    unsigned int getCorrection() override;
    unsigned int getMinimalSpeed() override;

private:
    std::unique_ptr<IGpioPort> m_speedPin;
    std::unique_ptr<IGpioPort> m_directionPin;
    bool m_isRunning = false;
    unsigned int m_correction = 0;
    MotorDirection m_direction = MotorDirection::Forward;
    unsigned int m_minSpeed = 600;

};

#endif // MOTOR_HPP
