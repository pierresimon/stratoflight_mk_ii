/*
    Sketch-Part for ozone sensor MQ131
    Projekt "Stratoflight MK2"
    2017 by Pierre Simon, Frederik Simon
*/


/*-----------------------------------------------------------------------*/

boolean setupSensorMQ131()
{
  return true;
}

/*-----------------------------------------------------------------------*/

void getMQ131Data(String &retVal)
{
  retVal.concat(String(analogRead(0) + OZONCORR) + ";");
}
