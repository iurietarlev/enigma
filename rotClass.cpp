#include"errors.h"
#include"rotClass.h"
#include<iostream>

#include"classUtils.h"

using namespace std;

Rotor::Rotor(const char *rotor_fname){
  int originalRotorArray[1024];
  int actualArrayLength;
  
  err = createArray(rotor_fname, originalRotorArray, actualArrayLength); 
  if(err==0)
    {
      if(actualArrayLength < 27)
	err = INVALID_ROTOR_MAPPING;
      
      else if (!isInRange(originalRotorArray, actualArrayLength))
	err = INVALID_INDEX;

      else if (is_duplicate(originalRotorArray, 26))
	err = INVALID_ROTOR_MAPPING;
      else
	{
	  err = NO_ERROR;
 

	  //assign first 26 values from the rotorArray into the rotorMap
	  for(int i = 0; i < 26; i++)
	    {
	      rotorMap[i][1] = i; //values to be mapped
	      rotorMap[i][0] = originalRotorArray[i]; //mappedValues
	    }

	  
	  nrOfNotches = actualArrayLength - 26;

	  //overwrite default notch array with the actual number of notches
	  notchPos = new int[nrOfNotches];

	  //cout << "Number of Notches = " << nrOfNotches << endl;
	  //cout << "26th index of originalRotorArray = " << originalRotorArray[26] << endl;
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
  if(err == 0)
    delete[] notchPos;
};


int Rotor::getErr()
{return err;};
