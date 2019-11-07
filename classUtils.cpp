#include"errors.h"
#include"classUtils.h"
#include<cctype> //std::isdigit
#include<iostream>
#include<fstream>

using namespace std;


// mod of negative numbers
int mod(int x, int n)
{
  return (x%n + n)%n;
};



bool rangeOk(int* array, int arrayLength)
{
  for(int i = 0; i < arrayLength; i++)
    if(array[i] < 0 || array[i] > 25)
      return false;
  return true;
};

bool lengthOk(int actualArrayLength, int expectedArrayLength)
{
  if (actualArrayLength != expectedArrayLength)
    return false;
  return true;
} 

bool duplicates(int* array, int arrayLength)
{
  for(int i = 1; i < arrayLength; i++)
    for(int j = 0; j < i; j++)
      if(array[i] == array[j])
	return true;
  return false;
}

bool duplicates2d(int array[26][4], int arrayLength)
{
  for(int i = 1; i < arrayLength; i++)
    for(int j = 0; j < i; j++)
      if(array[i][1] == array[j][1])
	return true;
  return false;
}


//Arrays55
void createArray(const char* filename, int* array, int& actualArrayLength)
{

  ifstream file (filename);
  if (file.fail())
    { 
      cout << "File \" " << filename << " \" couldn't be open." << endl;
      exit(ERROR_OPENING_CONFIGURATION_FILE);
    }
  
  file >> ws; // eat up any leading white spaces
  int temp;
  int i = 0;

  char peek = file.peek();

  //read integers until reach eof or 80 integers
  while(!file.eof() || i < 80)
    {
      if (!isdigit(peek))
	{
	  if(peek != -1) //exit if non-char
	    {
	      cout <<"File " << filename
		   << " contains a non-numeric character" << endl;
	      exit(NON_NUMERIC_CHARACTER);
	    }
	  break;
	}
      
      file >> temp; // store the number in temp variable
      file >> ws; // eat up any leading white sp
      array[i] = temp;
      
      cout << array[i] << " - " << i;
      cout << endl;
      peek = file.peek();
      i++;
    }
  actualArrayLength = i;

  cout << " ==================== " << endl;
  
  file.close();
}

