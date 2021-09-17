#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
 #include <string.h> 
 
const char* ssid="Wancom 2nd Floor";
const char* pass="M!cr0s0fT";
const char* brokerUser = "bahrozjaved6@gmail.com";
const char* brokerPass = "4bcd5aa6";
const char* broker = "mqtt.dioty.co";
const char* Topic1 ="/bahrozjaved6@gmail.com/relay1";
const char* Topic2 ="/bahrozjaved6@gmail.com/relay2";
const char* Topic3 ="/bahrozjaved6@gmail.com/relay3";
const char* Topic4 ="/bahrozjaved6@gmail.com/relay4";
const char* Topic5 ="/bahrozjaved6@gmail.com/relay5";
const char* Topic6 ="/bahrozjaved6@gmail.com/relay6";
 
#define Relay1 5 //D1
#define Relay2 4 //D2
#define Relay3 14 //D5
#define Relay4 12 //D6
#define Relay5 13 //D7
#define Relay6 15 //D8

WiFiClient espClient;
PubSubClient client(espClient);
 
void setupWifi(){
  delay(100);
  Serial.print("\nConnecting to");
  Serial.println(ssid);
 
  WiFi.begin(ssid, pass);
 
  while(WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print("-");
  }
 
  Serial.print("\nConnected to ");
  Serial.println(ssid);
}
 
void reconnect(){
  while(!client.connected()){
    Serial.print("\nConncting to ");
    Serial.println(broker);
    if(client.connect("esp82866", brokerUser, brokerPass)){
      Serial.print("\nConnected to ");
      Serial.println(broker);
      client.subscribe(Topic1);
      client.subscribe(Topic2);      
      client.subscribe(Topic3);      
      client.subscribe(Topic4);
      client.subscribe(Topic5);
      client.subscribe(Topic6);
    } else {
      Serial.println("\n Trying to reconnect");
      delay(5000);
    }
  }
}

 void callback(char* topic, byte* payload, unsigned int length) {

  if(strcmp(topic, Topic1) == 0)
   {
        //turn the light on if the payload is '1' and publish to the MQTT server a confirmation message
        if (payload[0] == '1')
        {
          digitalWrite(Relay1,LOW);
      Serial.println("light 1 ON");

            }

        //turn the light off if the payload is '0' and publish to the MQTT server a confirmation message
        else if (payload[0] == '0')
        {
   digitalWrite(Relay1,HIGH);
      Serial.println("light 1 Off");

        }
   }
   else if((strcmp(topic, Topic2) == 0))
   {
        //turn the light on if the payload is '1' and publish to the MQTT server a confirmation message
        if (payload[0] == '1')
        {
          digitalWrite(Relay2,LOW);
      Serial.println("light 2 ON");

        }

        //turn the light off if the payload is '0' and publish to the MQTT server a confirmation message
        else if (payload[0] == '0')
        {
            digitalWrite(Relay2,HIGH);
      Serial.println("light 2 Off");

        }
   }
   else if((strcmp(topic, Topic3) == 0))
   {
        //turn the light on if the payload is '1' and publish to the MQTT server a confirmation message
        if (payload[0] == '1')
        {
          digitalWrite(Relay3,LOW);
      Serial.println("light 3 ON");

        }

        //turn the light off if the payload is '0' and publish to the MQTT server a confirmation message
        else if (payload[0] == '0')
        {
            digitalWrite(Relay3,HIGH);
      Serial.println("light 3 Off");

        }
   }
   else if((strcmp(topic, Topic4) == 0))
   {
        //turn the light on if the payload is '1' and publish to the MQTT server a confirmation message
        if (payload[0] == '1')
        {
          digitalWrite(Relay4,LOW);
      Serial.println("light 4 ON");

        }

        //turn the light off if the payload is '0' and publish to the MQTT server a confirmation message
        else if (payload[0] == '0')
        {
            digitalWrite(Relay4,HIGH);
      Serial.println("light 4 Off");

        }
   }
   else if((strcmp(topic, Topic5) == 0))
   {
        //turn the light on if the payload is '1' and publish to the MQTT server a confirmation message
        if (payload[0] == '1')
        {
          digitalWrite(Relay5,LOW);
      Serial.println("light 5 ON");

        }

        //turn the light off if the payload is '0' and publish to the MQTT server a confirmation message
        else if (payload[0] == '0')
        {
            digitalWrite(Relay5,HIGH);
      Serial.println("light 5 Off");

        }
   }
 else if((strcmp(topic, Topic6) == 0))
   {
        //turn the light on if the payload is '1' and publish to the MQTT server a confirmation message
        if (payload[0] == '1')
        {
          digitalWrite(Relay6,LOW);
      Serial.println("light 6 ON");

        }

        //turn the light off if the payload is '0' and publish to the MQTT server a confirmation message
        else if (payload[0] == '0')
        {
            digitalWrite(Relay6,HIGH);
      Serial.println("light 6 Off");

        }
   }

}

 
void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  pinMode(Relay3,OUTPUT);
  pinMode(Relay4,OUTPUT);
  pinMode(Relay5,OUTPUT);
  pinMode(Relay6,OUTPUT);

  digitalWrite(Relay1,HIGH);
  digitalWrite(Relay2,HIGH);
  digitalWrite(Relay3,HIGH);
  digitalWrite(Relay4,HIGH);
  digitalWrite(Relay5,HIGH);
  digitalWrite(Relay6,HIGH);

    setupWifi();
    client.setServer(broker, 1883);
    client.setCallback(callback);
}
 
void loop() {
    // put your main code here, to run repeatedly:
    if (!client.connected()){
      reconnect();
    }
  client.loop();
 
 
}
