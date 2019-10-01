#include <Servo.h>

#define pir 5
#define buzzer 4
#define servo 0

Servo serv;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pir, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(pir); //Baca sensor pir
  if (data == 1) {
    Serial.println("Terdeteksi");
    buka();
  } else {
    Serial.println("Tidak Terdeteksi");
    tutup();
  }
  delay(200);
}

void buka() {
  serv.attach(servo);
  serv.write(90);
  delay(15);
  serv.detach();
}


void tutup() {
  serv.attach(servo);
  serv.write(0);
  delay(15);
  serv.detach();
}
