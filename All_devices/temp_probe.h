#include <OneWire.h> 
#include <DallasTemperature.h>
/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 


OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 

float callProbe(){
    float temperature;
    // call sensors.requestTemperatures() to issue a global temperature 
    // request to all devices on the bus 
    /********************************************************************/
    //Serial.print(" Requesting temperatures..."); 
    sensors.requestTemperatures(); // Send the command to get temperature readings 
    //Serial.println("DONE"); 
    /********************************************************************/
    Serial.print("Temperature is: "); 
    temperature = sensors.getTempCByIndex(0);
    Serial.print(temperature); // Why "byIndex"?  
    Serial.print("\n"); 
    // You can have more than one DS18B20 on the same bus.  
    // 0 refers to the first IC on the wire 
    delay(1000); 
    return temperature;

}

bool initProbe(){

      Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
    sensors.begin();
    return true;
}