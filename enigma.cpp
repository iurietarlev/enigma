#include"enigma.h"

Enigma::Enigma(int argc, char** argv)
{
  err = NO_ERROR;
  if(argc < 4)
    err = INSUFFICIENT_NUMBER_OF_PARAMETERS;
  
  //set nr of rotors
  nrOfRotors = argc-4;
  
  //PLUGBOARD
  pb = new Plugboard(argv[1]);
  err = pb->getErr();
  
  //REFLECTOR
  if(err == NO_ERROR)
    {
      rf = new Reflector(argv[2]);
      err = rf->getErr();
    }
  
  //ROTORS
  if(err == NO_ERROR)
    {
      nrOfRotors = argc-4;
      rot = new Rotor*[nrOfRotors];
      for(int i = 3; i < argc - 1; i++)
	{
	  rot[i-3] = new Rotor(argv[i]);
	  err = rot[i-3]->getErr();
	  if(err != NO_ERROR)
	    break;
	}
    }

  //ROTORS STARTING POSITIONS
  if(err == NO_ERROR)
    {
      pos = new Position(argv[argc-1], nrOfRotors);
      err = pos->getErr();
    }

  //SET ROTOR STARTING POSITIONS
  if(err == NO_ERROR)
    for(int rotIndex = 0; rotIndex < nrOfRotors; rotIndex++)
      rot[rotIndex]->setStartPos(pos->getStartPos(rotIndex));
}

void Enigma::encrypt(char& letter)
{
  int encLetter = letter - 'A';

  pb->encode(encLetter);

  if(nrOfRotors > 0)
    {
      rotateRotors();
      for(int rotIndex = nrOfRotors - 1; rotIndex >= 0; rotIndex--)
	{
	  encLetter = mod26(encLetter + rot[rotIndex]->getCurtPos());
	  rot[rotIndex]->encodeFwd(encLetter);
	  encLetter = mod26(encLetter - rot[rotIndex]->getCurtPos());

	}
    }
  
  rf->encode(encLetter);
  
  if(nrOfRotors > 0)
    {
      for(int rotIndex = 0; rotIndex < nrOfRotors; rotIndex++)
	{
	  encLetter = mod26(encLetter + rot[rotIndex]->getCurtPos());
	  rot[rotIndex]->encodeBwd(encLetter);
	  encLetter = mod26(encLetter - rot[rotIndex]->getCurtPos());
	}
    }

  pb->encode(encLetter);
  
  letter = encLetter + 'A';
}
  
void Enigma::rotateRotors()
{
  rot[nrOfRotors-1]->mvPos();
  
  if(nrOfRotors > 1)
    {
      bool notchesalign = true ;
      for(int rotIndex = nrOfRotors - 2; rotIndex >= 0; rotIndex--)
	{
	  for(int i = rotIndex + 1; i < nrOfRotors; i++)
	    if(!rot[i]->isCurtPosNotch())
	      {
		notchesalign = false;
		break;
	      }
	  if(notchesalign)
	    rot[rotIndex]->mvPos(); 
	}
    }
}

int Enigma::getErr()
{return err;}


Enigma::~Enigma(){
  delete pb;
  delete rf;
  delete pos;

  if(nrOfRotors > 0)
    for(int i = 0; i < nrOfRotors; i++)
      delete rot[i];
  
  delete rot;
};
   
    
	  
  

 
 
