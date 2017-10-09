#include <SoftwareSerial.h>
#include <Gpsneo.h>

Gpsneo gps;


char latitud[15];
char latitudHemisphere[2];
char longitud[15];
char longitudMeridiano[15];

void  setup()
{
    Serial.begin(9600);
}

void loop()
{
    gps.getDataGPRMC(latitud,latitudHemisphere,longitud,longitudMeridiano);

    Serial.print("Latitude: "); 
    Serial.println(latitud);
    Serial.print("Lat. Hemi.: ");
    Serial.println(latitudHemisphere);
    Serial.print("Longitude: ");
    Serial.println(longitud);
    Serial.print("Log. Hemi.: ");
    Serial.println(longitudMeridiano);
    delay(1000);
}

