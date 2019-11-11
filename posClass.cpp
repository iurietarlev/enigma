#include"errors.h"
#include"classUtils.h"
#include"posClass.h"
#include<iostream>

using namespace std;

Position::Position(const char positionFname[], int expectedArrayLength)
{
  int actualArrayLength;
  int positionArray[1024];
  err = NO_ERROR;
  err = createArray(positionFname, positionArray, actualArrayLength); 

  if(err == NON_NUMERIC_CHARACTER)
    {
      cerr << "Non-numeric character in rotor positions file "
	   << positionFname << endl;
    }    

  
  if(err == NO_ERROR)
    {
      if (!isInRange(positionArray, actualArrayLength))
	{
	  err = INVALID_INDEX;
	  cerr << "Out of range character in plugboard positions file "
	       << positionFname << endl;
	}
      else if(actualArrayLength < expectedArrayLength)
	{
	  err = NO_ROTOR_STARTING_POSITION;
	  cerr << "No starting position for rotor " 
	       << actualArrayLength << " in rotor position file: "
	       << positionFname << endl;
	}
      else
	{
	  err = NO_ERROR;
	  array = new int[actualArrayLength];
	  for(int i = 0; i < actualArrayLength; i++)
	    array[i] = positionArray[i];
	}
    }
};

int Position:: getStartPos(int rotorIndex)
{
  return array[rotorIndex];
};


int Position:: getErr()
{return err;};

Position::~Position()
{
  //cout << "Position class has died" << endl;
  delete[] array;
}
