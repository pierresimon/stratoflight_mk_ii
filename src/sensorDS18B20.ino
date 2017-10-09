/*
    Sketch-Part for digital temperature-sensor DS18B20
    used for ** external ** temperature
    Projekt "Stratoflight MK2"
    2017 by Pierre Simon, Frederik Simon
*/

#include <DallasTemperature.h>
#include <OneWire.h>

const int ONE_WIRE_BUS = 7; // Pin externer Temp.-Sensor

OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensDS18B20(&oneWire);

/*-----------------------------------------------------------------------*/

boolean setupSensorDS18B20()
{
  //writeLog(0,"Init external temp-sensor DS18B20...");
  sensDS18B20.begin();
  return true;
}

/*-----------------------------------------------------------------------*/

void getDS18B20Data(String &retVal)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  sensDS18B20.requestTemperatures(); // Send the command to get temperatures

  retVal.concat(String(sensDS18B20.getTempCByIndex(0) + EXTTEMPCORR) + ";");
}




