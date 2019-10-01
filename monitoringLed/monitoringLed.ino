#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial

char auth[] = "oIkuXvmMqwSoUQUgIPR3epomFzjw9KM5";
char ssid[] = "My ASUS_1005";
char pswd[] = "56784222";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pswd);

}

void loop() {
  Blynk.run();

}

/*
 * Kaki LED Panjang to GPIO 5
 * Kaki LED Pendek to GND/G
 */
