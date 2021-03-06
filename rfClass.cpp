#include"rfClass.h"
using namespace std;

/* ============ CONSTRUCTOR ============== */
Reflector::Reflector(const char* rfFname)
{
  int originalArray[1024];
  int originalArrayLength;
  
  err = createArray(rfFname, originalArray, originalArrayLength);
  
  if(err == ERROR_OPENING_CONFIGURATION_FILE)
    cerrCantOpenFile(rfFname);  
  
  if(err == NON_NUMERIC_CHARACTER)
    {
      cerr << "Non-numeric character in reflector file "
	   << rfFname << endl;
    }  

  if(err == NO_ERROR)
    {
      if(!isInRange(originalArray, originalArrayLength))
	{
	  err = INVALID_INDEX;
	  cerr << "Out of range character in reflector file: "
	       << rfFname << endl;
	}

      else if (originalArrayLength < 26 && originalArrayLength%2 != 0)
	{
	  err = INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
	  cerr << "Incorrect (odd) number of parameters "
	       << "in reflector file " << rfFname << endl;
	}

      else if (originalArrayLength < 26 && originalArrayLength%2 == 0)
	{
	  err = INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
	  cerr << "Insufficient number of mappings "
	       << "in reflector file: " << rfFname << endl;
	}      
      
      else if (originalArrayLength != 26)
	{
	  err = INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
	  cerr << "Incorrect (odd) number of parameters "
	       << "in reflector file " << rfFname << endl;
	}
      
      else if(is_duplicate(originalArray, originalArrayLength))
	{
	  err = INVALID_REFLECTOR_MAPPING;
	  cerr << "Mapping in rotor file: " << rfFname
	       << "contains duplicates" << endl;
	}
      
      else
	{
	  err = NO_ERROR;
	  for(int i = 0; i < originalArrayLength; i++)
	    rfMap[i] = originalArray[i];
	}
    } 
};

/* =============== FUNCTIONS ================ */
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
 
