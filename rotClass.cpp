#include"errors.h"
#include"rotClass.h"
#include<iostream>

#include"classUtils.h"

using namespace std;

Rotor::Rotor(){
  //default dynamic memory allocation
  notchPos = new int[1];
};

void Rotor::initialize(int rotorNr, const char rotor_fname[])
{
  this->rotorNr = rotorNr;

  //create an array with all inputs from the relevant file
  //this will also check for any non_numeric chars
  int originalRotorArray[80];
  int actualArrayLength;
  createArray(rotor_fname, originalRotorArray, actualArrayLength); 
  
  //check rotor for correct length, duplicates and out of range values
  bool goodRange = rangeOk(originalRotorArray, actualArrayLength);

  if (!goodRange)
    {
      cout << "At least one of the input numbers for rotor number " \
	   << rotorNr << " is out of range." << endl;
      exit(INVALID_INDEX);
    } 

  cout << "ActualArrayLength = " << actualArrayLength << endl;
  
  if(actualArrayLength < 27)
    {
      cout << "The number of input numbers in rotor number " \
	   << rotorNr << " is of insufficient length." << endl;
      exit(INVALID_ROTOR_MAPPING);
    }
 
  //assign first 26 values from the rotorArray into the rotorMap
  for(int i = 0; i < 26; i++)
    {
      rotorMap[i][2] = i; //values to be mapped
      rotorMap[i][1] = originalRotorArray[i]; //mappedValues
      
      //abs pos of mapped vals //assuming starting position of 0
      rotorMap[i][3] = i;
      rotorMap[i][0] = rotorMap[i][1] - rotorMap[0][2];
      
    }
      

  
  //check for duplicates
  bool duplicate = duplicates2d(rotorMap, 26);

  if (duplicate)
    {
      cout << "One of the inputs in the rotor " << rotorNr << " is a duplicate."  << endl;
      exit(INVALID_ROTOR_MAPPING);
    }

  nrOfNotches = actualArrayLength - 26;

  //overwrite default notch array with the actual number of notches
  notchPos = new int[nrOfNotches];

  cout << "Number of Notches = " << nrOfNotches << endl;
  cout << "26th index of originalRotorArray = " << originalRotorArray[26] << endl;
  for(int i = 0; i < nrOfNotches; i++)
    {
      notchPos[i] = originalRotorArray[26+i];
      cout <<  notchPos[i] << endl;
    }
};


int Rotor::getStartPos(int rotIndex)
{
  return startPos;
};


void Rotor::setStartPos(int startPos)
{
  curtPos = startPos;
  //curtPosVal = rotorMap[startPos][1];
  this->startPos = startPos;

  //find index of row including startPos
  int startPosRow;
  for(int j = 0; j < 26; j++)
    if (rotorMap[j][2] == startPos)
      {
	startPosRow = j;
	break;
      }
      
  //set absolute pos for values to be mapped
  for(int i = 0; i < 26; i++)
    rotorMap[mod((startPosRow+i),26)][3] = i;

  /*
    if ((startPosRow+i)%26 != (startPosRow+i))
      rotorMap[(startPosRow+i)%26][3] = i;
    else
      rotorMap[startPosRow+i][3] = i;
    */
  
 //set absolute pos values for mapped vals
  for (int i = 0; i < 26; i++)
    rotorMap[i][0] = mod(rotorMap[i][1] - startPos,26); 
};

void Rotor::mvPos()
{
  //set the leftmost values (absolute positions)
  for(int i = 0; i < 26; i++)
    rotorMap[i][3] = mod(rotorMap[i][3]-1,26);
    
  //move current position (12 o'clock position)
  curtPos++;
  if(curtPos > 25)
    curtPos = 0;
  
  //set absolute pos values for mapped vals
  for (int i = 0; i < 26; i++)
    rotorMap[i][0] = mod(rotorMap[i][1] - curtPos,26); 
  
  curtPosVal = rotorMap[curtPos][1]; 
};

int Rotor::getCurtPos()
{return curtPos;};


int Rotor::getCurtPosVal()
{return curtPosVal;};


int Rotor::getNrOfNotches()
{return nrOfNotches;}


int Rotor::getNotchPos(int i)
{
  return notchPos[i];
}

int Rotor::getPosOfVal(int val)
{
  for(int i = 0; i < 26; i++)
    if(val == rotorMap[i][1])
      return i;
  return -1;
}

int Rotor::getLeftMostVal(int rightMostVal)
{
  for(int i = 0; i < 26; i++)
    if(rotorMap[i][3] == rightMostVal)
      return rotorMap[i][0];
  
  cout << "ERROR in getLeftMostVal" << endl;
  exit(5);
}


int Rotor::getRightMostVal(int leftMostVal)
{
  for(int i = 0; i < 26; i++)
    if(rotorMap[i][0] == leftMostVal)
      return rotorMap[i][3];
  
  cout << "ERROR in getRightMostVal" << endl;
  exit(5);
}




//Rotor destructor
Rotor::~Rotor(){
  delete[] notchPos;
  cout << "Notch Array has died" << endl;
};
