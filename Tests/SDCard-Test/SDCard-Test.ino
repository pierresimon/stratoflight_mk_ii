/*
  SD card datalogger

 This example shows how to log data from three analog sensors
 to an SD card using the SD library.

 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <Gpsneo.h>

Gpsneo gps;


const int chipSelect = 4;


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // while (!Serial) {
  //  ; 
  // wait for serial port to connect. Needed for native USB port only
  // }


  // Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    //Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  // Serial.println("card initialized.");
}

String getGPSData()
{
  String retVal = "";
  char latitud[15];
  char latitudHemisphere[2];
  char longitud[15];
  char longitudMeridiano[15];
  
  gps.getDataGPRMC(latitud,latitudHemisphere,longitud,longitudMeridiano);
  retVal += String(latitud) + ";" + String (latitudHemisphere) + ";" + String(longitud) + ";" + String(longitudMeridiano);
  return retVal;
}

void loop() {
  // make a string for assembling the data to log:
  String dataString = "";

  dataString += ("GPSData: <" + getGPSData() + ">");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog1.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    // Serial.println(dataString);

   
  }
  // if the file isn't open, pop up an error:
  else {
    //Serial.println("error opening datalog.txt");
  }
  delay(1000);
}
