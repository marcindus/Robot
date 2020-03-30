#pragma once
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
void  startWiFi();
void  startOTA();
void  startSPIFFS();
void  startWebSocket();
void  startMDNS();
void  startServer();
void  startUltrasonicSensor();
String formatBytes(size_t bytes);
String getContentType(String filename);
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght);

void handleNotFound();
bool handleFileRead(String path);
void handleFileUpload();

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);
WebSocketsServer webSocket(81);

File fsUploadFile;
const char *OTAName = "ESP8266";
const char *OTAPassword = "esp8266";
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
  //WiFi.softAP(ssid, pass);             // Start the access point
  //Serial.print("Access Point \""); Serial.print(ssid); Serial.println("\" started\r\n");

  wifiMulti.addAP(ssid, pass);   // add Wi-Fi networks you want to connect to
  wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2");
  wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3");

  Serial.println("Connecting");
  while (wifiMulti.run() != WL_CONNECTED && WiFi.softAPgetStationNum() < 1) {  // Wait for the Wi-Fi to connect
    delay(250);
    Serial.print('.');
  }
  Serial.println("\r\n");
  if(WiFi.softAPgetStationNum() == 0) {
    Serial.print("Connected to ");
    Serial.println(WiFi.SSID());
    Serial.print("IP address:\t");
    Serial.print(WiFi.localIP());
  } else {  Serial.print("Station connected to ESP8266 AP"); }
  Serial.println("\r\n");
}

void startOTA()
{
  ArduinoOTA.setHostname(OTAName);
  ArduinoOTA.setPassword(OTAPassword);

  ArduinoOTA.onStart([]() { Serial.println("Start"); });
  ArduinoOTA.onEnd([]() { Serial.println("\r\nEnd"); });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) { Serial.printf("Progress: %u%%\r", (progress / (total / 100))); });
  ArduinoOTA.onError([](ota_error_t error)
  {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  Serial.println("OTA ready\r\n");
}

void startSPIFFS() {
  SPIFFS.begin();
  Serial.println("SPIFFS started. Contents:");
  {
    Dir dir = SPIFFS.openDir("/");
    while (dir.next()) {
      String fileName = dir.fileName();
      size_t fileSize = dir.fileSize();
      Serial.printf("\tFS File: %s, size: %s\r\n", fileName.c_str(), formatBytes(fileSize).c_str());
    }
    Serial.printf("\n");
  }
}

void startWebSocket() {
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  Serial.println("WebSocket server started.");
}

void startMDNS() {
  MDNS.begin(mdnsName);
  Serial.print("mDNS responder started: http://");
  Serial.print(mdnsName);
  Serial.println(".local");
}

void startServer() {
  server.on("/edit.html",  HTTP_POST, []() {
    server.send(200, "text/plain", "");
  }, handleFileUpload);

  server.onNotFound(handleNotFound);          // if someone requests any other file or page, go to function 'handleNotFound'
                                              // and check if the file exists

  server.begin();                             // start the HTTP server
  Serial.println("HTTP server started.");
}


void handleNotFound(){ // if the requested file or page doesn't exist, return a 404 not found error
  if(!handleFileRead(server.uri())){          // check if the file exists in the flash memory (SPIFFS), if so, send it
    server.send(404, "text/plain", "404: File Not Found");
  }
}

bool handleFileRead(String path) { // send the right file to the client (if it exists)
  Serial.println("handleFileRead: " + path);
  if (path.endsWith("/")) path += "index.html";          // If a folder is requested, send the index file
  String contentType = getContentType(path);             // Get the MIME type
  String pathWithGz = path + ".gz";
  if (SPIFFS.exists(pathWithGz) || SPIFFS.exists(path)) { // If the file exists, either as a compressed archive, or normal
    if (SPIFFS.exists(pathWithGz))                         // If there's a compressed version available
      path += ".gz";                                         // Use the compressed verion
    File file = SPIFFS.open(path, "r");                    // Open the file
    size_t sent = server.streamFile(file, contentType);    // Send it to the client
    file.close();                                          // Close the file again
    Serial.println(String("\tSent file: ") + path);
    return true;
  }
  Serial.println(String("\tFile Not Found: ") + path);   // If the file doesn't exist, return false
  return false;
}

void handleFileUpload(){
  // upload a new file to the SPIFFS
  HTTPUpload& upload = server.upload();
  String path;
  if(upload.status == UPLOAD_FILE_START){
    path = upload.filename;
    if(!path.startsWith("/")) path = "/"+path;
    if(!path.endsWith(".gz")) {                          // The file server always prefers a compressed version of a file 
      String pathWithGz = path+".gz";                    // So if an uploaded file is not compressed, the existing compressed
      if(SPIFFS.exists(pathWithGz))                      // version of that file must be deleted (if it exists)
         SPIFFS.remove(pathWithGz);
    }
    Serial.print("handleFileUpload Name: "); Serial.println(path);
    fsUploadFile = SPIFFS.open(path, "w");            // Open the file for writing in SPIFFS (create if it doesn't exist)
    path = String();
  } else if(upload.status == UPLOAD_FILE_WRITE){
    if(fsUploadFile)
      fsUploadFile.write(upload.buf, upload.currentSize); // Write the received bytes to the file
  } else if(upload.status == UPLOAD_FILE_END){
    if(fsUploadFile) {                                    // If the file was successfully created
      fsUploadFile.close();                               // Close the file again
      Serial.print("handleFileUpload Size: "); Serial.println(upload.totalSize);
      server.sendHeader("Location","/success.html");      // Redirect the client to the success page
      server.send(303);
    } else {
      server.send(500, "text/plain", "500: couldn't create file");
    }
  }
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) { // When a WebSocket message is received
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
      }
      break;
    case WStype_TEXT:
    if(payload[0] == '#')
    {
        uint32_t correction  = (uint32_t) strtol((const char *) &payload[1], NULL, 16);
        // robot_ptr->setCorrection(correction);
        Serial.print("Correction ");
        Serial.print(correction);
    }
      else if (payload[0] == 'F') { 
          Serial.print("Forward"); 
          webSocket.sendTXT(num, "Forward");
          robot_ptr->goForward();
      }
      else if (payload[0] == 'L'){
          Serial.print("Left"); 
          webSocket.sendTXT(num, "Left");
          robot_ptr->turnLeft();
      }
      else if (payload[0] == 'R'){ 
          Serial.print("Right"); 
          webSocket.sendTXT(num, "Right");
          robot_ptr->turnRight();
      }
      else if (payload[0] == 'B'){ 
          Serial.print("Backward"); 
          webSocket.sendTXT(num, "Backward");
          robot_ptr->goBackward(); 
      }
      else if (payload[0] == 'S'){ 
          Serial.print("Stop"); 
          webSocket.sendTXT(num, "Stop");
          robot_ptr->stay(); 
      }

      else if (payload[0] == 'D'){  
          int dist =  getDistance();
          char arr[10] = "";
          itoa(dist, arr,10);
          Serial.print(" Distance ");
          webSocket.sendTXT(num, arr);
      }

    case  WStype_ERROR:
      Serial.printf("[%u] WStype_ERROR!\n", num);
      break;
    case  WStype_BIN:
      Serial.printf("[%u] WStype_BIN!\n", num);
      break;
    case  WStype_FRAGMENT_TEXT_START:
      Serial.printf("[%u] WStype_FRAGMENT_TEXT_START!\n", num);
      break;
    case  WStype_FRAGMENT_BIN_START:
      Serial.printf("[%u] WStype_FRAGMENT_BIN_START!\n", num);
      break;
    case  WStype_FRAGMENT:
      Serial.printf("[%u] WStype_FRAGMENT!\n", num);
      break;
    case  WStype_FRAGMENT_FIN:
      Serial.printf("[%u] WStype_FRAGMENT_FIN!\n", num);
      break;
    case  WStype_PING:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case  WStype_PONG:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
  }
}

String formatBytes(size_t bytes) {
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

String getContentType(String filename) { // determine the filetype of a given filename, based on the extension
  if (filename.endsWith(".html")) return "text/html";
  else if (filename.endsWith(".css")) return "text/css";
  else if (filename.endsWith(".js")) return "application/javascript";
  else if (filename.endsWith(".ico")) return "image/x-icon";
  else if (filename.endsWith(".gz")) return "application/x-gzip";
  return "text/plain";
}


