#ifndef UTILS_H
#define UTILS_H


int mod26(int n); // allows taking mod of negative nrs
bool isInRange(int* array, int arrayLength);
bool is_duplicate(int* array, int arrayLength);
int createArray(const char* filename, int* array, int& actualArrayLength);


#endif
