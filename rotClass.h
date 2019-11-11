#ifndef ROTOR_CLASS
#define ROTOR_CLASS

class Rotor
{
 public:
  Rotor(const char *rotor_fname); 
  ~Rotor();
  
  void setStartPos(int startPos);
  void mvPos();
  int getCurtPos();
  int getErr();
  bool isCurtPosNotch();

  int rotorMap[26][2];

  void encodeFwd(int& encLetter);
  void encodeBwd(int& encLetter);

 private:
  int err;   
  int nrOfNotches;
  int* notchPos; 
  int curtPos;

  //int expectedArrayLength;
};

#endif
