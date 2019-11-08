#include<iostream>
#include"mainUtils.h"
#include"classUtils.h" 
#include"errors.h"
#include"rotClass.h"
#include"posClass.h"
#include"pbClass.h"
#include"rfClass.h"


#include<cctype> //isupper, isspace
#include<cstring>

using namespace std;


bool notchesAlignment(Rotor* rotor, int rotIndex){
  if(rotIndex == 0)
    return true;
   
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
	  cout << character << "is not a valid input character (input characters must be upper case letters A-Z)!" << endl;
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
  

  //PLUGBOARD OPERATION  
  pbOp(plugboard, encMsg, msgCount);

  for(int i = 0; i < msgCount; i++)
    cout << encMsg[i] << " ";
  cout << endl;


  cout << "PRINT THE PLUGBOARD" << endl;
  int* pbMap = plugboard.getMap();
  int pbLength = plugboard.getLength();

  for(int i = 0; i < pbLength; i++)
    cout << pbMap[i] << " " << endl;
  cout << "FINISH PRINT THE PLUGBOARD" << endl;

  cout << "PRINT THE REFLECTOR" << endl;
  int* rfMap = reflector.getMap();
  int rfLength = reflector.getLength();

  for(int i = 0; i < rfLength; i++)
    cout << rfMap[i] << " " << endl;
  cout << "FINISH PRINT THE REFLECTOR" << endl;
  
    
  //set starting position for all the rotors
  for(int rotIndex = 0; rotIndex < nrOfRotors; rotIndex++)
    rotor[rotIndex].setStartPos(position.getStartPos(rotIndex));

  cout << "PRINTING THE ROTOR ARRAY" << endl;
  for(int i= 0; i < 26; i++)
    {
      for(int j = 0; j < 4; j++)
	cout << rotor[0].rotorMap[i][j] << " ";
      cout << endl;
    }
  cout << "FINISHED PRINTING THE ROTOR ARRAY" << endl;
  
  
  // ROTORS OPERATION 
  for(int i = 0; i < msgCount; i++)
    {
      if(nrOfRotors > 0)
	{
	//rotors forwards
	for(int rotIndex = 0; rotIndex < nrOfRotors; rotIndex++)
	  {
	    if(notchesAlignment(rotor, rotIndex))
	      {
		//move by one position
		rotor[rotIndex].mvPos();
	      
		//get the absolute value on the other end
	      
	      }
	    encMsg[i] = rotor[rotIndex].getLeftMostVal(encMsg[i]);
	  }
	}

      for(int i = 0; i < msgCount; i++)
	{
	  char c = encMsg[i] + 'A';
	  cout << c << " ";
	}
      cout << endl;  
  

      
      //reflector
      rfOp(reflector, encMsg[i], msgCount);


      for(int i = 0; i < msgCount; i++)
	{
	  char c = encMsg[i] + 'A';
	  cout << c << " ";
	}
      cout << endl;  



      if(nrOfRotors > 0)
	{
	  //rotors path backwards
	  for(int rotIndex = nrOfRotors - 1; rotIndex >= 0; rotIndex--)
	    {
	      encMsg[i] = rotor[rotIndex].getRightMostVal(encMsg[i]);
	    }
	}


      for(int i = 0; i < msgCount; i++)
	{
	  char c = encMsg[i] + 'A';
	  cout << c << " ";
	}
      cout << endl;  

      
    }

  //go through plugboard backwards
  pbOp(plugboard, encMsg, msgCount);

  

  
  cout << "PRINTING THE ROTOR ARRAY" << endl;
  for(int i= 0; i < 26; i++)
    {
      for(int j = 0; j < 4; j++)
	cout << rotor[0].rotorMap[i][j] << " ";
      cout << endl;
    }
  cout << "FINISHED PRINTING THE ROTOR ARRAY" << endl;
  
  

  for(int i = 0; i < msgCount; i++)
    {
      char c = encMsg[i] + 'A';
      cout << c << " ";
    }
  cout << endl;  


  
 return 0;
}

