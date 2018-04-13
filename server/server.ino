#include<SPI.h>//serial peripheral interface(SPI)
#include<ESP8266WiFi.h>

int led=D4;
char ssid[]="HTTPS";
char pass[]= "kuchbhiiee";
WiFiServer server(80);

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid,pass);

  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  
 Serial.print("connected");
 server.begin();
  Serial.print(WiFi.localIP());
  pinMode(led,OUTPUT);
  
}
void loop()
{
  WiFiClient client=server.available();

  if(client){
    if(client.available()){

      digitalWrite(led,LOW);
      String request = client.readStringUntil('\r');
      Serial.println("From client");
      Serial.print(request);
      client.flush();
      Serial.print("hi client! i am listening.\r");
      digitalWrite(led,HIGH);
    }
    client.stop();
  }
  
}


