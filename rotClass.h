#ifndef ROTOR_CLASS
#define ROTOR_CLASS

#include<iostream>
#include"errors.h"
#include"classUtils.h"

class Rotor
{
  int err;   
  int nrOfNotches;
  int* notchPos; 
  int curtPos;
  
 public:
  
  Rotor(const char *rotor_fname); 
  ~Rotor();
  
  void setStartPos(int startPos);
  void mvPos();
  int getCurtPos();
  bool isCurtPosNotch();

  int rotorMap[26][2];
  void encodeFwd(int& encLetter);
  void encodeBwd(int& encLetter);
  
  int getErr();
};

#endif
