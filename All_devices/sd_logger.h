////////////////////////////////////////////////////////////////////////////////////// SD
#include <SPI.h>
#include <SD.h>
////////////////////////////////////////////////////////////////////////////////////// tmp_sonda
// First we include the libraries

File myFile;


int writeSD(String data){
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    myFile = SD.open("data.txt", FILE_WRITE);

    // if the file opened okay, write to it:
    if (myFile) {
        myFile.println(data);
        // close the file:
        myFile.close();
        return 0;
    } else {
        // if the file didn't open, print an error:
        Serial.println("error opening data.txt");
        return -1;
    }
}
    



bool initSD(){
    /////////// SD
    Serial.print("Initializing SD card...");

    if (!SD.begin(10)) {//this number must be 10 for adafruit
        Serial.println("initialization failed!");
        while (1);
    }
  Serial.println("initialization done.");
}
