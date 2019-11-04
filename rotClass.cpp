#include"errors.h"
#include"rotClass.h"
#include<iostream>

#include"utils.h"

using namespace std;

Rotor::Rotor(){
  //default dynamic memory allocation
  notchArray = new int[1];
};

void Rotor::initialize(int rotorNr, const char rotor_fname[])
{
  this->rotorNr = rotorNr;

  //create an array with all inputs from the relevant file
  //this will also check for any non_numeric chars
  int originalRotorArray[80];
  int actualArrayLength;
  createArray(rotor_fname, originalRotorArray, actualArrayLength); 
  
  //check rotor for correct length, duplicates and out of range values
  bool goodRange = rangeOk(originalRotorArray, actualArrayLength);

  if (!goodRange)
    {
      cout << "At least one of the input numbers for rotor number " \
	   << rotorNr << " is out of range." << endl;
      exit(INVALID_INDEX);
    } 

  cout << "ActualArrayLength = " << actualArrayLength << endl;
  
  if(actualArrayLength < 27)
    {
      cout << "The number of input numbers in rotor number " \
	   << rotorNr << " is of insufficient length." << endl;
      exit(INVALID_ROTOR_MAPPING);
    }
 
  //assign first 26 values from the rotorArray into the rotorMap
  for(int i = 0; i < 26; i++)
    rotorMap[i] = originalRotorArray[i];

  
  //check for duplicates
  bool duplicate = duplicates(rotorMap, 26);

  if (duplicate)
    {
      cout << "One of the inputs in the rotor " << rotorNr << " is a duplicate."  << endl;
      exit(INVALID_ROTOR_MAPPING);
    }

  nrOfNotches = actualArrayLength - 26;

  //overwrite default notch array with the actual number of notches
  notchArray = new int[nrOfNotches];

  cout << "Number of Notches = " << nrOfNotches << endl;
  cout << "26th index of originalRotorArray = " << originalRotorArray[26] << endl;
  for(int i = 0; i < nrOfNotches; i++)
    {
      notchArray[i] = originalRotorArray[26+i];
      cout <<  notchArray[i] << endl;
    }
};

//Rotor destructor
Rotor::~Rotor(){
  cout << "Notch Array has died" << endl;
  delete[] notchArray;
};
void Rotor::movePosition(){};
void Rotor::getPosition(){};
