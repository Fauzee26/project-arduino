#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingerESP8266.h>

#define username "hilmy2602"
#define id_device "nodemcu"
#define id_credential "nodemcudht11ku"

#define ssid "My ASUS_1005"
#define pswd "56782222"

#define DHTPIN 5

ThingerESP8266 thing(username, id_device, id_credential);

DHT dht(DHTPIN, DHT11);

float hum, temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT11 ON");
  thing.add_wifi(ssid, pswd);

  thing["dht11"] >> [](pson & out){
    out["Kelembapan"] = hum;
    out["Suhu"] = temp;
  };
  Serial.println(dht.readTemperature());
}

void loop() {
  thing.handle();
  hum = dht.readHumidity();
  temp = dht.readTemperature();

}
