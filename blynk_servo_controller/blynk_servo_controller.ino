#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

#define BLYNK_PRINT Serial

Servo servo;

char auth[] = "kD-_3fHHFLOwiCA3GCvegMaUCsAe7KP0"; // token yang dikirim ke email
char ssid[] = "My ASUS_1005"; // wifi
char pwsd[] = "56784222"; // pass wifi

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pwsd);
  servo.attach(2); // GPIO2
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}

BLYNK_WRITE(V3) {
  servo.write(param.asInt());
}
