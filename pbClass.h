#ifndef PLGBRD_CLASS
#define PLGBRD_CLASS


class Plugboard
{
 public:
  Plugboard(const char* pbFname);
  void encode(int& encLetter);
  int getErr();
  ~Plugboard();
  
 private:
  int* pbMap;
  int arrayLength;
  int err;
};

#endif
