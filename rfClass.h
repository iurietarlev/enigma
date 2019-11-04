#ifndef RF_CLASS
#define RF_CLASS

class Reflector
{
 public:
  Reflector(const char* rfFname);
  int getIthInput(int i);
  int getIthOutput(int i);
  
 private:
  int input[13];
  int output[13];
};

#endif
