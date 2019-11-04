#include<iostream>
#include"rotClass.h"
#include"posClass.h"
#include"plgbrdClass.h"
#include"rfClass.h"

using namespace std;

int main(int argc, char** argv)
{
  //cout << argc << endl;
  //cout << argv[0] << endl;

  
  //  for(int i = 1; i < strlen(argv) - 1; i++)
    

  //Rotor rotors[3]{};
  //Rotor rotor[3];

  //rotor[0].initialize(1, "rotors/letters.rot");

 
  
  Reflector plugboard("plugboards/test.pb");


  
  
  for(int i = 0; i < 13; i++)
    {
      cout << plugboard.getIthInput(i) << endl;
      cout << plugboard.getIthOutput(i) << endl;
      
      cout << endl;
    }
   
    //Position two("rotors/letters.pos", 3);
    
  return 0;
}

