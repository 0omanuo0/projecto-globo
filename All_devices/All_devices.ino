#include "sd_logger.h"
#include "temp_probe.h"
#include "dht22.h"
#include "bmp180.h"

float tmp_sonda = 0;
float press_bmp = 0;
float humid_dht = 0;

void setup() {

  Serial.begin(9600);
  
  //initSD();

  initProbe();
  initDHT22();
  initBMP();
}

void loop() {
  tmp_sonda = getProbe();
  press_bmp = bmp_getPress();
  humid_dht = getDHTTemperature();
  //writeSD(tmp_sonda);
  Serial.println(tmp_sonda);
  Serial.println(press_bmp);
  Serial.println(humid_dht);
}
