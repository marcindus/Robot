#include "hw_config.h"

void  forward()
{
    analogWrite(PWMA, maxSpeed-right_A_Correction);
    digitalWrite(DA, LOW);
    analogWrite(PWMB, maxSpeed-left_B_Correction);
    digitalWrite(DB, LOW);
    Serial.println("Forward");
}

void left_turn()
{
     analogWrite(PWMA, minSpeed);
     digitalWrite(DA, HIGH);
     analogWrite(PWMB, noSpeed);
     digitalWrite(DB, LOW);
}

void backward()
{
     analogWrite(PWMA, maxSpeed-right_A_Correction);
     digitalWrite(DA, HIGH);
     analogWrite(PWMB, maxSpeed-left_B_Correction);
     digitalWrite(DB, HIGH);
}
void stay()
{
     analogWrite(PWMA, noSpeed);
     digitalWrite(PWMA, LOW);
     digitalWrite(PWMB, LOW);
     digitalWrite(DA, LOW);
     analogWrite(PWMB, noSpeed);
     digitalWrite(DB, LOW);
}
void right_turn()
{
     analogWrite(PWMA, noSpeed);
     digitalWrite(DA, LOW);
     analogWrite(PWMB, minSpeed);
     digitalWrite(DB, HIGH);
}
