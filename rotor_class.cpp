#include"errors.h"
#include"rotor_class.h"
#include<fstream>
#include<iostream>
#include<cctype>  //std::isdigit

using namespace std;

Checker::Checker(int* array)
{
  this->array = array;
  this->expectedArrayLength =  expectedArrayLength;
  this->actualArrayLength = actualArrayLength;
};

bool Checker::isDuplicate()
{
  for(int i = 1; i < 26; i++)
    for(int j = 0; j < i; j++)
      if(array[i] == array[j])
	return true;
  return false;
};

bool Checker::isOutOfRange()
{
  for(int i = 0; i < 26; i++)
    if(array[i] < 0 || array[i] > 25)
      return true;
  return false;
};

void Checker::isCorrectLength(int actualArrayLength, int expectedArrayLength)
{
  if (actualArrayLength != expectedArrayLength)
    {
      cout << "The input array is of incorrect length" << endl;
      exit(INVALID_ROTOR_MAPPING);
    } 
}

ArrayCreator::ArrayCreator(const char* filename, int* array)
{
  this->filename = filename;
  this->array = array;
}

void ArrayCreator::create()
{
  ifstream file (filename);
  if (file.fail())
    { 
      cout << "This file couldn't be open" << endl;
      exit(ERROR_OPENING_CONFIGURATION_FILE);
    }
  
  file >> ws; // eat up any leading white spaces
  int temp;
  int i = 0;

  char peek = file.peek();
  while(peek != -1)
    {
      if (!isdigit(peek))
	{
	  if (peek != -1)
	    {
	      cout << "NON_NUMERIC_CHARACTER" << endl;
	      exit(NON_NUMERIC_CHARACTER);
	    }
	  break;
	}
      
      file >> temp; // store the number in temp variable
      file >> ws; // eat up any leading white sp
      array[i] = temp;
      
      cout << array[i] << " - " << i;
      cout << endl;
      peek = file.peek();
      i++;
    }
  actualArrayLength = i;
  
  file.close();
};

int ArrayCreator::getActualArrayLength()
{
  return actualArrayLength;
};


Rotor::Rotor(int rotorNr, const char rotor_fname[], const char setup_fname[], int expectedArrayLength)
{

  // create an array with parameters for Rotor
  ArrayCreator RotorOriginalArray(rotor_fname, originalRotorArray);
  RotorOriginalArray.create();

  //get the expected and the actual length fo the array
  int actualArrayLength = RotorOriginalArray.getActualArrayLength();
  this->expectedArrayLength = expectedArrayLength; 

  //check rotor for correct length, duplicates and out of range values
  Checker RotorCheck(originalRotorArray);
  RotorCheck.isCorrectLength(actualArrayLength,expectedArrayLength);
  bool outOfRange = RotorCheck.isOutOfRange();

  if (outOfRange)
    {
      cout << "OUT OF RANGE" << endl;
      exit(INVALID_INDEX);
    }      // check for valid range


  //assign first 26 values from the rotorArray into the rotorMap
  for(int i = 0; i < 26; i++)
    rotorMap[i] = originalRotorArray[i];

  //check for duplicates
  Checker RotorMap(rotorMap);
  bool duplicate = RotorMap.isDuplicate();

  if (duplicate)
    {
      cout << "DUPLICATE" << endl;
      exit(INVALID_ROTOR_MAPPING);
    }

  //get the notch position
  notchPosition = originalRotorArray[26];  
}; 
void Rotor::movePosition(){};
void Rotor::getPosition(){};
