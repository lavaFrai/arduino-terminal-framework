#include "serial.h"

char test()
{
  Serial.print("\r\n");
  Serial.println("Kakoy to  randomniy tekst!");
  return 0;
}

char argtest()
{
  String arg1 = readKeyword();
  String arg2 = readKeywordLower();
  Serial.print("\r\n");
  Serial.print("Arg1 (standrt): ");
  Serial.println(arg1);
  Serial.print("Arg2 (lower): ");
  Serial.println(arg2);
  return 0;
}
