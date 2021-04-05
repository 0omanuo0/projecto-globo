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

float getProbe(){
    float temperature;
    // call sensors.requestTemperatures() to issue a global temperature 
    // request to all devices on the bus 
    /********************************************************************/
    //Serial.print(" Requesting temperatures..."); 
    sensors.requestTemperatures(); // Send the command to get temperature readings 
    //Serial.println("DONE"); 
    temperature = sensors.getTempCByIndex(0);
    // You can have more than one DS18B20 on the same bus.  
    // 0 refers to the first IC on the wire 
    delay(1000); 
    if(temperature > (float)10000){return -1;}
    else{return temperature;}

    
}

bool initProbe(){sensors.begin();}
