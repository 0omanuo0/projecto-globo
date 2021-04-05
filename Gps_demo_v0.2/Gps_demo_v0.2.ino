#include <SoftwareSerial.h>//include the serial software to comunicate with gps module
#include <TinyGPS.h>//include the TinyGPS library (it is used to parse raw data from serial)

TinyGPS gps;//Declare gps object
SoftwareSerial serialgps(4,3);//Declare pin 4 for Tx and 3 for Rx comunication gps serial

//We declare the variables for data collection
int year;
byte month, day, hour, minute, second, hundredths;
unsigned long chars;
unsigned short sentences, failed_checksum;

void setup()
{
  Serial.begin(115200);//Inizializing serial port
  serialgps.begin(9600);//Inizializing serial port for gps, 
                        //it bust be 9600 for gy-gps6mv2
  Serial.println("");
  Serial.println("         GPS GY-GPS6MV2         ");
  Serial.println(" ---Searching for satellites--- ");
  Serial.println("");
}

void loop()
{
  while(serialgps.available()) 
  {
    int c = serialgps.read();
 
    if(gps.encode(c))  
    {
      float latitude, longitude;
      gps.f_get_position(&latitude, &longitude);
      Serial.print("Lat/Long: "); 
      Serial.print(latitude,5); 
      Serial.print(", "); 
      Serial.println(longitude,5);


  gps.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);
      Serial.print("Date: "); Serial.print(day, DEC); Serial.print("/"); 
      Serial.print(month, DEC); Serial.print("/"); Serial.print(year);
      Serial.print(" Hour: "); Serial.print(hour, DEC); Serial.print(":"); 
      Serial.print(minute, DEC); Serial.print(":"); Serial.print(second, DEC); 
      Serial.print("."); Serial.println(hundredths, DEC);
      Serial.print("Alt (metros): ");
      Serial.println(gps.f_altitude()); 
      Serial.print("Course (deg): "); Serial.println(gps.f_course()); 
      Serial.print("Vel(kmph): ");
      Serial.println(gps.f_speed_kmph());
      Serial.print("Satellites: "); Serial.println(gps.satellites());
      Serial.println();
      gps.stats(&chars, &sentences, &failed_checksum);  
    }
  }
}
