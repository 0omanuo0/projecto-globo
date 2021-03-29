////////////////////////////////////////////////////////////////////////////////////// SD
#include <SPI.h>
#include <SD.h>
////////////////////////////////////////////////////////////////////////////////////// tmp_sonda
// First we include the libraries

File myFile;


bool writeSD(float data){
        // nothing happens after setup
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    myFile = SD.open("test.txt", FILE_WRITE);

    // if the file opened okay, write to it:
    if (myFile) {
        Serial.print("Writing to test.txt...");
        myFile.println(data);
        // close the file:
        myFile.close();
        Serial.println("done.");
    } else {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");
    }
    return true;
}


bool initSD(){
     //////////////////////////////////////////////////////////////// SD
  Serial.print("Initializing SD card...");

    if (!SD.begin(10)) {//this number must be 10 for adafruit
        Serial.println("initialization failed!");
        while (1);
    }
  Serial.println("initialization done.");
}