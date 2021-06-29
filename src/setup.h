#pragma once

/*
 *   Most of this code is copied from:  https://tttapa.github.io/
 *   A Beginner's Guide to the ESP8266
 *   Pieter P, 08-03-2017
 *    Examples : https://github.com/tttapa/ESP8266/tree/master/Examples
 */

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266mDNS.h>
#include <WebSocketsServer.h>
#include <string>

#include "ArduinoWrapper.hpp"
#include "RobotBuilder.hpp"
#include "ultrasonic.h"

void setup_robot();
void startWiFi();
void startWebSocket();
void startMDNS();
void webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t lenght);

void handleFileUpload();

ESP8266WiFiMulti wifiMulti;
WebSocketsServer webSocket(81);
const char* mdnsName = "esp8266";
ArduinoGpioWrapper nodemcuWrapper;
RobotBuilder builder(nodemcuWrapper);
std::unique_ptr<Robot> robot_ptr = nullptr;

void startWiFi()
{
    wifiMulti.addAP(ssid, pass);

    Serial.println("Connecting");
    while (wifiMulti.run() != WL_CONNECTED && WiFi.softAPgetStationNum() < 1)
    {
        delay(250);
        Serial.print('.');
    }
    Serial.println("\r\n");
    if (WiFi.softAPgetStationNum() == 0)
    {
        Serial.print("Connected to ");
        Serial.println(WiFi.SSID());
        Serial.print("IP address:\t");
        Serial.print(WiFi.localIP());
    }
    else
    {
        Serial.print("Station connected to ESP8266 AP");
    }
    Serial.println("\r\n");
}

void startWebSocket()
{
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);
    Serial.println("WebSocket server started.");
}

void startMDNS()
{
    if (!MDNS.begin(mdnsName))
    {
        Serial.println("Error setting up MDNS responder!");
    }
    else
    {
        Serial.println("mDNS responder started");
        Serial.print("mDNS responder started: http://");
        Serial.print(mdnsName);
        Serial.println(".local");
    }
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t lenght)
{
    String robot_answer;
    robot_answer.reserve(16); //!!!!! magic number
    String received;
    received.reserve(lenght);
    received = reinterpret_cast<char*>(payload);

    switch (type)
    {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            break;

        case WStype_CONNECTED: 
        {
            IPAddress ip = webSocket.remoteIP(num);
            Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
        }
        break;

        case WStype_TEXT: 
        {
            Serial.println("Received :" + received);
            robot_answer = robot_ptr->handleMessage(received);
            Serial.println("Sending robot answer: " + robot_answer);
            webSocket.sendTXT(num, robot_answer);
            robot_answer = "";
            received = "";
            break;
        }
        case WStype_ERROR:
            Serial.printf("[%u] WStype_ERROR! \n", num);
            webSocket.sendTXT(num, "WStype_ERROR!");
            break;
        case WStype_BIN:
            Serial.printf("[%u] WStype_BIN!\n", num);
            break;
        case WStype_FRAGMENT_TEXT_START:
            Serial.printf("[%u] WStype_FRAGMENT_TEXT_START!\n", num);
            break;
        case WStype_FRAGMENT_BIN_START:
            Serial.printf("[%u] WStype_FRAGMENT_BIN_START!\n", num);
            break;
        case WStype_FRAGMENT:
            Serial.printf("[%u] WStype_FRAGMENT!\n", num);
            break;
        case WStype_FRAGMENT_FIN:
            Serial.printf("[%u] WStype_FRAGMENT_FIN!\n", num);
            break;
        case WStype_PING:
            Serial.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_PONG:
            Serial.printf("[%u] Disconnected!\n", num);
            break;
    }
}
