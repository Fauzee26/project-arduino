#define sensorpin A0
#define buzzer 5

void setup() {  
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(sensorpin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float data = analogRead(sensorpin);
  Serial.println(data);

  if (data>50) {
    digitalWrite(buzzer, LOW);
  } else {
    digitalWrite(buzzer, HIGH);
  }
}

// Deteksi kebakaran
