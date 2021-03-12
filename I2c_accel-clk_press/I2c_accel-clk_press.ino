#include<Wire.h>
    const int MPU_addr=0x69;  // I2C address ACELEROMETRO MPU-6050
    const int ZS_addr=0x68;   //I2C address RELOJ
    int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ; //VARIABLES LECTURA

#include <Adafruit_BMP085.h>

    #include <Arduino.h>
#include <Wire.h>


#define I2C_ADDRESS 0x77


Adafruit_BMP085 bmp;

 

    
    void setup(){
      Wire.begin();
      Wire.beginTransmission(MPU_addr); //Seleeciona acelerómetro
      Wire.write(0x6B);  // Inicializa registro interno del acelerómetros
      Wire.write(0);     // Despertar acelerómetro
      Wire.endTransmission(true); //Finaliza la transmisión, puede ser true o nada
      
      Wire.beginTransmission(ZS_addr); //DS3231 address
      Wire.write(0x0E); //Inicializa registro interno del reloj
      Wire.write(0);  //Despertar reloj
      Wire.endTransmission(true); //Finaliza la transmisión, puede ser true o nada





      while (!Serial);

  Wire.begin();

  

      Serial.begin(9600);

    }
    void loop(){
      accelerometro();   
      delay(100);
      reloj();
      delay(100);


delay(1000);

  Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" meters");
    
    Serial.println();
    delay(500);
  
    }

   void accelerometro(){
      Wire.beginTransmission(MPU_addr);
      Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
      Wire.endTransmission(false);
      Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
      AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
      AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
      AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
      Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
      GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
      GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
      GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
      //Serial.print("AcX = "); Serial.print(AcX);
      Serial.print(" | AcY = "); Serial.print(AcY);
      Serial.print(" | AcZ = "); Serial.print(AcZ);
      Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equ<ation for temperature in degrees C from datasheet
      //Serial.print(" | GyX = "); Serial.println(GyX);
      Serial.print(" | GyY = "); Serial.println(GyY);
      //Serial.print(" | GyZ = "); Serial.println(GyZ);
      Wire.endTransmission();
   }
   
  void reloj(){
      Wire.beginTransmission(ZS_addr);
      Wire.write(0x01);
      Wire.endTransmission(false);
      Wire.requestFrom(ZS_addr,1,true);
      Serial.println(Wire.read());
  }
