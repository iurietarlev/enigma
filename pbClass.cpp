#include<iostream>
#include"errors.h"
#include"classUtils.h"
#include"pbClass.h"

using namespace std;

/* ============== PLUGBOARD CONSTRUCTOR ============== */
Plugboard::Plugboard(const char* pbFname)
{
  int originalArray[1024];

  err = NO_ERROR;
  err = createArray(pbFname, originalArray, arrayLength);

  if(err == NON_NUMERIC_CHARACTER)
    {
      cerr << "Non-numeric character in plugboard file "
	   << pbFname << endl;
    }
  
  if(err == NO_ERROR){
    if(!isInRange(originalArray, arrayLength))
      {
	err = INVALID_INDEX;
	cerr << "Out of range Character in plugboard file " << pbFname
	     << endl;
      }
    else if (arrayLength%2 != 0 || arrayLength > 26)
      {
	err = INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
	cerr << "Incorrect number of parameters in plugboard file "
	     << pbFname << endl;
      }
    else if(is_duplicate(originalArray, arrayLength))
      {
	err = IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
	cerr << "Mapping in plugboard file: " << pbFname
	     << "contains duplicates" << endl;
		  
      }
    else
      {
	err = NO_ERROR;
      
	pbMap = new int[arrayLength]; 

	for(int i = 0; i < arrayLength; i++)
	  pbMap[i] = originalArray[i];
      }
  }
};


/* ============== GET NR OF VALUES TO BE MAPPED ============== */
int Plugboard::getErr()
{
  return err;
};
  

void Plugboard::encode(int& encLetter)
{
  for(int j = 0; j < arrayLength; j++)
    if (encLetter == pbMap[j])
      {
	if(j%2 == 0)
	  {
	    encLetter = pbMap[j+1];
	    break;
	  }
	else
	  {
	    encLetter = pbMap[j-1];
	    break;
	  }
      }
}


Plugboard::~Plugboard(){
  if(err == NO_ERROR)
    delete[] pbMap;
  //cout << "Plugboard has died" << endl;
}
