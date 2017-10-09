#include <Wire.h>
#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);

int ozone_sensor_value = 0;
int ozone_snsor_value_temporaer = 0;




void setup() {
  Serial.begin(9600);

  if (u8g.getMode() == U8G_MODE_R3G3B2)
  {
    u8g.setColorIndex(155);     // white
  }
  else if (u8g.getMode() == U8G_MODE_GRAY2BIT)
  {
    u8g.setColorIndex(3);         // max intensity
  }
  else if (u8g.getMode() == U8G_MODE_BW)
  {
    u8g.setColorIndex(1);         // pixel on
  }
  else if (u8g.getMode() == U8G_MODE_HICOLOR)
  {
    u8g.setHiColorByRGB(255, 155, 155);
  }
}

for (int a = 0; a < 30; a++)
  {
    u8g.firstPage();

    do
    {
      u8g.setFont(u8g_font_fub11);
      u8g.setFontRefHeightExtendedText();
      u8g.setDefaultForegroundColor();
      u8g.setFontPosTop();
      u8g.drawStr(4, a, "zocker");
    }
    while (u8g.nextPage());
  }

void loop() {
  //displayOutput(analogRead(ozone_sensor_value));

 // u8g.firstPage();


/*
u8g.setFont(u8g_font_fub11);
u8g.setFontRefHeightExtendedText();
u8g.setDefaultForegroundColor();
u8g.setFontPosTop();
u8g.drawStr(4, 0, "Ozon-Wert:");
*/
  
  //Serial.println(analogRead(ozone_sensor_value));
  delay (500); 
}
/*
void displayOutput(int ozone_sensor_value_temporaer) {
u8g.firstPage();

do {

u8g.setFont(u8g_font_fub11);
u8g.setFontRefHeightExtendedText();
u8g.setDefaultForegroundColor();
u8g.setFontPosTop();
u8g.drawStr(4, 0, "Ozon-Wert:");
//u8g.setPrintPos(65, 0);
//u8g.print(ozone_sensor_value_temporaer);

}
//while(u8g.nextPage())
}
*/
