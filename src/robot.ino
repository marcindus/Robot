#include "../.cfg/wifi_credentials.h"

#include <ESP8266WiFi.h> 
#include "move.h"


WiFiServer server(80);

void setup()
{ 
    Serial.begin(57600); 

    pinMode(PWMA, OUTPUT); 
    pinMode(PWMB, OUTPUT); 
    pinMode(DA, OUTPUT); 
    pinMode(DB, OUTPUT); 
    delay(10);

    Serial.println(); Serial.println(); Serial.print("Connecting to "); Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(""); Serial.println("WiFi connected");
    server.begin(); Serial.println("Server started");
    Serial.print("Use this URL to connect: ");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");

} 
 
 
void loop() {
  WiFiClient client = server.available();
  if (!client) { return; } 

  Serial.println("new client");
  while(!client.available()){ delay(1); }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  String value="";
  if (request.indexOf("/RIGHT") != -1)  
  { 
    right_turn();
    value = "RIGHT";
  }

  if (request.indexOf("/LEFT") != -1)  
  {
      left_turn();
      value ="LEFT";
  }

  if (request.indexOf("/FORWARD") != -1)  
  {
      forward();
      value ="FORWARD";
  }
  
  if (request.indexOf("/BACKWARD") != -1)  
  {
       backward();
       value ="BACKWARD";
  }
  
  if (request.indexOf("/STOP") != -1)  
  {
      stay();
      value ="STOP";
  }
  
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print("Your car is moving ");

//WHAT IS THAT?  ...... client.print(value); ...?
  if(value == "RIGHT") {
    client.print("RIGHT");
  } else if(value="LEFT"){
    client.print("LEFT");
  }
  else if(value=="FORWARD")
  {
    client.print("FORWARD");
  }
  else if(value=="BACKWARD")
  {
    client.print("BACKWARD");
  }
  else if(value=="STOP")
  {
    client.print("STOP");
  }
  
  client.println("<br><br>");
  client.println("<a href=\"/RIGHT\"\"><button>RIGHT </button></a>");
  client.println("<a href=\"/LEFT\"\"><button>LEFT </button></a><br />");  
  client.println("<a href=\"/FORWARD\"\"><button>FORWARD </button></a><br />"); 
  client.println("<a href=\"/BACKWARD\"\"><button>BACKWARD </button></a><br />"); 
  client.println("<a href=\"/STOP\"\"><button>STOP </button></a><br />"); 
  client.println("</html>");
 
  delay(1); Serial.println("Client disonnected"); Serial.println("");
}
 
 
