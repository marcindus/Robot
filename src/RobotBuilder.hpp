#include "Robot.hpp"
#include "ArduinoWrapper.hpp"

class RobotBuilder
{
public:
    RobotBuilder(IArduinoWrapper& arduinoWrapper);
    RobotBuilder& set_sth()
    {
        return *this;
    }

    Robot build()
    {

        GpioPort motor_A_speed( GpioPort(IArduinoWrapper& p_arduinoWrapper,  GpioNodemcuV2 p_pin, GpioMode p_mode);


        return Robot();
    }

private:
    ///std::unique_ptr<IMotor> m_motor;

};
