#include "hw_config.h"


void  forward() 
{
    analogWrite(PWMA, maxSpeed-right_A_Correction); 
    digitalWrite(DA, LOW); 
    analogWrite(PWMB, maxSpeed-left_B_Correction); 
    digitalWrite(DB, LOW); 
    Serial.println("Forward");
}

void backward_and_left()
{
     analogWrite(PWMA, noSpeed);  
     digitalWrite(DA, LOW);        
     analogWrite(PWMB, maxSpeed); 
     digitalWrite(DB, HIGH); 
     Serial.println("back left");
}
void left_turn() 
{
     analogWrite(PWMA, minSpeed); 
     digitalWrite(DA, HIGH); 
     analogWrite(PWMB, noSpeed); 
     digitalWrite(DB, LOW); 
}

void forward_and_left() 
{
     analogWrite(PWMA, noSpeed); 
     digitalWrite(DA, LOW); 
     analogWrite(PWMB, maxSpeed); 
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
void backward_and_right()
{
     analogWrite(PWMA, maxSpeed); 
     digitalWrite(DA, HIGH); 
     analogWrite(PWMB, noSpeed); 
     digitalWrite(DB, LOW); 
     Serial.println("Backward and Right");
}
void right_turn() 
{
     analogWrite(PWMA, noSpeed); 
     digitalWrite(DA, LOW); 
     analogWrite(PWMB, minSpeed); 
     digitalWrite(DB, HIGH); 
}

void forward_and_right()
{
     analogWrite(PWMA, maxSpeed); 
     digitalWrite(DA, LOW); 
     analogWrite(PWMB, noSpeed); 
     digitalWrite(DB, LOW);
}
/*
void move(int x, int y) 
{
    if(x==-1 && y==-1)     {    backward_and_left(); }
    else if(x==-1 && y==0) {    left_turn();         }
    else if(x==-1 && y==1) {    forward_and_left();  }
    else if(x==0 && y==-1) {    backward();          }
    else if(x==0 && y==0)  {    stay();              }
    else if(x==0 && y==1)  {    forward();           }
    else if(x==1 && y==-1) {    backward_and_left(); }
    else if(x==1 && y==0)  {    right_turn();        }
    else if(x==1 && y==1)  {    forward_and_right(); }
} 
*/


