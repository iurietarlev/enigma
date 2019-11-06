#include<iostream>
#include"mainUtils.h"
#include"errors.h"
#include"rotClass.h"
#include"posClass.h"
#include"pbClass.h"
#include"rfClass.h"

#include<cctype> //isupper, isspace
#include<cstring>

using namespace std;





bool notchesAlignment(Rotor* rotor, int rotIndex){
    
    int rotWithAlignedNotches[rotIndex] = {0};
    
    for(int i = 1; i <= rotIndex; i++)
      {
	int curtPos = rotor[rotIndex-i].getCurtPos();
	int nrOfNotches = rotor[rotIndex-i].getNrOfNotches();
	for(int notchPosIndex = 0; notchPosIndex < nrOfNotches; notchPosIndex++)
	  {
	    if(curtPos == rotor[rotIndex-i].getNotchPos(notchPosIndex))
	      {
		rotWithAlignedNotches[rotIndex-i] = 1;
		break;
	      }
	  }
      }
    
    for(int i = 0; i < rotIndex; i++)
      if(rotWithAlignedNotches[i] != 1)
	return false;
    
    return true;
    
  }


int main(int argc, char** argv)
{

  //pb rf rot rot rot pos 
  
  // COMMAND LINE ARGS
  //plugboard
  Pb plugboard(argv[1]);

  //reflector
  Reflector reflector(argv[2]);
  
  //rotors
  int nrOfRotors = argc - 4;
  
  Rotor rotor[nrOfRotors]{};
  
  for(int i = 3; i < argc - 1; i++)
    rotor[i-3].initialize(i - 2, argv[i]);

  
  // position
  Position position(argv[argc-1], nrOfRotors);
  
  char inputString[80];
  
  cout << "Enter your message:" << endl;
  cin.getline(inputString, 80);
  //cout << inputString << endl;

  int encMsg[strlen(inputString)];
  int msgCount = 0;

  //check if the input is valid (put this in utils maybe?)
  int i = 0;
  char character;
  while(inputString[i] != '\0')
    {
      character = inputString[i];
      if(!isspace(character) && !isupper(character))
	{
	  cout << "Invalid input message, it must be capitals A-Z only."
	       << endl;
	  exit(INVALID_INPUT_CHARACTER);
	}
      
      if(isupper(character))
	{
	  //if isupper append message
	  encMsg[msgCount] = character - 'A';
	  msgCount++;
	}
      i++;
    }


  for(int i = 0; i < msgCount; i++)
    cout << encMsg[i] << " ";
  cout << endl;
  
  /*
  //PLUGBOARD OPERATION  
  pbOp(plugboard, encMsg, msgCount);

  for(int i = 0; i < msgCount; i++)
    cout << encMsg[i] << " ";
  cout << endl;
  */



  //ROTORS OPERATION
  /*
  if(nrOfRotors > 0)
    {
      for(int rotIndex = 0; rotIndex < nrOfRotors; rotIndex++)
	{
	  // set the starting position for one rotor
	  rotor[rotIndex].setStartPos(position.getStartPos(rotIndex));
	  
	  // map the values
	  for(int i = 0; i < msgCount; i++)
	    {
	      rotor[rotIndex].mvPos();
	      encMsg[i] = rotor[rotIndex].getCurtPosVal();	  
	    }

	  //check output after rotors operation
	  for(int i = 0; i < msgCount; i++)
	    cout << encMsg[i] << " ";
	  cout << endl;
	}
    }
  */

  //===============================================================
 
  if(nrOfRotors > 0)
    {
      for(int rotIndex = 0; rotIndex < nrOfRotors; rotIndex++)
	{
	  // set the starting position for one rotor
	  rotor[rotIndex].setStartPos(position.getStartPos(rotIndex));
	}
    
      for(int i = 0; i < msgCount; i++)
	{
	  int rotIndex = 0;
	  while(rotIndex < nrOfRotors)
	    {
	      if(rotIndex == 0)
		rotor[rotIndex].mvPos();
	      else
		{
		  if(notchesAlignment(rotor, rotIndex))
		    rotor[rotIndex].mvPos();
		}
	
	      encMsg[i] = rotor[rotIndex].getCurtPosVal();
	      rotIndex++;
	    }
	  cout << encMsg[i] << endl;
	}

    }
  
  //rfOp(reflector, encMsg, msgCount)

 
 //check output after rotors operation
 for(int i = 0; i < msgCount; i++)
   cout << encMsg[i] << " ";
 cout << endl;
 
 //============================================================= 
  
    //Rotor Rotors[3];
  //Rotors(1, "rotors/I.pos");

  //Rotor rotor[3]{};
  //Rotor rotor[3];

  //rotor[0].initialize(1, "rotors/letters.rot");

   
  /*
  for(int i = 0; i < 13; i++)
    {
      cout << plugboard.getIthInput(i) << endl;
      cout << plugboard.getIthOutput(i) << endl;
      
      cout << endl;
    }
   
    //Position two("rotors/letters.pos", 3);
    */
 
 return 0;
}

