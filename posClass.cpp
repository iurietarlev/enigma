#include"posClass.h"
using namespace std;

/* ====== CONSTRUCTOR & DESCTRUCTOR ====== */
Position::Position(const char positionFname[], int expectedArrayLength)
{
  int actualArrayLength;
  int positionArray[1024];

  err = createArray(positionFname, positionArray, actualArrayLength); 

  
  if(err == ERROR_OPENING_CONFIGURATION_FILE)
    cerrCantOpenFile(positionFname);
  
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
	  cerr << "Out of range character in rotor position file "
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
}


Position::~Position()
{
  if(err == NO_ERROR)
    delete[] array;
}

/* =============== FUNCTIONS ================ */
int Position:: getStartPos(int rotorIndex)
{return array[rotorIndex];}

int Position:: getErr()
{return err;};
