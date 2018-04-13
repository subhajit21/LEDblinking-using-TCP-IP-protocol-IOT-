#include<SPI.h>
#include<ESP8266WiFi.h>

int led=D4;
char ssid[]="#subha";
char pass[]="5011truth";

IPAddress server(192,168,43,250);
WiFiClient client;

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid,pass);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
   Serial.println(".");
      
  }
  Serial.println("WiFi connected");
  pinMode(led,OUTPUT);
}

void loop(){
  client.connect(server,80);
  digitalWrite(led,LOW);
  Serial.print("hello server");
  String answer=client.readStringUntil('r');
  Serial.print(answer);
  client.flush();
  digitalWrite(led,HIGH);
  delay(1000);
}

