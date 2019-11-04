#ifndef POS_CLASS_H
#define POS_CLASS_H

class Position
{
 public:
  Position(const char positionFname[], int expectedArrayLength);
 private:
  int positionArray[80];
  int expectedArrayLenght;
};

#endif
