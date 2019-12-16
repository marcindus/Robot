#include "Robot.hpp"
#include 

class RobotBuilder
{
public:
    RobotBuilder& set_()
    {
        return *this;
    }

    Robot build()
    {
        return Robot();
    }

private:
    ///std::unique_ptr<IMotor> m_motor;
};
