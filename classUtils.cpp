#include"classUtils.h"
using namespace std;

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
  
  //read integers until reach eof
  while(!inStream.eof() || i >= 1024)
    {
      if (!isdigit(peek))
	return NON_NUMERIC_CHARACTER;
      
      inStream >> temp; // store number in temp var
      inStream >> ws; // eat up any leading white sp
      array[i] = temp;
      
      peek = inStream.peek();
      i++;
    }
  
  //store array length
  arrayLength = i;
  
  inStream.close();
  return NO_ERROR;
}

void cerrCantOpenFile(const char* fname)
{
  cerr << "Positions file: \"" << fname
       << "\" can't be open "
       << "(possible cause may be that "
       << "a file with this name doesn't exist)."
       << endl;
}
