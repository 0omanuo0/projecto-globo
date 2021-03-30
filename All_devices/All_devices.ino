#include "sd_logger.h"
#include "temp_probe.h"

float tmp_sonda = 0;
float press_bmp = 0;

void setup() {

  Serial.begin(9600);
  
  initSD();

  hinitProbe();
}

void loop() {

  tmp_sonda = getProbe();
  press_bmp = bmp_getPress();
  writeSD(tmp_sonda);
  Serial.println(tmp_sonda);
  Serial.println(press_bmp);
}