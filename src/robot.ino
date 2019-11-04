#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
#include "../.cfg/wifi_credentials.h"
/*
static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;
*/

int PWMA=D1;    //Right side    D1 -> 5
int PWMB=D2;    //Left side     D2 -> 4
int DA=D3;      //Right reverse   D3 -> 0
int DB=D4;      //Left reverse    D4 -> 2

unsigned int maxSpeed = 1023;
unsigned int minSpeed = 650;
unsigned int noSpeed = 0;
unsigned int right_A_Correction; //V3, motorA range   0 100
unsigned int left_B_Correction;  //V4, motorB range   0 100

void setup(){ 
 // Debug console 
 Serial.begin(57600); 
 Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,13), 8080);
 pinMode(PWMA, OUTPUT); 
 pinMode(PWMB, OUTPUT); 
 pinMode(DA, OUTPUT); 
 pinMode(DB, OUTPUT); 
} 
void loop(){ 

Blynk.run(); 
  
} 

BLYNK_WRITE(V3) { right_A_Correction = param.asInt(); }
BLYNK_WRITE(V4) { left_B_Correction = param.asInt(); }


// Handling Joystick data 
BLYNK_WRITE(V1){ 
int x = param[0].asInt(); 
int y = param[1].asInt();  
Serial.println(left_B_Correction);
Serial.println(right_A_Correction);

if(x==-1 && y==-1){             //Backward and Left     
     analogWrite(PWMA, noSpeed); 
     digitalWrite(DA, LOW); 
     
     analogWrite(PWMB, maxSpeed); 
     digitalWrite(DB, HIGH); 
     Serial.println("back left");

}else if(x==-1 && y==0){        //Left Turn 
     analogWrite(PWMA, minSpeed); 
     digitalWrite(DA, HIGH); 
    
     analogWrite(PWMB, noSpeed); 
     digitalWrite(DB, LOW); 
      Serial.println("turn left");
      
}else if(x==-1 && y==1){        //Forward and Left     
     analogWrite(PWMA, noSpeed); 
     digitalWrite(DA, LOW); 
    
     analogWrite(PWMB, maxSpeed); 
     digitalWrite(DB, LOW); 
          Serial.println("Forward and Left");
          
}else if(x==0 && y==-1){        //Backward     
     analogWrite(PWMA, maxSpeed-right_A_Correction); 
     digitalWrite(DA, HIGH); 
     
     analogWrite(PWMB, maxSpeed-left_B_Correction); 
     digitalWrite(DB, HIGH);
     Serial.println("Backward");

}else if(x==0 && y==0){        //Stay 
     analogWrite(PWMA, noSpeed); 
     digitalWrite(PWMA, LOW); 
     digitalWrite(PWMB, LOW); 
     digitalWrite(DA, LOW); 
     
     analogWrite(PWMB, noSpeed); 
     digitalWrite(DB, LOW); 

}else if(x==0 && y==1){        //Forward 
     analogWrite(PWMA, maxSpeed-right_A_Correction); 
     digitalWrite(DA, LOW); 
    
     analogWrite(PWMB, maxSpeed-left_B_Correction); 
     digitalWrite(DB, LOW); 
      Serial.println("Forward");
}else if(x==1 && y==-1){        //Backward and Right     

     analogWrite(PWMA, maxSpeed); 
     digitalWrite(DA, HIGH); 
     
     analogWrite(PWMB, noSpeed); 
     digitalWrite(DB, LOW); 
      Serial.println("Backward and Right");
}else if(x==1 && y==0){        //Right turn 
     analogWrite(PWMA, noSpeed); 
     digitalWrite(DA, LOW); 
     
     analogWrite(PWMB, minSpeed); 
     digitalWrite(DB, HIGH); 
       Serial.println("Right turn ");
}else if(x==1 && y==1){        //Forward and Right 
     analogWrite(PWMA, maxSpeed); 
     digitalWrite(DA, LOW); 
     
     analogWrite(PWMB, noSpeed); 
     digitalWrite(DB, LOW);
       Serial.println("Forward and Right");
 } 
}
 
