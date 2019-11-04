#ifndef ROTOR_CLASS
#define ROTOR_CLASS
//
class Rotor
{
 public:
  Rotor(); 
  void initialize(int rotorNr, const char rotor_fname[]);
  void movePosition();
  void getPosition();
  ~Rotor();

private:
  int rotorNr;    
  int rotorMap[26];

  int nrOfNotches;
  int* notchArray; 
  int currentPosition;

  int expectedArrayLength;
};

#endif
