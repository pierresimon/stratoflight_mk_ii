/*
    Sketch-Part for Tiltsensor GY-521 (MPU 6050)
    Projekt "Stratoflight MK2"
    2017 by Pierre Simon, Frederik Simon
*/

/*-----------------------------------------------------------------------*/

boolean setupSensorGY521()
{
  //writeLog(1, "Init Gyro-sensor GY512...");
  Wire.begin();
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);  // Gyro Config
  Wire.write(0);     // to +/- 250 degree/s
  Wire.endTransmission(true);
  Wire.beginTransmission(0x68);
  Wire.write(0x1c);  // Accel Config
  Wire.write(0);     // to +/- 2G
  Wire.endTransmission(true);
  return true;
}

/*-----------------------------------------------------------------------*/

void getGY521Data(String &retVal)
{
  int myValue;

  Wire.beginTransmission(0x68);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 14, true); // request a total of 14 registers

  myValue = (Wire.read() << 8 | Wire.read());// / 16384.0; // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  retVal.concat(String(myValue) + ";");
  myValue = (Wire.read() << 8 | Wire.read());// / 16384.0; // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  retVal.concat(String(myValue) + ";");
  myValue = (Wire.read() << 8 | Wire.read());// / 16384.0; // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  retVal.concat(String(myValue) + ";");

  myValue = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)

  myValue = (Wire.read() << 8 | Wire.read());// / 131.0; // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  retVal.concat(String(myValue) + ";");
  myValue = (Wire.read() << 8 | Wire.read());// / 131.0; // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  retVal.concat(String(myValue) + ";");
  myValue = (Wire.read() << 8 | Wire.read());// / 131.0; // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  retVal.concat(String(myValue) + ";");
}

