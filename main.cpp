/* This program is designed to take user's input
   in capital alphabetic format and encrypt it using 
   the enigma machine, invented in Europe during WWII.
   The machine consists of a plugboard, reflector
   and rotors. This program is designed to take in
   command line arguments for plugboard, reflector, 
   rotors and initital position in the order that 
   they are specified. */

//Author: Iurie Tarlev

#include<iostream>
#include"enigma.h" 
#include"errors.h"
#include<cctype> //isupper, isspace
#include<cstring>//strlen

using namespace std;

int main(int argc, char** argv)
{
  Enigma enigma(argc, argv);
  int err = enigma.getErr();
  
  switch(err)
    {
    case(INSUFFICIENT_NUMBER_OF_PARAMETERS):
      return INSUFFICIENT_NUMBER_OF_PARAMETERS;
      break;
    case(INVALID_INDEX):
      return INVALID_INDEX;
      break;
    case(NON_NUMERIC_CHARACTER):
      return NON_NUMERIC_CHARACTER;
      break;
    case(IMPOSSIBLE_PLUGBOARD_CONFIGURATION):
      return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
      break;
    case(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS):
      return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
      break;
    case(INVALID_ROTOR_MAPPING):
      return INVALID_ROTOR_MAPPING;
      break;
    case(NO_ROTOR_STARTING_POSITION):
      return NO_ROTOR_STARTING_POSITION;
      break;
    case(INVALID_REFLECTOR_MAPPING):
      return INVALID_REFLECTOR_MAPPING;
      break;
    case(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS):
      return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
      break;
    case(ERROR_OPENING_CONFIGURATION_FILE):
      return ERROR_OPENING_CONFIGURATION_FILE;
    default:
      break; 
    }
  
  char msg[512];
  
  cin.getline(msg, 512);
  
  char encMsg[strlen(msg)];
  
  int msgCount = 0;
  int i = 0;
  while(msg[i] != '\0')
    {
      if(!isspace(msg[i]) && !isupper(msg[i]))
	{
	  cerr << msg[i] << " is not a valid input "
	       << "character (input characters must "
	       << "be upper case letters A-Z)!" << endl;
	  return INVALID_INPUT_CHARACTER;
	}
      
      if(isupper(msg[i]))
	{
	  encMsg[msgCount] = msg[i];
	  enigma.encrypt(encMsg[msgCount]);   
	  cout << encMsg[msgCount];  
	  msgCount++;   
	}
      i++;
    }
  
  return NO_ERROR;
}

