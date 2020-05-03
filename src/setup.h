#pragma once

/*
 *   Most of this code copied from:
 *   https://tttapa.github.io/
 *   A Beginner's Guide to the ESP8266
 *   Pieter P, 08-03-2017
 *    Examples : https://github.com/tttapa/ESP8266/tree/master/Examples
 */

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <FS.h>
#include <WebSocketsServer.h>
#include <stdlib.h>

#include "ArduinoWrapper.hpp"
#include "RobotBuilder.hpp"
#include "ultrasonic.h"

void setup_robot();
void startWiFi();
void startOTA();
void startSPIFFS();
void startWebSocket();
void startMDNS();
void startServer();
void startUltrasonicSensor();
String formatBytes(size_t bytes);
String getContentType(String filename);
void webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t lenght);

void handleNotFound();
bool handleFileRead(String path);
void handleFileUpload();

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);
WebSocketsServer webSocket(81);

File fsUploadFile;
const char* OTAName = "ESP8266";
const char* OTAPassword = "esp8266";
const char* mdnsName = "esp8266";

ArduinoWrapper nodemcuWrapper;
RobotBuilder builder(nodemcuWrapper);
std::unique_ptr<Robot> robot_ptr = nullptr;

void setup_robot()
{
    robot_ptr = builder.build();

    startWiFi();
    startOTA();
    startSPIFFS();
    startWebSocket();
    startMDNS();
    startServer();
}

void startWiFi()
{
    wifiMulti.addAP(ssid, pass); 
    wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2");
    wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3");

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

void startOTA()
{
    ArduinoOTA.setHostname(OTAName);
    ArduinoOTA.setPassword(OTAPassword);

    ArduinoOTA.onStart([]() { Serial.println("Start"); });
    ArduinoOTA.onEnd([]() { Serial.println("\r\nEnd"); });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR)
            Serial.println("Auth Failed");
        else if (error == OTA_BEGIN_ERROR)
            Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR)
            Serial.println("Connect Failed");
        else if (error == OTA_RECEIVE_ERROR)
            Serial.println("Receive Failed");
        else if (error == OTA_END_ERROR)
            Serial.println("End Failed");
    });
    ArduinoOTA.begin();
    Serial.println("OTA ready\r\n");
}

void startSPIFFS()
{
    SPIFFS.begin();
    Serial.println("SPIFFS started. Contents:");
    {
        Dir dir = SPIFFS.openDir("/");
        while (dir.next())
        {
            String fileName = dir.fileName();
            size_t fileSize = dir.fileSize();
            Serial.printf("\tFS File: %s, size: %s\r\n", fileName.c_str(), formatBytes(fileSize).c_str());
        }
        Serial.printf("\n");
    }
}

void startWebSocket()
{
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);
    Serial.println("WebSocket server started.");
}

void startMDNS()
{
    MDNS.begin(mdnsName);
    Serial.print("mDNS responder started: http://");
    Serial.print(mdnsName);
    Serial.println(".local");
}

void startServer()
{
    server.on("/edit.html", HTTP_POST, []() { server.send(200, "text/plain", ""); }, handleFileUpload);

    server.onNotFound(handleNotFound); 
                                       

    server.begin(); 
    Serial.println("HTTP server started.");
}

void handleNotFound()
{ 
    if (!handleFileRead(server.uri()))
    { 
        server.send(404, "text/plain", "404: File Not Found");
    }
}

bool handleFileRead(String path)
{ 
    Serial.println("handleFileRead: " + path);
    if (path.endsWith("/"))
        path += "index.html";                  
    String contentType = getContentType(path);
    String pathWithGz = path + ".gz";
    if (SPIFFS.exists(pathWithGz) || SPIFFS.exists(path))
    {                                      
        if (SPIFFS.exists(pathWithGz))    
            path += ".gz";               
        File file = SPIFFS.open(path, "r");
        // size_t sent = server.streamFile(file, contentType);    // Send it to the client
        server.streamFile(file, contentType);
        file.close();                        
        Serial.println(String("\tSent file: ") + path);
        return true;
    }
    Serial.println(String("\tFile Not Found: ") + path);
    return false;
}

void handleFileUpload()
{
    HTTPUpload& upload = server.upload();
    String path;
    if (upload.status == UPLOAD_FILE_START)
    {
        path = upload.filename;
        if (!path.startsWith("/"))
            path = "/" + path;
        if (!path.endsWith(".gz"))
        {                                     
            String pathWithGz = path + ".gz";
            if (SPIFFS.exists(pathWithGz))   
                SPIFFS.remove(pathWithGz);
        }
        Serial.print("handleFileUpload Name: ");
        Serial.println(path);
        fsUploadFile = SPIFFS.open(path, "w");
        path = String();
    }
    else if (upload.status == UPLOAD_FILE_WRITE)
    {
        if (fsUploadFile)
            fsUploadFile.write(upload.buf, upload.currentSize); 
    }
    else if (upload.status == UPLOAD_FILE_END)
    {
        if (fsUploadFile)
        {                         
            fsUploadFile.close(); 
            Serial.print("handleFileUpload Size: ");
            Serial.println(upload.totalSize);
            server.sendHeader("Location", "/success.html"); 
            server.send(303);
        }
        else
        {
            server.send(500, "text/plain", "500: couldn't create file");
        }
    }
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t lenght)
{ 

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
            webSocket.sendTXT(num, robot_ptr->handleMessage(payload));
        }
        case WStype_ERROR:
            Serial.printf("[%u] WStype_ERROR!\n", num);
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

String formatBytes(size_t bytes)
{
    if (bytes < 1024)
    {
        return String(bytes) + "B";
    }
    else if (bytes < (1024 * 1024))
    {
        return String(bytes / 1024.0) + "KB";
    }
    else if (bytes < (1024 * 1024 * 1024))
    {
        return String(bytes / 1024.0 / 1024.0) + "MB";
    }
    else
    {
        return String(bytes);
    }
}

String getContentType(String filename)
{ 
    if (filename.endsWith(".html"))
        return "text/html";
    else if (filename.endsWith(".css"))
        return "text/css";
    else if (filename.endsWith(".js"))
        return "application/javascript";
    else if (filename.endsWith(".ico"))
        return "image/x-icon";
    else if (filename.endsWith(".gz"))
        return "application/x-gzip";
    return "text/plain";
}
