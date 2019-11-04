#include<iostream>
#include"errors.h"
#include"rotClass.h"
#include"posClass.h"
#include"plgbrdClass.h"
#include"rfClass.h"
#include<cctype> //isupper, isspace
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{

  //pb rf rot rot rot pos 
  
  // COMMAND LINE ARGS
  //plugboard
  PlgBrd plugboard(argv[1]);

  //reflector
  Reflector reflector(argv[2]);
  
  //rotors
  int nrOfRotors = argc - 4;
  
  Rotor rotors[nrOfRotors]{};
  
  for(int i = 3; i < argc - 1; i++)
    rotors[i-3].initialize(i - 2, argv[i]);

  
  // position
  Position position(argv[argc-1], nrOfRotors);

  char inputString[80];
  
  cout << "Enter your message:" << endl;
  cin >> skipws;
  cin.getline(inputString, 80);

  cout << inputString << endl;

  int inputMessage[strlen(inputString)];
  int messageCount = 0;

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
	  inputMessage[messageCount] = character - 'A';
	  messageCount++;
	}
      i++;
    }


  for(int i = 0; i < messageCount; i++)
    cout << inputMessage[i] << " ";
  cout << endl;
  

  //PLUGBOARD OPERATION
  int pbLength = plugboard.getPlgBrdLength();

  for(int i = 0; i < messageCount; i++)
    for(int j = 0; j < pbLength; j++)
      {
	if(plugboard.getIthInput(j) == inputMessage[i])
	  inputMessage[i] = plugboard.getIthOutput(j);
      }

  for(int i = 0; i < messageCount; i++)
    cout << inputMessage[i] << " ";
  cout << endl;
  
  
  
  //Rotor rotors[3];
  //rotors(1, "rotors/I.pos");

  //Rotor rotors[3]{};
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

