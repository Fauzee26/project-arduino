#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <ESP8266WiFi.h>

#define suhu 5
#define BLYNK_PRINT Serial

DHT sh(5, DHT11);
SimpleTimer timer;

char auth[] = "On-Y0C-OFSStgd_IzwF-6neVzjIpZYhr";
char ssid[] = "My ASUS_1005";
char pswd[] = "56784222";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pswd);
  sh.begin();
  timer.setInterval(1000, senddata); 
}

void senddata() {
  float temp = sh.readTemperature();
  float hum  = sh.readHumidity();
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);
}

void loop() {
  Blynk.run();
  timer.run();
}
