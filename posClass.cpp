#include"errors.h"
#include"utils.h"
#include"posClass.h"
#include<iostream>

using namespace std;

Position::Position(const char positionFname[], int expectedArrayLength)
{
  int actualArrayLength;
  createArray(positionFname, positionArray, actualArrayLength); 

  bool goodRange = rangeOk(positionArray, actualArrayLength);
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
