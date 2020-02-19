#include "Robot.hpp"
#include "ArduinoWrapper.hpp"

class RobotBuilder
{
public:
    RobotBuilder();
    RobotBuilder(IArduinoWrapper& nodemcuWrapper)
        : nodemcu(nodemcuWrapper),
          pin_A_speed(new GpioPort(nodemcu, GpioNodemcuV2::D1, GpioMode::Pwm)),
          pin_A_direction(new GpioPort(nodemcu, GpioNodemcuV2::D3, GpioMode::Output)),
          pin_B_speed(new GpioPort(nodemcu, GpioNodemcuV2::D2, GpioMode::Pwm)),
          pin_B_direction(new GpioPort(nodemcu, GpioNodemcuV2::D4, GpioMode::Output)),
          motor_A(motor_A_correction,
                  std::move(pin_A_speed),
                  std::move(pin_A_direction),
                  motor_A_minSpeed,
                  motor_A_maxSpeed),
          motor_B(motor_B_correction,
                  std::move(pin_B_speed),
                  std::move(pin_B_direction),
                  motor_B_minSpeed,
                  motor_B_maxSpeed),
          m_driver(motor_A, motor_B)
    {
    }

    std::unique_ptr<Robot> build() { return std::unique_ptr<Robot>(new Robot(m_driver)); }

private:
    IArduinoWrapper& nodemcu;
    std::unique_ptr<GpioPort> pin_A_speed;
    std::unique_ptr<GpioPort> pin_A_direction;
    std::unique_ptr<GpioPort> pin_B_speed;
    std::unique_ptr<GpioPort> pin_B_direction;
    int motor_A_minSpeed = 700;
    int motor_A_maxSpeed = 1024;
    int motor_A_correction = 0;
    int motor_B_minSpeed = 700;
    int motor_B_maxSpeed = 1024;
    int motor_B_correction = 0;
    Motor motor_A;
    Motor motor_B;
    Driver m_driver;
};
