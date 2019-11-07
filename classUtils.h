#ifndef UTILS_H
#define UTILS_H


int mod(int x, int n); // allows taking mod of negative nrs
bool rangeOk(int* array, int arrayLength);
bool lengthOk(int actualArrayLength, int expectedArrayLength);
bool duplicates(int* array, int arrayLength);
bool duplicates2d(int array[26][4], int arrayLength);
void createArray(const char* filename, int* array, int& actualArrayLength);


#endif
