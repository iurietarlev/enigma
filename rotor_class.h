#ifndef ROTOR_CLASS
#define ROTOR_CLASS


#include<fstream>
#include<iostream>

class Checker
{
 public:
  Checker(int* array, int array_length);
  bool isDuplicate();
  bool isOutOfRange();
  void isCorrectLength();
 private:
  int *array;
  int array_length;
};

class ArrayCreator
{
 public:
  ArrayCreator(const char* filename, int* array);
  void create();
 private:
  const char* filename;
  int* array;
};     


class Rotor
{
 public:
  Rotor(int rotorNr, const char rotor_fname[], const char setup_fname[]); 
  void movePosition();
  void getPosition();
  void rotorSetup();
  void verifyRotorSetup();

private:
  int rotorNr;
  int* originalRotorArray;

  void setNotchPosition();
  void setRotorMap();
  
  int rotorMap[26]; 
  int notchPosition; 
  int currentPosition;
  //  const char mapping[];

  
};

#endif
