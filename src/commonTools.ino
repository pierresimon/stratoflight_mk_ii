
//const char strOK[] = "...ok";
//const char strError[] = "##### error #####";

/*----------------------------------------------------------------------------*/

int freeRAM()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

/*----------------------------------------------------------------------------*/


