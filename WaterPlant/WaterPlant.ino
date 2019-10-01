#define sens A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(sens, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float data = analogRead(sens);
  Serial.println(data);

  if (data > 900) {
    Serial.println("Kering");
  } else {
    Serial.println("Basah");
  }
  delay(500);
}
