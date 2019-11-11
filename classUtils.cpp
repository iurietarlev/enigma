#include"errors.h"
#include"classUtils.h"
#include<cctype> //std::isdigit
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// mod of +ve and -ve numbers
int mod26(int n)
{return (n%26 + 26)%26;}

//Check if is in range 0 =< x <=25 
bool isInRange(int* array, int arrayLength)
{
  for(int i = 0; i < arrayLength; i++)
    if(array[i] < 0 || array[i] > 25)
      return false;
  return true;
};

//Check if duplicates present
bool is_duplicate(int* array, int arrayLength)
{
  for(int i = 1; i < arrayLength; i++)
    for(int j = 0; j < i; j++)
      if(array[i] == array[j])
	return true;
  return false;
}

//Create Array
int createArray(const char* filename, int* array, int& arrayLength)
{
  ifstream inStream (filename);
  if (inStream.fail())
    return ERROR_OPENING_CONFIGURATION_FILE;
  
  inStream >> ws; // eat up any leading white spaces
  int temp;
  int i = 0;
  char peek = inStream.peek();
  
  //read integers until reach eof or 80 integers
  while(!inStream.eof())
    {
      if (!isdigit(peek))
	return NON_NUMERIC_CHARACTER;
      
      inStream >> temp; // store the number in temp variable
      inStream >> ws; // eat up any leading white sp
      array[i] = temp;
      
      // cout << array[i] << " - " << i;
      // cout << endl;
      peek = inStream.peek();
      i++;
    }
  arrayLength = i;
  
  inStream.close();
  return NO_ERROR;
}

