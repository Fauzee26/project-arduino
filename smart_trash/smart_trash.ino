#include <HCSR04.h>
#include <Servo.h>

#define trigger 5
#define echo 4
#define pinservo 16

Servo serv;
HCSR04 distance(trigger, echo);
int status = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  float sensor = distance.dist();

  if (sensor >= 5 && sensor <= 20) {
    buka();
  } else {
    tutup();
  }
}

void buka() {
  serv.attach(pinservo);
  serv.write(90);
  delay(15);
  Serial.println("Dibuka");
  serv.detach();
}

void tutup() {
  serv.attach(pinservo);
  serv.write(0);
  delay(15);
  Serial.println("Ditutup");
  serv.detach();
}

/*
 * Sensor ultrasonik
 * 1. Vcc to pin VCC/3V
 * 2. Trigger to pin GPIO 5
 * 3. echo to pin GPIO 4
 * 4. Gnd to Gnd/G
 */

/*
 * Servo
 * 1. Kabel Coklat to pin GND/G
 * 2. Kabel Merah to pin VCC/3V
 * 3. Kabel Orange to pin GPIO 16 (A0)
 */
