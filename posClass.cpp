#include"errors.h"
#include"classUtils.h"
#include"posClass.h"
#include<iostream>

using namespace std;

Position::Position(const char positionFname[], int expectedArrayLength)
{
  int actualArrayLength;
  int positionArray[80];
  createArray(positionFname, positionArray, actualArrayLength); 
  
  array = new int[actualArrayLength];
  
  for(int i = 0; i < actualArrayLength; i++)
    array[i] = positionArray[i];
  
  
  bool goodRange = rangeOk(array, actualArrayLength);
  if (!goodRange)
    {
      cout << "At least one of the input parameters for rotors starting positions is out of range." << endl;
      exit(INVALID_INDEX); 
    }

  if (actualArrayLength < expectedArrayLength)
   {
      cout << "Insufficient parameters for rotors starting positions." << endl;
      exit(NO_ROTOR_STARTING_POSITION);
    }

  if (actualArrayLength > expectedArrayLength)
    {
      cout << "Too many parameters for rotors starting positions." << endl;
      exit(1);
    }
};

int Position:: getStartPos(int rotorIndex)
{
  return array[rotorIndex];
};

Position::~Position()
{
  cout << "Position class has died" << endl;
  delete[] array;
}
