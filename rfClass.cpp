#include<iostream>
#include"errors.h"
#include"classUtils.h"
#include"rfClass.h"

using namespace std;

/* ============== PLUGBOARD CONSTRUCTOR ============== */
Reflector::Reflector(const char* rfFname)
{
  int originalArray[1024];
  int originalArrayLength;
  
  err = NO_ERROR; //start with NO_ERROR
  err = createArray(rfFname, originalArray, originalArrayLength);
  
  // check if length is exactly 26
  if(err == NO_ERROR)
    {
      if (originalArrayLength != 26)
	err = INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
      
      else if(!isInRange(originalArray, originalArrayLength))
	err = INVALID_INDEX; 
      
      else if(is_duplicate(originalArray, originalArrayLength))
	err = INVALID_REFLECTOR_MAPPING;

      else
	{
	  err = NO_ERROR;
	  for(int i = 0; i < originalArrayLength; i++)
	    rfMap[i] = originalArray[i];
	}
    } 
};
 
void Reflector::encode(int& encLetter)
{
  for(int j = 0; j < arrayLength; j++)
    if (encLetter == rfMap[j])
      {
	if(j%2 == 0)
	  {
	    encLetter = rfMap[j+1];
	    break;
	  }
	else
	  {
	    encLetter = rfMap[j-1];
	    break;
	  }
      }
}

int Reflector::getErr()
{
  return err;
};
