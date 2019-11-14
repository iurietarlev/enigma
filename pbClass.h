#ifndef PLGBRD_CLASS
#define PLGBRD_CLASS

#include<iostream>
#include"errors.h"
#include"classUtils.h"

class Plugboard
{
  int* pbMap;
  int arrayLength;
  int err;
  
 public:
  Plugboard(const char* pbFname);
  ~Plugboard();
  void encode(int& encLetter);
  int getErr();  
};

#endif
