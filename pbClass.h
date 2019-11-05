#ifndef PLGBRD_CLASS
#define PLGBRD_CLASS


class Pb
{
 public:
  Pb(const char* pbFname);

  int* getMap();
  int getLength();
  ~Pb();
  
 private:
  int* pbMap;
  int arrayLength;
  //int input[13];
  //int output[13];
};

#endif
