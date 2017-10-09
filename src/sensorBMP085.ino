/*
    Sketch-Part for temperature & pressure-sensor BMP085
    used for ** internal ** temp & pressure
    Projekt "Stratoflight MK2"
    2017 by Pierre Simon, Frederik Simon
*/

#include <Adafruit_BMP085.h>

Adafruit_BMP085 sensBMP085;

/*-----------------------------------------------------------------------*/

boolean setupSensorBMP085()
{
  //writeLog(0, "Init internal temp-sensor BMP085...");
  if (!sensBMP085.begin())
  {
    return false;
  }
  return true;
}

/*-----------------------------------------------------------------------*/

void getBMP085Data(float &altitude, String &retVal)
{
  altitude = sensBMP085.readAltitude();// + ALTICORR;
  retVal.concat(String(sensBMP085.readTemperature() + INTTEMPCORR) + ";" +
                String((sensBMP085.readPressure() / 100.0) + PRESSURECORR) + ";" +
                String(altitude) + ";");
}


