#include"errors.h"
#include"rotClass.h"
#include<iostream>

#include"classUtils.h"

using namespace std;

Rotor::Rotor(const char *rotor_fname){
  int originalRotorArray[1024];
  int actualArrayLength;
  
  err = createArray(rotor_fname, originalRotorArray, actualArrayLength);
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
            
      else if (!isInRange(originalRotorArray, actualArrayLength))
	{
	  err = INVALID_INDEX;
	  cerr << "Out of range character in rotor file: " << rotor_fname
	       << endl;
	}

      else if (is_duplicate(originalRotorArray, 26))
	{
	  err = INVALID_ROTOR_MAPPING;
	  cerr << "Mapping in rotor file: " << rotor_fname
	       << " contains duplicates" << endl;
	}
      else
	{
	  err = NO_ERROR;
 
	  for(int i = 0; i < 26; i++)
	    {
	      rotorMap[i][1] = i; //values to be mapped
	      rotorMap[i][0] = originalRotorArray[i]; //mappedValues
	    }

	  
	  nrOfNotches = actualArrayLength - 26;
	  notchPos = new int[nrOfNotches];

	  for(int i = 0; i < nrOfNotches; i++)
	    {
	      notchPos[i] = originalRotorArray[26+i];
	      //cout <<  notchPos[i] << endl;
	    }
	}
    }
};


void Rotor::setStartPos(int startPos)
{
  curtPos = startPos; 
};


void Rotor::mvPos()
{
  //move current position (12 o'clock position)
  curtPos = mod26(curtPos+1);
};

int Rotor::getCurtPos()
{return curtPos;};

void Rotor::encodeFwd(int &encLetter)
{
  for(int i = 0; i < 26; i++)
    if(rotorMap[i][1] == encLetter)
      {
	encLetter = rotorMap[i][0];
	break;
      }
};

void Rotor::encodeBwd(int &encLetter)
{
  for(int i = 0; i < 26; i++)
    if(rotorMap[i][0] == encLetter)
      {
	encLetter = rotorMap[i][1];
	break;
      }
};

bool Rotor::isCurtPosNotch()
{
  
  for(int i = 0 ; i < nrOfNotches; i++)
    if(curtPos == notchPos[i])
      return true;
  return false;
}

//Rotor destructor
Rotor::~Rotor()
{
  if(err == NO_ERROR)
    delete[] notchPos;
};


int Rotor::getErr()
{return err;};
