#include  <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>

#define FIREBASE_HOST "home-automation-system-72cb4.firebaseio.com"                  // Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "AB2LYPzBBOd9yznVpm7TVdJdfUu2kTdTW2g577Vv"    // Your Firebase Database Secret goes here
#define WIFI_SSID "Wancom 2nd Floor"                                  // your WiFi SSID for which yout NodeMCU connects
#define WIFI_PASSWORD "M!cr0s0fT"
 
#define DHTPIN D2   
 
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
 
void setup() 
{
  Serial.begin(115200);
  dht.begin();                                                  //reads dht sensor data 
               
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); 
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  
}
 
void loop() 
{
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();  // Reading temperature as Celsius (the default)
 
  Serial.print("Humidity: ");  
  Serial.print(h);
  
  Serial.print("%  Temperature: ");  
  Serial.print(t);  
  Serial.println("°C ");
   
  Firebase.setFloat ("Temp",t);
  Firebase.setFloat ("Humidity",h);
  delay(3000);
}



