#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 4
#define RST_PIN 5
#define led 0

int statuss = 0;
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("ID :");
  String content = "";
  byte letter;
  for (byte i = 0; i <mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  Serial.println();
  content.toUpperCase();

  if (content.substring(1) == "79 B7 34 99") {
    if (statuss == 0) {
      digitalWrite(led, HIGH);
      statuss = 1;
    } else {
      digitalWrite(led, LOW);
      statuss = 0;
    }
  }

  delay (1000);

}

/*
 * SDA (SS) to D2 (GPIO 4)
 * SCK to D5 (GPIO 14)
 * MOSI to D7 (GPIO 13)
 * MISO to D6 (GPIO 12)
 * GND to GND/G
 * RST to D1 (GPIO 5)
 * 3.3V to 3V
 * 
 * LED 
 * Kaki Panjang D3
 * Kaki Pendek G
 */
