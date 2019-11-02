#include"errors.h"
#include"rotor_class.h"
#include<fstream>
#include<iostream>
#include<cctype>  //std::isdigit

using namespace std;

Checker::Checker(int* array, int array_length)
{
  this->array = array;
  this->array_length = array_length;
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

void Checker::isCorrectLength()
{
  if (array_length != 27)
    {
      cout << array_length << endl;
      cout << "INVALID_ROTOR_MAPPING" << endl;
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

  file.close();
};


void Rotor::setNotchPosition()
{
  notchPosition = originalRotorArray[26];
};


void Rotor::setRotorMap()
{
  for(int i = 0; i < 26; i++)
    rotorMap = originalRotorArray[i];
};
  


Rotor::Rotor(int rotorNr, const char rotor_fname[], const char setup_fname[])
{
  ArrayCreator RotorOriginalArray(rotor_fname, originalRotorArray);
  RotorOriginalArray.create();

  

  cout << rotorMap[10] << endl;
  cout << rotorMap[20] << endl;
  cout << rotorMap[26] << endl;

  
  int length_of_array = 27;
  Checker rotorCheck(rotorOutput, length_of_array);
  rotorCheck.isCorrectLength();
  bool duplicate = rotorCheck.isDuplicate();
  bool outOfRange = rotorCheck.isOutOfRange();
  if (duplicate)
    {
      cout << "DUPLICATE" << endl;
      //      cout <<rotorOutput) << endl;
    }
  
  if (outOfRange)
    {
      cout << "OUT OF RANGE" << endl;
    }      // check for valid range
}; 
void Rotor::movePosition(){};
void Rotor::getPosition(){};

void Rotor::rotorSetup()
{};
void Rotor::verifyRotorSetup()
{
  
  
};

//int Rotor::notchPosition =
//int Rotor::currentPosition = 

