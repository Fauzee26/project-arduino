#include<DHT.h>

#define pindht 5
#define dhttype DHT11

DHT dht (pindht,DHT11);

void setup() {
  dht.begin();
  Serial.begin(115200);
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();

  if(isnan(suhu)||isnan(kelembapan)){ //is not number
    Serial.println("Failed to read");
    
    return;
    
    }

     Serial.print("Suhu :");
     Serial.println(suhu);
     Serial.print("Kelembapan :");
     Serial.println(kelembapan);

     delay(1000);

}
