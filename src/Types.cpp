#include "Types.hpp"
#include <ostream>

std::ostream& operator<<(std::ostream& os, MotorDirection value)
{
    switch (value)
    {
        case MotorDirection::Forward:
            return os << "Forward";
        case MotorDirection::Backward:
            return os << "Backward";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, GpioMode value)
{
    os << "Mode:";
    switch (value)
    {
        case GpioMode::GpioMode_Input:
            return os << "Input";
        case GpioMode::GpioMode_Output:
            return os << "Output";
        case GpioMode::GpioMode_Pwm:
            return os << "Pwm";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, GpioDigitalValue value)
{
    switch (value)
    {
        case GpioDigitalValue::GpioValue_Low:
            return os << "Low";
        case GpioDigitalValue::GpioValue_High:
            return os << "High";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, GpioPin value)
{
    return os << "Pin:" << value;
}

std::ostream& operator<<(std::ostream& os, GpioNodemcuV2 value)
{
    os << "Pin:";
    switch (value)
    {
        case GpioNodemcuV2::GpioNodemcuV2_D0:
            return os << "D0";
        case GpioNodemcuV2::GpioNodemcuV2_D1:
            return os << "D1";
        case GpioNodemcuV2::GpioNodemcuV2_D2:
            return os << "D2";
        case GpioNodemcuV2::GpioNodemcuV2_D3:
            return os << "D3";
        case GpioNodemcuV2::GpioNodemcuV2_D4:
            return os << "D4";
        case GpioNodemcuV2::GpioNodemcuV2_D5:
            return os << "D5";
        case GpioNodemcuV2::GpioNodemcuV2_D6:
            return os << "D6";
        case GpioNodemcuV2::GpioNodemcuV2_D7:
            return os << "D7";
        case GpioNodemcuV2::GpioNodemcuV2_D8:
            return os << "D8";
        case GpioNodemcuV2::GpioNodemcuV2_D9:
            return os << "D9";
        case GpioNodemcuV2::GpioNodemcuV2_D10:
            return os << "D10";
    }
    return os;
}
