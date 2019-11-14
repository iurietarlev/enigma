#ifndef POS_CLASS_H
#define POS_CLASS_H

#include<iostream>
#include"errors.h"
#include"classUtils.h"

class Position
{
  int * array; 
  int expectedArrayLenght;
  int err;

 public:
  Position(const char positionFname[], int expectedArrayLength);
  ~Position();
  int getStartPos(int rotor_index);
  int getErr();
};

#endif
