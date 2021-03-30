#include "DHT.h"
 
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
 
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
 
const int DHTPin = 5;     // what digital pin we're connected to
 
DHT dht(DHTPin, DHTTYPE);
 
void initDHT22() {dht.begin();}
 
float getDHTTemperature(){
    float t = dht.readTemperature();
    if (isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return -1;
    }
    return t;

}

float getDHTHumidity(){
    float h = dht.readHumidity();
    if (isnan(h)) {
      Serial.println("Failed to read from DHT sensor!");
      return -1;
    }

    return h;
}
