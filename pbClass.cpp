#include"pbClass.h"
using namespace std;

/* ====== CONSTRUCTOR & DESCTRUCTOR ====== */
Plugboard::Plugboard(const char* pbFname)
{
  int originalArray[1024];
  
  err = NO_ERROR;
  err = createArray(pbFname, originalArray, arrayLength);

  
  if(err == ERROR_OPENING_CONFIGURATION_FILE)
    cerrCantOpenFile(pbFname);
  
  if(err == NON_NUMERIC_CHARACTER)
    {
      cerr << "Non-numeric character in plugboard file "
	   << pbFname << endl;
    }
  
  if(err == NO_ERROR){
    if(!isInRange(originalArray, arrayLength))
      {
	err = INVALID_INDEX;
	cerr << "Out of range character in plugboard file "
	     << pbFname << endl;
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
	pbMap = new int[arrayLength]; 
	
	for(int i = 0; i < arrayLength; i++)
	  pbMap[i] = originalArray[i];
      }
  }
}


Plugboard::~Plugboard()
{
  if(err == NO_ERROR)
    delete[] pbMap;
}


/* =============== FUNCTIONS ================ */
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

int Plugboard::getErr()
{return err;}

