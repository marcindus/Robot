
/*
const int PWMA=D1;    //Right side    D1 -> 5
const int PWMB=D2;    //Left side     D2 -> 4
const int DA=D3;      //Right reverse   D3 -> 0
const int DB=D4;      //Left reverse    D4 -> 2
*/

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

