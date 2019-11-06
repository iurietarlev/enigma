#ifndef RF_CLASS
#define RF_CLASS

class Reflector
{
 public:
  Reflector(const char* rfFname);
  int* getMap();
  int getLength();
  
 private:
  int rfMap[26];
  int arrayLength = 26;
};

#endif
