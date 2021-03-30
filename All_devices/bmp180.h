#include <Wire.h>
#include <math.h>
#include <SFE_BMP180.h>

SFE_BMP180 bmp180;

int Altitude = 5; //current altitude in meters

void initBMP() {
  bool success = bmp180.begin();

  if (success) {
    Serial.print("ey");}
}

float press_sea = 0;

float bmp_getTemp() {

  char status;
  double P;
  double T;
  bool success = false;

  status = bmp180.startTemperature();

  if (status != 0) {
    delay(1000);
    status = bmp180.getTemperature(T);

    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);

        if (status != 0) {
          float comp = bmp180.sealevel(P, Altitude);
          return T;
        }
        else{return -1;}
      }
    }
  }
  else{return-1;}
}


float bmp_getPress() {

  char status;
  double P;
  double T;
  bool success = false;

  status = bmp180.startTemperature();

  if (status != 0) {
    delay(1000);
    status = bmp180.getTemperature(T);

    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);

        if (status != 0) {
          float comp = bmp180.sealevel(P, Altitude);
          return comp;
        }
        else{return-1;}
      }
    }
  }
  else {return -1;}
}




float bmp_getAlt() {

  char status;
  double P;
  double T;
  bool success = false;

  status = bmp180.startTemperature();

  if (status != 0) {
    delay(1000);
    status = bmp180.getTemperature(T);

    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);

        if (status != 0) {
          float comp = bmp180.sealevel(P, Altitude);
          return 44330*(1-pow((comp/press_sea),(1/5.255)));
        }
        else {return -1;}
      }
    }
  }
  else {return -1;}
}
