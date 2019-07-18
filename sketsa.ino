#include <string.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "NAMA WIFI ANDA";  
const char* password = "PASSWORD WIFI ANDA";  

WebServer server(80);
String temp3;

void setup() {
  Serial.begin(115200);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {  

server.handleClient();
  server.send(200, "text/plain", "200 OK");
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

void handle_OnConnect() {
  String plainText = "Firza";
  String pesan = "OK PESAN SAMPAI";
  server.send(200, "text/html", SendHTML(plainText,pesan)); 
}

String SendHTML(String plainText, String pesan){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Kriptografi</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: red;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>Kriptografi</h1>\n";
  
  ptr +="<p>Nama: ";
  ptr += plainText;
  ptr +="<p>Pesan: ";
  ptr += pesan;
  
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
