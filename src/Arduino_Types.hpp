#ifndef ARDUINO_TYPES_HPP
#define ARDUINO_TYPES_HPP


enum class GpioMode
{
    GpioMode_Input = 0,
    GpioMode_Output = 1,
    GpioMode_Pwm = 2
};

enum class GpioDigitalValue
{
    GpioValue_Low = 0,
    GpioValue_High = 1
};

enum class GpioPin
{
    GpioPin_1 = 1,
    GpioPin_2 = 2,
    GpioPin_3 = 3,
    GpioPin_4 = 4,
    GpioPin_5 = 5,
    GpioPin_6 = 6,
    GpioPin_7 = 7,
    GpioPin_8 = 8,
    GpioPin_9 = 9,
    GpioPin_10 = 10
};

#endif // ARDUINO_TYPES_HPP
