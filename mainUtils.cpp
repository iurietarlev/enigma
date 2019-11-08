#include"pbClass.h"
#include"rfClass.h"
#include<iostream>

using namespace std;

// function to convert characters through the plugboard
void pbOp(Pb &pb, int* encMsg, const int msgLength)
{
  int* pbMap = pb.getMap();
  int pbLength = pb.getLength();

  for(int i = 0; i < msgLength; i++)
    for(int j = 0; j < pbLength; j++)
      {
	if (encMsg[i] == pbMap[j])
	  {
	    if(j%2 == 0)
	      {
		encMsg[i] = pbMap[j+1];
		break;
	      }
	    else
	      {
		encMsg[i] = pbMap[j-1];
		break;
	      }
	  }
      }
}

// function to convert characters through the plugboard
void rfOp(Reflector &pb, int& encMsg, const int msgLength)
{
  int* pbMap = pb.getMap();
  int pbLength = pb.getLength();

  std::cout << "PRINT THE PLUGBOARD" << endl;
  for(int j = 0; j < pbLength; j++)
    {
      cout << pbMap[j] << " " << endl;
      if (encMsg == pbMap[j])
	{
	  if(j%2 == 0)
	    {
	      encMsg = pbMap[j+1];
	      break;
	    }
	  else
	    {
	      encMsg = pbMap[j-1];
	      break;
	    }
	}
    }
  std::cout << "FINISH PRINT THE PLUGBOARD" << endl;
}
