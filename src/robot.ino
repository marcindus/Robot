#include "../.cfg/wifi_credentials.h"
#include <ESP8266WiFi.h> 
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <FS.h>
#include <WebSocketsServer.h>

#include "ArduinoWrapper.hpp"
#include "RobotBuilder.hpp"
#include "setup.h"

ArduinoWrapper nodemcuWrapper;
RobotBuilder builder(nodemcuWrapper);
std::unique_ptr<Robot> robot_ptr = nullptr;

void setup()
{
    robot_ptr = builder.build();    
    Serial.begin(57600); 
    delay(10);
    setup_network();
}


void loop() 
{
  webSocket.loop();                           // constantly check for websocket events
  server.handleClient();                      // run the server
  ArduinoOTA.handle();                        // listen for OTA events

/* 
robot_ptr->turnRight();
robot_ptr->turnLeft();
robot_ptr->goForward(800);
robot_ptr->goBackward(800);
robot_ptr->stay(); 
*/
}


