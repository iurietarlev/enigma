#include"rotClass.h"
using namespace std;


/* ====== CONSTRUCTOR & DESCTRUCTOR ====== */

Rotor::Rotor(const char *rotor_fname){
  int originalArray[1024];
  int actualArrayLength;
  
  err = createArray(rotor_fname, originalArray, actualArrayLength);

  if(err == ERROR_OPENING_CONFIGURATION_FILE)
    cerrCantOpenFile(rotor_fname);
  
  if(err == NON_NUMERIC_CHARACTER)
    {
      cerr << "Non-numeric character for mapping in rotor file "
	   << rotor_fname << endl;
    }
  
  if(err==0)
    {   
      if(actualArrayLength < 26)
	{
	  err = INVALID_ROTOR_MAPPING;
	  cerr << "Not all inputs mapped in rotor file: "
	       << rotor_fname << endl;
	}
      
      else if (!isInRange(originalArray, actualArrayLength))
	{
	  err = INVALID_INDEX;
	  cerr << "Out of range character in rotor file: " << rotor_fname
	       << endl;
	}
      
      else 
	{
	  
	  for(int i = 0; i < 26; i++)
	    {
	      rotorMap[i][1] = i; //values to be mapped
	      rotorMap[i][0] = originalArray[i]; //mappedValues
	    }

	  //check for duplicates
	  for(int i = 1; i < 26; i++)
	    for(int j = 0; j < i; j++)
	      if(rotorMap[i][0] == rotorMap[j][0])
		{
		  err = INVALID_ROTOR_MAPPING;
		  cerr << "Invalid mapping of input "
		       << rotorMap[i][1] << " to output "
		       << rotorMap[i][0] << " (output "
		       << rotorMap[i][0]
		       << " is already mapped to from input "
		       << rotorMap[j][1] << ") in rotor file: "
		       << rotor_fname << endl;
		  break;
		}
	}
      
      if(err == NO_ERROR)
	{
	  nrOfNotches = actualArrayLength - 26;
	  notchPos = new int[nrOfNotches];
	  
	  for(int i = 0; i < nrOfNotches; i++)
	    notchPos[i] = originalArray[26+i];
	}
    }
};


Rotor::~Rotor()
{
  if(err == NO_ERROR)
    delete[] notchPos;
}

/* =============== FUNCTIONS ================ */

void Rotor::setStartPos(int startPos)
{curtPos = startPos;}


void Rotor::mvPos()
{curtPos = mod26(curtPos+1);}

int Rotor::getCurtPos()
{return curtPos;}


bool Rotor::isCurtPosNotch()
{
  
  for(int i = 0 ; i < nrOfNotches; i++)
    if(curtPos == notchPos[i]) return true;
  
  return false;
}


void Rotor::encodeFwd(int &encLetter)
{
  for(int i = 0; i < 26; i++)
    if(rotorMap[i][1] == encLetter)
      {
	encLetter = rotorMap[i][0];
	break;
      }
}


void Rotor::encodeBwd(int &encLetter)
{
  for(int i = 0; i < 26; i++)
    if(rotorMap[i][0] == encLetter)
      {
	encLetter = rotorMap[i][1];
	break;
      }
}


int Rotor::getErr()
{return err;}
