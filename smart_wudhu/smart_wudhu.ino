#include <HCSR04.h>

#define trigger 5
#define echo 4
#define pinrelay 16

HCSR04 distance(trigger, echo);

void setup() {
  Serial.begin(115200);
  pinMode(pinrelay, OUTPUT);
}

void loop() {
  float sensor = distance.dist();

  if (sensor >= 5 && sensor <= 15) {
    digitalWrite(pinrelay, LOW);
    Serial.println("Air Mengalir");
  } else {
    digitalWrite(pinrelay, HIGH);
    Serial.println("Air Berhenti");
  }
  delay(200);
}
