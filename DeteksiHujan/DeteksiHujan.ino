#define sensor A0
#define buzzer 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  float data = analogRead(sensor);
  Serial.println(data);

  if (data < 1000) {
    Serial.println("Deteksi Hujan");
    digitalWrite(buzzer, HIGH);
  } else {
    Serial.println("Tidak Hujan");
    digitalWrite(buzzer, LOW);
  }
  delay(200);
}

/*
 * Sensor Hujan
 * VCC to 3V
 * GND to GND/G
 * A0 to pin A0
 */
