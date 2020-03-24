#include "../.cfg/wifi_credentials.h"
#include <ESP8266WiFi.h> 
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <FS.h>
#include <WebSocketsServer.h>

#include "setup.h"
#include "ultrasonic.h"

void setup()
{

    ultrasonic_init();
    Serial.begin(57600); 
   // setup_robot();
   // robot_ptr->stay();
}


void loop() 
{
    ultrasonic_measure();
    //webSocket.loop();  
    //server.handleClient(); 
    //ArduinoOTA.handle(); 
}


