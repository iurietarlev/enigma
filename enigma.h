#ifndef ENIGMA_H
#define ENIGMA_H

#include<iostream>
#include"errors.h"
#include"rotClass.h"
#include"posClass.h"
#include"pbClass.h"
#include"rfClass.h"
#include"classUtils.h"


class Enigma
{
  int err;
  int nrOfRotors;
  Plugboard* pb;
  Reflector* rf;
  Rotor** rot;
  Position* pos;
  
  void rotateRotors();

 public:
  Enigma(int arc, char** argv);
  ~Enigma();
  void encrypt(char& letter);
  int getErr();
  
};
  
#endif
