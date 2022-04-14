#include "constants.h"
#include "serial.h"

#define     PSTR(s)   ((const PROGMEM char *)(s))

const char greeting[] PROGMEM = "Welcome to lava.analizer\r\n";

/**
   @brief Выводит приветствие при запуске программы

*/
void printGreeting()
{
  printPGM(greeting);
  Serial.print("Loaded ");
  Serial.print(getPathLength());
  Serial.print(" programs from path\r\n");
}


void setup()
{
  Serial.begin(115200);
  printGreeting();
}

void loop()
{
  Serial.print("\r\n > ");
  String program = readKeyword();
  // Serial.print("\r\n");
  for (int i = 0; i < getPathLength(); i++)
  {
    if (path[i].name == program)
    {
      path[i].function();
      return 0;
    }
  }
  Serial.print("\r\n");
  Serial.print(program);
  Serial.print(" it is not program");
}
