#pragma once

#include "IMotor.hpp"
#include "GpioPort.hpp"
#include <memory>

class Motor : public IMotor
{
public:
    Motor(std::unique_ptr<IGpioPort> p_speedPin, std::unique_ptr<IGpioPort> p_directionPin);
    Motor(std::unique_ptr<IGpioPort> p_speedPin,
          std::unique_ptr<IGpioPort> p_directionPin,
          int correction,
          int m_minSpeed,
          int m_maxSpeed);

    void runForward(int speed) override;
    void runForwardSlowly() override;
    void stop() override;
    void runBackward(int speed) override;
    void runBackwardSlowly() override;
    bool isRunning() override;
    MotorDirection getDirection() override;
    unsigned int getCorrection() override;
    unsigned int getMinimalSpeed() override;

private:
    std::unique_ptr<IGpioPort> m_speedPin;
    std::unique_ptr<IGpioPort> m_directionPin;
    bool m_isRunning = false;
    int m_correction = 0;
    MotorDirection m_direction = MotorDirection::Forward;
    int m_minSpeed = 600;
    int m_maxSpeed = 1024;
    void setSpeed(int speed);
};
