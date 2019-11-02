#include<iostream>
#include"rotor_class.h"

using namespace std;

int main(int argc, char** argv)
{
  cout << argc << endl;
  cout << argv[0] << endl;


  //for(int i = 1; i < strlen(argv) - 1;

  
  Rotor one(2, "rotors/shift_up.rot", "234");


  one.getPosition();
  one.movePosition();

  one.rotorSetup();
  return 0;
}

