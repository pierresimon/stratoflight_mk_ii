/*
    Sketch-Part for gps-sensor
    Projekt "Stratoflight MK2"
    2017 by Pierre Simon, Frederik Simon
*/

#include <Gpsneo.h>
Gpsneo gps;


/*-----------------------------------------------------------------------*/

boolean setupSensorGPS()
{
  //writeLog(2,"Init gps-sensor...");
  //writeLog(2,strOK);

  return true;
}

/*-----------------------------------------------------------------------*/

void getGPSData(String &retVal)
{
  /*char latitude[15];
    char latitudHemisphere[2];
    char longitude[15];
    char longitudMeridiano[15];
  */

  char time[10];
  char status[3];
  char latitud[11];
  char latitudHemisphere[3];
  char longitud[11];
  char longitudMeridiano[3];
  char speedKnots[10];
  char trackAngle[8];
  char date[10];
  char magneticVariation[10];
  char magneticVariationOrientation[3];
  gps.getDataGPRMC(time,
                   status,
                   latitud,
                   latitudHemisphere,
                   longitud,
                   longitudMeridiano,
                   speedKnots,
                   trackAngle,
                   date,
                   magneticVariation,
                   magneticVariationOrientation);

  //gps.getDataGPRMC(latitude, latitudHemisphere, longitude, longitudMeridiano);
  retVal.concat(latitud);
  retVal.concat(";");
  retVal.concat(latitudHemisphere);
  retVal.concat(";");
  retVal.concat(longitud);
  retVal.concat(";");
  retVal.concat(longitudMeridiano);
  retVal.concat(";");
  retVal.concat(speedKnots);
  retVal.concat(";");
  retVal.concat(trackAngle);
  retVal.concat(";");
  retVal.concat(date);
  retVal.concat(";");
  retVal.concat(magneticVariation);
  retVal.concat(";");
  retVal.concat(magneticVariationOrientation);
  retVal.concat(";");

}

