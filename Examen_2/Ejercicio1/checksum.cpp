#include "checksum.h"
#include <iostream>
#include <string>
#include <cstring>

uint32_t Checksum::compute(const std::string &str)
{

  uint32_t temp = 0;

  if (str.size() > 4)
  {
    if (str.size() % 4 == 0)
    {
      int x = 0;
      while (x <= str.size())
      {
        temp += makeWord(str[x], str[x + 1], str[x + 2], str[x + 3]);
        x += 4;
      }
      return (~temp + 1);
    }
  }
  else if (str.size() == 3)
  {
    temp += makeWord(str[0], str[1], str[2], ' ');
    return (~temp + 1);
  }
  else
  {
    temp += makeWord(str[0], str[1], ' ', ' ');
    return (~temp + 1);
  }
}