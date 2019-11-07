#ifndef ROTOR_CLASS
#define ROTOR_CLASS

class Rotor
{
 public:
  Rotor(); 
  void initialize(int rotorNr, const char rotor_fname[]);
  void setStartPos(int startPos);
  int getStartPos(int rotIndex);
  void mvPos();
  int getCurtPos();
  int getCurtPosVal();
  int getNotchPos(int i);
  int getNrOfNotches();
  int getPosOfVal(int val);
  ~Rotor();
  int rotorMap[26][4];

  int getLeftMostVal(int rightMostVal);
  int getRightMostVal(int leftMostVal);

 private:
  int rotorNr;    
  //  int rotorMap[26][4];

  int nrOfNotches;
  int* notchPos; 
  int startPos;
  int curtPos;
  int curtPosVal;
  

  int expectedArrayLength;
};

#endif
