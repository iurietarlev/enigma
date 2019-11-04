#ifndef PLGBRD_CLASS
#define PLGBRD_CLASS


class PlgBrd
{
 public:
  PlgBrd(const char* plgBrdFname);
  int getPlgBrdLength();
  int getIthInput(int i);
  int getIthOutput(int i);
  
 private:
  int arrayLength;
  int input[13];
  int output[13];
};

#endif
