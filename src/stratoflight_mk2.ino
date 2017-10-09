#include <SPI.h>
#include <Wire.h>

const int SPEAKER = 3; // Speaker an Pin 3
const int HUMIDITY = 5; // Feuchte-Sensor an Pin 5


const boolean TESTMODE = false;
const float EXTTEMPCORR = 0.0;
const float INTTEMPCORR = 0.0;
const float PRESSURECORR = 0.0;
const float ALTICORR = 0.0;
const int OZONCORR = 0;
boolean firstRun = true;
boolean sdCardOK = true;

byte beepCtr = 0;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  //wait for serial port to connect. Needed for native USB port only
  /*  while (!Serial)
    {
      ;
    }
  */

  setupSpeaker;
	sdCardOK = setup_sdcard();
	if (sdCardOK == true)
	{
    setupSensorBMP085(); // internal temp. & pressure sensor
    setupSensorDS18B20(); // external temp.-sensor
    setupSensorGY521(); // Accel-/Gyro-sensor
    setupSensorDHT11(); // Humidity-/Temp-Sensor
    setupSensorMQ131(); // Ozon-Sensor
    setupSensorGPS(); // GPS-module 
 
    if (TESTMODE == false)
    {
      shortBeep(5);
      while (millis() < 10000)
      {
        delay(100);
      }
      shortBeep(4);
      delay(1000);
    }
    else
      shortBeep(3);
	}
	
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

void loop() {

  String logString = "";
  float altitude = 0.0;
  unsigned long onTime = millis();

	if (sdCardOK)
	{
    if (firstRun == true)
    {
      writeLog(0, "START");
     f irstRun = false;
    } 
  
    if ((!TESTMODE) && (onTime < 60000))
      shortBeep(1);
 
    logString.concat(String(onTime) + ";");
  
    getDS18B20Data(logString);
    getBMP085Data(altitude, logString);
    getDHT11Data(logString);
    getMQ131Data(logString);
    getGY521Data(logString);
    //getGPSData(logString);
    logString.concat(freeRAM());
  
    writeLog(0, logString);
  
    if ((!TESTMODE) && (onTime < 60000))
      shortBeep(2);
      
    // Beep after 3.5 hrs and below 500m
    if ((onTime > 12600000) && (altitude < 500.0))
    {
      beepCtr += 1;
      if (beepCtr >= 10)
      {
        doBeep();
        beepCtr = 0;
      }
    }
	}
	else
	{
	  errorBeep();
	}

  delay(1000);
}
