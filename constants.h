#include "programs.h"

/**
   @brief Структура программы, которую впоследствии можно вызвать из терминала

*/
struct program
{
  String name;
  char (*function)();
};

/**
   @brief Список программ, которые можно вызвать из консоли. name - алиас для вызова, function - указатель на функцию

*/
program path[] = {
  {"test", test},
  {"argtest", argtest}
};

/**
   @brief Возвращает количество элементов в переменной path

   @return int
*/
int getPathLength()
{
  return sizeof(path) / sizeof(program);
}
