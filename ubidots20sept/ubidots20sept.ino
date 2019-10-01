#include "DHT.h"
#include "UbidotsMicroESP8266.h" 
#define DHTPIN 5 //pin sensor DHT
#define TOKEN "BBFF-nxH5NVYYsjVEAeMWmHJuW8K9Rhc9Fb" 
#define ssid "SEKOLAH IDN"
//#define psswd "xxxxxxxxxxxx"
DHT dht(DHTPIN,DHT11); Ubidots client(TOKEN); unsigned long last = 0;
void setup() { 
  Serial.begin(9600); dht.begin();
delay(20); 
//client.wifiConnection(ssid, psswd); client.wifiConnection(ssid,NULL);
}
void loop() {
if (millis() - last > 10000) {
float hum = dht.readHumidity();
float temp = dht.readTemperature();
last = millis(); 
client.add("kelembapan",hum); 
client.add("suhu",temp); 
client.sendAll(true);
} 
}
