#define pir 5
#define buzzer 4

void setup() {
  Serial.begin(115200);
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int data = digitalRead(pir); //Baca sensor PIR

  if (data == 1){
    Serial.println("Terdeteksi");
    digitalWrite(buzzer, HIGH);
  } else {
    Serial.println("Tidak Terdeteksi");
    digitalWrite(buzzer, LOW);
  }
  delay(200);
}
