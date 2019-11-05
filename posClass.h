#ifndef POS_CLASS_H
#define POS_CLASS_H

class Position
{
 public:
  Position(const char positionFname[], int expectedArrayLength);
  ~Position();
  int getStartPos(int rotor_index);

 private:
  int * array;
  int expectedArrayLenght;
};

#endif
