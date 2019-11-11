#ifndef ENIGMA_H
#define ENIGMA_H

#include<iostream>
#include"rotClass.h"
#include"posClass.h"
#include"pbClass.h"
#include"rfClass.h"
#include"classUtils.h"
#include"errors.h"

using namespace std;

class Enigma
{
 public:
  Enigma(int arc, char** argv);
  ~Enigma();
  void encrypt(char& letter);
  int getErr();
  
 private:
  int err;
  int nrOfRotors;
  Plugboard* pb;
  Reflector* rf;
  Rotor** rot;
  Position* pos;

  void rotateRotors();
};
  
#endif
