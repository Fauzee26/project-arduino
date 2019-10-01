#include "TinyGPS++.h"
#include "SoftwareSerial.h"

#define rx 5
#define tx 4

SoftwareSerial gpserial(rx, tx);
TinyGPSPlus gps;
double latitude, longitude;

void setup() {
  Serial.begin(9600);
  gpserial.begin(9600);
}

void loop() {
  while (gpserial.available() > 0) {
    //Serial.println(gpserial.read());
    gps.encode(gpserial.read());
  }

  if (gps.location.isValid()) {
    latitude = gps.location.lat();
    longitude = gps.location.lng();
    String link = "www.google.com/maps/place" + String(latitude) + "," +
    String(longitude);
    Serial.println(link);
    delay(2000);
  }

}
