#include <Arduino.h>
#include <ESP8266WiFi.h> 
#include <ESP8266WiFiMulti.h> 
#include <ESP8266HTTPClient.h> 
#include <DHT.h>
#define dhtpin 5 //pin data dht11 di pin 5 
#define ssid "SEKOLAH IDN" //SSID wifi 
//#define psswd "xxxxxx"
DHT dht(dhtpin, DHT11);
ESP8266WiFiMulti WiFiMulti; 
String url;
String api = "JX9CUY7T82P06278"; // TOKEN API 
void setup() {
Serial.begin(115200); //setup komunikasi serial 9600 WiFi.mode(WIFI_STA);
//WiFiMulti.addAP(ssid, psswd); // nama wifi dan Password WiFiMulti.addAP(ssid, NULL); //nama wifi ssid tanpa password dht.begin();
}
void loop() {
  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.println("Connecting to Wi-Fi ...");
    delay(500); 
  };
  float temp = dht.readTemperature(); //membaca data suhu 
  float hum = dht.readHumidity(); //membaca data kelembapan
  if (isnan(hum) || isnan(temp)) { //cek data suhu dan kelembapan terbaca atau tidak 
    Serial.println("Gagal baca data sensor");
    return;
  }
  if((WiFiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    Serial.println("[HTTP] Memulai Koneksi...");
    url = "http://api.thingspeak.com/update?api_key=";
    url += api;
    url += "&field1=";
    url += String(temp); //mengirim data suhu
    url += "&field2=";
    url += String(hum); //mengirim data humidity
    Serial.println(url); http.begin(url); //HTTP Request
    int httpCode = http.GET(); // mengakses jawaban server
      if(httpCode > 0) {
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);
          if(httpCode == HTTP_CODE_OK) { 
            String payload = http.getString();
            Serial.println(payload); // print balasan / file html dari server
            Serial.println("\n\n"); 
          }
      } else {
        Serial.println("[HTTP] GET... failed");
      }
   http.end(); // mengakhiri Request 
}
delay(10000); // jeda per koneksi 10 detik 
}
