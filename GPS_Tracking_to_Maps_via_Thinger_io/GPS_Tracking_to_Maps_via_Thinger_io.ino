#include "TinyGPS++.h"
#include "SoftwareSerial.h"
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingerESP8266.h>

#define rx 5
#define tx 4
#define username "goobiez"
#define id_device "gps"
#define id_credential "mygpsku"
#define ssid "My ASUS_1005"
#define pswd "56782222"

ThingerESP8266 thing(username, id_device, id_credential);
SoftwareSerial ss  (rx, tx);
TinyGPSPlus gps;
double latitude, longitude;

void setup() {
  Serial.begin(9600);
  ss.begin(9600);

  thing.add_wifi(ssid, pswd);

  thing["mygps"] >> [](pson & data) {
    data["latitude"] = latitude;
    data["longitude"] = longitude;
  };

}

void loop() {
  thing.handle();
  while (ss.available() > 0) {
    gps.encode(ss.read());
  }

  if (gps.location.isValid()) {
    latitude = gps.location.lat();
    longitude = gps.location.lng();
    String link = "www.google.com/maps/place" + String(latitude)+ "," +
    String(longitude);
    Serial.println(link);
    delay(2000);
  }
}
