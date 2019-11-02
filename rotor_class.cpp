#include"errors.h"
#include"rotor_class.h"
#include<fstream>
#include<iostream>
#include<cctype>  //std::isdigit

using namespace std;

Checker::Checker(int iterNr, int currentNr, int* array)
{
  
  this->iterNr = iterNr;
  this->currentNr = currentNr;
  this->array = array;

};

bool Checker::isDuplicate()
{
  for(int j = 0; j < iterNr; j++)
    if(currentNr == array[j])
      return true;
  return false;
};

bool Checker::isOutOfRange()
{
  if(currentNr < 0 || currentNr > 25)
    {
      //cout << INVALID_INDEX << endl;
      return true;
    }
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
  for (int i = 0; i < 26; i++)
    {
      char peek = file.peek();
      if (!isdigit(peek))
	{
	  if (peek != -1)
	    {
	      cout << NON_NUMERIC_CHARACTER << endl;
	    }
	  break;    
	}

      file >> temp;
      
      Checker rotorCheck(i, temp, rotorOutput);
      bool duplicate = rotorCheck.isDuplicate();
      bool outOfRange = rotorCheck.isOutOfRange();
      if (duplicate  == true)
	{
	  cout << "DUPLICATE" << endl;
	  break;
	}
      if (outOfRange == true)
	{
	  cout << "OUT OF RANGE" << endl;
	  break;
	}      // check for valid range
		
      
      
      
 
		
  //      if isDuplicate(i, temp, rotorOutput)
  
  file >> ws; // eat up any leading white sp
  rotorOutput[i] = temp;
  cout << rotorOutput[i];
  cout << endl;
      
}
  
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

