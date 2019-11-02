#include"errors.h"
#include"rotor_class.h"
#include<fstream>
#include<iostream>
#include<cctype>  //std::isdigit

using namespace std;

Checker::Checker(int* array)
{this->array = array;};

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


Rotor::Rotor(int rotorNr, const char rotor_fname[], const char setup_fname[])
{
  ifstream file (rotor_fname);
  if (file.fail())
    { 
      cout << "This file couldn't be open" << endl;
      exit(1);
    }



  file >> ws; // eat up any leading white spaces
  int temp;
  int i = 0;
  for (; i < 27; i++)
    {
      char peek = file.peek();
      if (!isdigit(peek))
	{
	  if (peek != -1)
	    cout << NON_NUMERIC_CHARACTER << endl;
	  break;
	}
      
      file >> temp;
      
      file >> ws; // eat up any leading white sp
	  rotorOutput[i] = temp;

     
      cout << rotorOutput[i] << " - " << i;
      cout << endl;
      
    }

  if (i != 27)
    {
      cout << i << endl;
      cout << "INVALID_ROTOR_MAPPING" << endl;
      exit(INVALID_ROTOR_MAPPING);
    }
       
  
  Checker rotorCheck(rotorOutput);
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

