#pragma once
#include <iosfwd>

enum class MotorDirection
{
    Forward = 0,
    Backward = 1
};

std::ostream& operator << (std::ostream&, MotorDirection);

enum class GpioMode
{
    Input = 0,
    Output = 1,
    Pwm = 2
};

std::ostream& operator << (std::ostream&, GpioMode);

enum class GpioDigitalValue
{
    GpioValue_Low = 0,
    GpioValue_High = 1
};

std::ostream& operator << (std::ostream&, GpioDigitalValue);

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

std::ostream& operator << (std::ostream&, GpioPin);

enum class GpioNodemcuV2
{
    D0 = 16,
    D1 = 5,
    D2 = 4,
    D3 = 0,
    D4 = 2,
    D5 = 14,
    D6 = 12,
    D7 = 13,
    D8 = 15,
    D9 = 3,
    D10 = 1
};

std::ostream& operator << (std::ostream&, GpioNodemcuV2);

/*
const int PWMA=D1;    //Right side    D1 -> 5
const int PWMB=D2;    //Left side     D2 -> 4
const int DA=D3;      //Right reverse   D3 -> 0
const int DB=D4;      //Left reverse    D4 -> 2

enum class L298nSpeed
{
    L298nPwmA = D1,
    L298nPwmB = D2,
};

enum class L298nDirection
{
    L298nDirectionPortA = D3,
    L298nDirectionPortB = D4
};


*/

/*
const int PWMA=D1;    //Right side    D1 -> 5
const int PWMB=D2;    //Left side     D2 -> 4
const int DA=D3;      //Right reverse   D3 -> 0
const int DB=D4;      //Left reverse    D4 -> 2
*/

/*
enum class L298nSpeed
{
    L298nPwmA = D1,
    L298nPwmB = D2,
};

enum class L298nDirection
{
    L298nDirectionPortA = D3,
    L298nDirectionPortB = D4
};
*/
