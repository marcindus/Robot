#include "../.cfg/wifi_credentials.h"
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <FS.h>
#include <WebSocketsServer.h>

#include "setup.h"

void setup()
{
    Serial.begin(57600);
    robot_ptr = builder.build();
    startWiFi();
    startWebSocket();
    startMDNS();
    robot_ptr->stay();
}

void loop()
{
    webSocket.loop();
}


