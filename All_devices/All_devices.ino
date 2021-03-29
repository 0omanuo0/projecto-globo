#include "sd_logger.h"
#include "temp_probe.h"
#include "gps.h"

float tmp_sonda = 0;

void setup() {

  Serial.begin(9600);
  
  initSD();
  initGPS();
  initProbe();

}

void loop() {

  tmp_sonda = callProbe();
  writeSD(tmp_sonda);
  
  GPS();
}