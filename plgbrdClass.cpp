#include<iostream>
#include"errors.h"
#include"utils.h"
#include"plgbrdClass.h"

using namespace std;

/* ============== PLUGBOARD CONSTRUCTOR ============== */
PlgBrd::PlgBrd(const char* plgBrdFname)
{
  int originalArray[80];
  int originalArrayLength;
  createArray(plgBrdFname, originalArray, originalArrayLength);


  // if length is 
  if (originalArrayLength > 26)
    {
      cout << "There can only be a maximum of 13 pairs of numbers for plugboard."
	   << endl;
      exit(IMPOSSIBLE_PLUGBOARD_CONFIGURATION);
    }
  
  bool goodRange = rangeOk(originalArray, originalArrayLength);
  if (!goodRange)
    {
      cout << "At least one of the input parameters for plugboard mapping is out of range." << endl;
      exit(INVALID_INDEX); 
    }
  
  //check for duplicates
  bool duplicate = duplicates(originalArray, originalArrayLength);
  if (duplicate)
    {
      cout << "One of the inputs in plugboard seems to be mapped to itself or mapped twice."  << endl;
      exit(IMPOSSIBLE_PLUGBOARD_CONFIGURATION);
    }

  // check for odd number of numbers
  if (originalArrayLength%2 != 0)
    {
      cout << "Incorrect number of plugboard parameters" << endl;
      exit(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);
    }

  //length of input array and output array
  arrayLength = originalArrayLength/2;


  input[0] = originalArray[0];
  output[0] = originalArray[1];

  int countEven = 1;
  int countOdd = 1;
  for(int i = 2; i<originalArrayLength; i++)
    {
      if(i%2 == 0)
	{
	  input[countEven] = originalArray[i];
	  countEven++;
	}
      else
	{
	  output[countOdd] = originalArray[i];
	  countOdd++;
	}
    }
};
  

/* ============== GET NR OF VALUES TO BE MAPPED ============== */
int PlgBrd::getPlgBrdLength()
{
  return arrayLength;
};

/* ============== GET THE ITH ELEMENT IN THE INPUT ARRAY ============== */
int PlgBrd::getIthInput(int i)
{
  return input[i];
};

/* ============== GET THE ITH ELEMENT IN THE OUTPUT ARRAY ============== */
int PlgBrd::getIthOutput(int i)
{
  return output[i];
};
