#define pinldr 5
#define relay 4

void setup() {
  Serial.begin(115200);
  pinMode(pinldr, INPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  float sensor = analogRead(pinldr);
  Serial.println(sensor);

if (sensor > 1000) {
  digitalWrite(relay, LOW); // Lampu nyala
} else {
  digitalWrite(relay, HIGH); // Lampu Mati
}
delay(500);
}

/*
 * ## Sensor LDR
 * VCC to 3V
 * GND to GND/G
 * D0 to GPIO 5
 * 
 * ## Relay
 * VCC to 3V
 * GND to GND/G
 * 1N2 to D2 (GPIO 4)
 */
