//configuration pinout
const int PWMA=D1;    //Right side    D1 -> 5
const int PWMB=D2;    //Left side     D2 -> 4
const int DA=D3;      //Right reverse   D3 -> 0
const int DB=D4;      //Left reverse    D4 -> 2


//configuration speeds
const unsigned int maxSpeed = 1023;
const unsigned int minSpeed = 650;
const unsigned int noSpeed = 0;
const unsigned int right_A_Correction = 0; //V3, motorA range   0 100
const unsigned int left_B_Correction = 200;  //V4, motorB range   0 100


