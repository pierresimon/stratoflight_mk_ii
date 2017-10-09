char string2[20];
float y = 0.0;
float z = 1000.0;
int ledPin = 13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial.println("es geht los...");
  pinMode(ledPin, OUTPUT);
}

int freeRam()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

char* formatTimeDigits(int num)
{
  String dummy = "";
  char retVal[3];
  if (num < 10)
    dummy = '0' + String(num);
  else
    dummy = num;

  dummy.toCharArray(retVal, 3);

  return retVal;
}

/*-----------------------------------------------------------------------*/

char* getTime()
{
  char retVal[9];
  long timeNow = millis();
  strcpy(retVal, formatTimeDigits(int(timeNow / 3600000)));
  strcat(retVal, ":");
  strcat(retVal, formatTimeDigits(int((timeNow % 3600000) / 60000)));
  strcat(retVal, ":");
  strcat(retVal, formatTimeDigits(int(((timeNow % 3600000) % 60000) / 1000)));
  return retVal;
}

/*----------------------------------------------------------------------------*/


void ledBlink()
{
  digitalWrite(ledPin, HIGH);   // sets the LED on
  delay(100);                  // waits for a second
  digitalWrite(ledPin, LOW);    // sets the LED off
  delay(100);
}

void writeLog(const char *message)
{
  Serial.print(message);
  if (message != "\n")
    Serial.print(";");
}

char* floatToChar(const float &value)
{
  String dummy = "";
  char retVal[11];
  dummy = value;
  dummy.toCharArray(retVal, 9);
  return retVal;
}

char* getMillis()
{
  char retVal[11];
  String dummy = "";
  dummy = millis();
  dummy.toCharArray(retVal, 10);
  return retVal;
}

char* getValue()
{
  char retVal[20];
  y += 0.3;
  z += 12.12;
  strcpy(retVal, floatToChar(y));
  strcat(retVal, ";");
  strcat(retVal, floatToChar(z));
  return retVal;
}

void loop() {
  String dummyString = "";

  /*
    for (int i = 0; i < 10; i++)
    {

      dummy = y;
      dummy.toCharArray(dummy2, 9);
      strcpy(string2, dummy2);
      writeLog(string2);
      writeLog(";");
      y += 0.3;
    }
  */
  writeLog(getTime());


  strcpy(string2, getMillis());
  strcat(string2, ";");
  writeLog(string2);

  strcpy(string2, getValue());
  strcat(string2, ";");
  writeLog(string2);

  dummyString = freeRam();
  dummyString.toCharArray(string2, 9);
  writeLog(string2);
  writeLog("\n");
  ledBlink();
}
