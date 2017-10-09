/*
    Sketch-Part for humidity and temperature sensor DHT11
    Projekt "Stratoflight MK2"
    2017 by Pierre Simon, Frederik Simon
*/
/*-----------------------------------------------------------------------*/

#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 2

/*-----------------------------------------------------------------------*/

boolean setupSensorDHT11()
{
  //writeLog(0, "Init sensor DHT11...");
  return true;
}

/*-----------------------------------------------------------------------*/

// delta max = 0.6544 wrt dewPoint()
// reference: http://en.wikipedia.org/wiki/Dew_point
/*
double dewPoint(double celsius, double humidity)
{
  double a = 17.271;
  double b = 237.7;
  double temp = (a * celsius) / (b + celsius) + log(humidity * 0.01);
  double Td = (b * temp) / (a - temp);
  return Td;
}
*/
/*-----------------------------------------------------------------------*/

void getDHT11Data(String &retVal)
{
  if (DHT11.read(DHT11PIN) == DHTLIB_OK)
    retVal.concat(String(DHT11.humidity) + ";"); // + String(dewPoint(DHT11.temperature, DHT11.humidity)));
}

