#include<iostream>
#include"errors.h"
#include"utils.h"
#include"rfClass.h"

using namespace std;

/* ============== PLUGBOARD CONSTRUCTOR ============== */
Reflector::Reflector(const char* rfFname)
{
  int originalArray[80];
  int originalArrayLength;
  createArray(rfFname, originalArray, originalArrayLength);


  // check if length is exactly 26
  if (originalArrayLength != 26)
    {
      cout << "There needs to be exactly 13 pairs of numbers for the reflector."
	   << endl;
      exit(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
    }

  //check if the values are within the range (0 to 25)
  bool goodRange = rangeOk(originalArray, originalArrayLength);
  if (!goodRange)
    {
      cout << "At least one of the input numbers for the reflector is out of range." << endl;
      exit(INVALID_INDEX); 
    }
  
  //check for duplicates
  bool duplicate = duplicates(originalArray, originalArrayLength);
  if (duplicate)
    {
      cout << "One of the inputs of reflector seems to be mapped to itself or mapped twice."  << endl;
      exit(INVALID_REFLECTOR_MAPPING);
    }

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
  

/* ============== GET THE ITH ELEMENT IN THE INPUT ARRAY ============== */
int Reflector::getIthInput(int i)
{
  return input[i];
};

/* ============== GET THE ITH ELEMENT IN THE OUTPUT ARRAY ============== */
int Reflector::getIthOutput(int i)
{
  return output[i];
};
