#ifndef RF_CLASS
#define RF_CLASS

#include<iostream>
#include"errors.h"
#include"classUtils.h"

class Reflector
{
  int rfMap[26];
  int arrayLength = 26;
  int err;

 public:
  Reflector(const char* rfFname);
  void encode(int &encLetter);
  int getErr();
};

#endif
