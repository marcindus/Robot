#include "../.cfg/wifi_credentials.h"
#include <ESP8266WiFi.h> 
#include "ArduinoWrapper.hpp"
#include "RobotBuilder.hpp"

WiFiServer server(80);
ArduinoWrapper nodemcuWrapper;
RobotBuilder builder(nodemcuWrapper);
std::unique_ptr<Robot> robot_ptr = nullptr;

void  respond(WiFiClient* client ) 
{
  client->println("HTTP/1.1 200 OK");
  client->println("Content-Type: text/html");
  client->println(""); //  do not forget this one
  client->println("<!DOCTYPE HTML>");
  client->println("<html>");
  client->println("<br><br>");
  client->println("<a href=\"/RIGHT\"\"><button>RIGHT </button></a>");
  client->println("<a href=\"/LEFT\"\"><button>LEFT </button></a><br />");  
  client->println("<a href=\"/FORWARD\"\"><button>FORWARD </button></a><br />"); 
  client->println("<a href=\"/BACKWARD\"\"><button>BACKWARD </button></a><br />"); 
  client->println("<a href=\"/STOP\"\"><button>STOP </button></a><br />"); 
  client->println("</html>");
}

void setup()
{
    robot_ptr = builder.build();    
    Serial.begin(57600); 

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

  WiFiClient* ptr_client = &client;

  Serial.println("new client");
  while(!client.available()){ delay(1); }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();


  if (request.indexOf("/RIGHT") != -1)  { robot_ptr->turnRight(); }
  if (request.indexOf("/LEFT") != -1)  { robot_ptr->turnLeft(); }
  if (request.indexOf("/FORWARD") != -1)  { robot_ptr->goForward(800); }
  if (request.indexOf("/BACKWARD") != -1)  { robot_ptr->goBackward(800);  }
  if (request.indexOf("/STOP") != -1)  { robot_ptr->stay();  }

    respond(ptr_client);

    delay(1); Serial.println("Client disonnected"); Serial.println("");
}


