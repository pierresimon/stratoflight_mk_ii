/*
   Sketch-Part for writing log-messages to sd-card
   Projekt "Stratoflight MK2"
   2017 by Pierre Simon, Frederik Simon
*/

#include <SD.h>

/*-----------------------------------------------------------------------
  initialize sd-card
*/
boolean setup_sdcard()
{
  // see if the card is present and can be initialized:
  if (!SD.begin(4)) {
    // Card failed, or not present, don't do anything more
    return false;
  }
	return true;
}

/*-----------------------------------------------------------------------*/

void writeLog(const byte aFile, const String &message)
{
  if (TESTMODE == true)
    Serial.println(message);
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog1.log", FILE_WRITE);

  if (!dataFile) {
    Serial.println("error opening logfile");
    return;
  }

  dataFile.println(message);
  dataFile.close();
}

