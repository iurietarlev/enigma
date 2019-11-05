#ifndef PLGBRD_CLASS
#define PLGBRD_CLASS


class PlgBrd
{
 public:
  PlgBrd(const char* plgBrdFname);

  int* getMap();
  int getLength();
  //int getIthInput(int i);
  //int getIthOutput(int i);
  ~PlgBrd();
  
 private:
  int* plgMap;
  int arrayLength;
  //int input[13];
  //int output[13];
};

#endif
