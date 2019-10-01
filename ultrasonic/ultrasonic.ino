#include <HCSR04.h>


// echo mengumpulkan gelombang, trigger mengeluarkan
#define trigger 5
#define echo 4

HCSR04 distance(trigger, echo);

void setup() {
  Serial.begin(115200);
}

void loop() {
  float jarak = distance.dist();
  Serial.println(jarak);
  delay(1000);
}
