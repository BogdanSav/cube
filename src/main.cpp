#include<Arduino.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
//asdasdas
#ifndef STASSID
#define STASSID "Lab_101"
#define STAPSK  "LaB_1010"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);
void light()
{
  
  String content = "<html><body><form  method='POST'>";
  content +="<button name='up' value='UP'>Up</button>";
  content +="<button name='down' value='DOWN'>Down</button>";
  content +="<button name='right' value='RIGHT'>Right</button>"; 
  content +="<button name='left' value='LEFT'>Left</button>";
   content +="<button name='stop' value='STOP'>Stop</button></form> </body></html>"; 
  server.send(200,"text/html",content);
  if(server.hasArg("up"))
  {
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(0,HIGH);
    digitalWrite(2,LOW);
    

  }
  if(server.hasArg("down"))
  {
     digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(0,LOW);
    digitalWrite(2,HIGH);
  }
  if(server.hasArg("right"))
  {
     digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
     digitalWrite(0,LOW);
    digitalWrite(2,LOW);
  }
  if(server.hasArg("left"))
  {
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(0,HIGH);
    digitalWrite(2,LOW);
  }
   if(server.hasArg("stop"))
  {
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(0,LOW);
    digitalWrite(2,LOW);
    

  }
}

void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(12,OUTPUT);
  analogWrite(14,127);
  analogWrite(12,127);



  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/",light);
 
 


  //here the list of headers to be recorded

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
}