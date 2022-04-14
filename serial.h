#pragma once

/**
   @brief Print string from flash memory to Serial terminal

   @param[in] p pointer to string in falsh
*/
void printPGM(const PROGMEM char * p) {
  char buf[strlen_P(p)];
  strcpy_P(buf, p);
  Serial.print(buf);
}

/**
   @brief Skipping whtespace symbols from Serial terminal

*/
void skipWhitespace()
{
  char temp = Serial.peek();
  while (temp == '\n' or temp == ' ' or temp == '\t' or temp == '\r' or temp == -1)
  {
    if (temp != -1)
    {
      Serial.read();
      Serial.write(temp);
    }
    temp = Serial.peek();
  }
}

/**
   @brief Returns string - readed from Serail to first whitespace symbol

   @return String
*/
String readKeyword()
{
  String result = "";
  char temp = 0;
  skipWhitespace();
  while (temp != '\n' and temp != ' ' and temp != '\t' and temp != '\r')
  {
    if (temp != 0 and temp != -1)
    {
      Serial.write(temp);
      if (temp == 127) {
        // Serial.println(result.substring(0, result.length() - 1));
        if (result.length() > 0) {
          result = result.substring(0, result.length() - 1);
        }
        else {
          Serial.write(' ');
        }
      }
      else {
        result += temp;
      }
    }
    temp = Serial.read();
  }
  // Serial.println(result.length());
  // Serial.println(result);
  Serial.write(temp);
  return result;
}

/**
   @brief Returns string - readed from Serail to first whitespace symbol and converted to low case

   @return String
*/
String readKeywordLower()
{
  String result = readKeyword();
  result.toLowerCase();
  return result;
}
