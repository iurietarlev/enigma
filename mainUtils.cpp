#include"plgbrdClass.h"

// function to convert characters through the plugboard
void pbOp(PlgBrd &pb, int* encMsg, const int msgLength)
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
