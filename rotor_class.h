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
 private:
  int *array;
};

class CheckForCharAndLength
{
 public:
  CheckForCharAndLength
	      


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
  int rotorOutput[26];
  
  int notchPosition; 
  int currentPosition;
  //  const char mapping[];

  
};

#endif
