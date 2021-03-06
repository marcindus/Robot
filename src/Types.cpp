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
    os << "GpioMode::";
    switch (value)
    {
        case GpioMode::Input:
            return os << "Input";
        case GpioMode::Output:
            return os << "Output";
        case GpioMode::Pwm:
            return os << "Pwm";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, GpioDigitalValue value)
{
    os << "GpioDigitalValue";
    switch (value)
    {
        case GpioDigitalValue::GpioValue_Low:
            return os << "GpioValue_Low";
        case GpioDigitalValue::GpioValue_High:
            return os << "GpioValue_High";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, GpioPin value)
{
    return os << "GpioPin:" << value;
}

std::ostream& operator<<(std::ostream& os, GpioNodemcuV2 value)
{
    os << "GpioNodemcuV2::";
    switch (value)
    {
        case GpioNodemcuV2::D0:
            return os << "D0";
        case GpioNodemcuV2::D1:
            return os << "D1";
        case GpioNodemcuV2::D2:
            return os << "D2";
        case GpioNodemcuV2::D3:
            return os << "D3";
        case GpioNodemcuV2::D4:
            return os << "D4";
        case GpioNodemcuV2::D5:
            return os << "D5";
        case GpioNodemcuV2::D6:
            return os << "D6";
        case GpioNodemcuV2::D7:
            return os << "D7";
        case GpioNodemcuV2::D8:
            return os << "D8";
        case GpioNodemcuV2::D9:
            return os << "D9";
        case GpioNodemcuV2::D10:
            return os << "D10";
    }
    return os;
}
