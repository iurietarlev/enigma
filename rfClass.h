#ifndef RF_CLASS
#define RF_CLASS

class Reflector
{
 public:
  Reflector(const char* rfFname);
  void encode(int &encLetter);
  int getErr();
  
 private:
  int rfMap[26];
  int arrayLength = 26;
  int err;
};

#endif
