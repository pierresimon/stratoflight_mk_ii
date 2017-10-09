// BMP180 Barometric Pressure& Temp Sensor //
// Video https://www.youtube.com/channel/UCqJym4fsMaT1CZ2i6GxWURQ
// More information at http://www.jaimeferns.in/2016/10/arduino-bmp180-barometric-pressure-temp.html
// BMP sensor code Modified by embeddedUser from Adafruit example

#include <Wire.h>
#include <Adafruit_BMP085.h>
// based on adafruit example
/***************************************************
  This is an example for the BMP085 Barometric Pressure & Temp Sensor

  Designed specifically to work with the Adafruit BMP085 Breakout
  ----> https://www.adafruit.com/products/391

  These displays use I2C to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
// EOC is not used, it signifies an end of conversion
// XCLR is a reset pin, also not used here
Adafruit_BMP085 bmp;


float pressure = 0.0;
float tempC = 0.0;
float altitude = 0.0;
void BmpSensorRead(float* pressure, float* tempC, float* altitude);

void setup(void)
{
  Serial.begin(9600);

  if (!bmp.begin())
  {
    
    Serial.println("BMP085 sensor, ERROR!");

    while (1) {}
  }
}
void loop(void)
{
  BmpSensorRead(&pressure, &tempC, &altitude);
  delay(1000);
}

void BmpSensorRead(float* pressure, float* tempC, float* altitude)
{
  *tempC = bmp.readTemperature();
  Serial.print("Temperature = ");
  Serial.print(*tempC);
  Serial.println(" *C");

  *pressure = bmp.readPressure() / 100.0;
  Serial.print("Pressure = ");
  Serial.print(*pressure / 100.0);
  Serial.println(" hPa");

  // Calculate altitude assuming 'standard' barometric
  // pressure of 1013.25 millibar = 101325 Pascal
  *altitude = bmp.readAltitude();
  Serial.print("Altitude = ");
  Serial.print(*altitude);
  Serial.println(" meters");
}
