#include <SoftwareSerial.h>//include the serial software to comunicate with gps module
#include <TinyGPS.h>//include the TinyGPS library (it is used to parse raw data from serial)

TinyGPS gps;//Declare gps object
SoftwareSerial serialgps(4,3);//Declare pin 4 for Tx and 3 for Rx comunication gps serial

//We declare the variables for data collection
int year;
byte month, day, hour, minute, second, hundredths;
unsigned long chars;
unsigned short sentences, failed_checksum;
//public String a = "";

void initGPS()
{
  serialgps.begin(9600);//Inizializing serial port
}

bool get_GPSlocation()
{
  while(serialgps.available()) 
  {
    int c = serialgps.read();
 
    if(gps.encode(c))  
    {
      float latitude, longitude;
      gps.f_get_position(&latitude, &longitude);
      //a = String(latitude) + "," + String(longitude);
      String a = String(latitude) + "," + String(longitude);
      Serial.println(a);
      return a;
    }
    else return -1;//return String(-1);
  }
}


String get_GPSdate()
{
  while(serialgps.available()) 
  {
    int c = serialgps.read();
 
    if(gps.encode(c))  
    {
        gps.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);
        String date = String(day) + "," + String(month) + "," + String(year) + ";" + String(hour) + "," + String(minute) + "," + String(second);
        return date;
    }else return String((float)-1);
  }
}
