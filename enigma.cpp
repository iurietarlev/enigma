#include"enigma.h"
using namespace std;

/* ====== CONSTRUCTOR & DESCTRUCTOR ====== */
Enigma::Enigma(int argc, char** argv)
{
  pb = NULL;
  rf = NULL;
  pos = NULL;
  
  nrOfRotors = argc-4; 
  if(nrOfRotors < 1)
    rot = new Rotor*[1];
  else
    rot = new Rotor*[nrOfRotors];
 
  err = NO_ERROR;
  if(argc < 4)
    {
      err = INSUFFICIENT_NUMBER_OF_PARAMETERS;
      cerr << "usage: enigma plugboard-file reflector-file (<rotor-file>)* rotor-positions"
	   << endl;
    }
  
  //PLUGBOARD
  if(err == NO_ERROR)
    {
      pb = new Plugboard(argv[1]);
      err = pb->getErr(); 
    }
  
  //REFLECTOR
  if(err == NO_ERROR)
    {
      rf = new Reflector(argv[2]);
      err = rf->getErr();
    }

  
  //ROTORS
  if(err == NO_ERROR && nrOfRotors > 0)
    {
      nrOfRotors = argc-4;

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

Enigma::~Enigma(){
  delete pb;
  delete rf;
  delete pos;

  if(nrOfRotors > 0)
    {
      for(int i = 0; i < nrOfRotors; i++)
	delete rot[i];
    }
  delete[] rot;
};


/* =============== FUNCTIONS ================ */
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

int Enigma::getErr()
{return err;}

   
    
	  
  

 
 
