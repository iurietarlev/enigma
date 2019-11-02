#ifndef ROTOR_CLASS
#define ROTOR_CLASS


#include<fstream>
#include<iostream>

class Checker
{
 public:
  Checker(int* array);
  bool isDuplicate();
  bool isOutOfRange();
  void isCorrectLength(int actualArrayLength, int expectedArrayLength);
 private:
  int *array;
  int expectedArrayLength;
  int actualArrayLength;
};

class ArrayCreator
{
 public:
  ArrayCreator(const char* filename, int* array);
  void create();
  int getActualArrayLength();
 private:
  const char* filename;
  int* array;
  int actualArrayLength;
};     


class Rotor
{
 public:
  Rotor(int rotorNr, const char rotor_fname[], const char setup_fname[], int expectedArrayLength); 
  void movePosition();
  void getPosition();

private:
  int rotorNr;
    
  int originalRotorArray[100];
  int rotorMap[26];
  int notchPosition; 
  int currentPosition;
  int expectedArrayLength;

  
};

#endif
