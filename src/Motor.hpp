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
    void runForward() override;
    void stop() override;
    void runBackward(int speed) override;
    void runBackward() override;
    bool isRunning() override;
    MotorDirection getDirection() override;
    unsigned int getCorrection() override;
    void setCorrection(unsigned int) override;
    unsigned int getMinimalSpeed() override;
    int m_correction = 0;

private:
    std::unique_ptr<IGpioPort> m_speedPin;
    std::unique_ptr<IGpioPort> m_directionPin;
    bool m_isRunning = false;
    MotorDirection m_direction = MotorDirection::Forward;
    int m_minSpeed = 700;
    int m_maxSpeed = 1024;
    void setSpeed(int speed);
};
