#ifndef UTILS_H
#define UTILS_H

#include<iostream>
#include"errors.h"
#include<cctype>
#include<fstream>


// calculates n%26 (including -ve nrs)
int mod26(int n);

// checks if the numbers of array are within 0-25 range
bool isInRange(int* array, int arrayLength);

// checks if there are any duplicates in the array
bool is_duplicate(int* array, int arrayLength);

// creates array from the input file and also stores the error code
int createArray(const char* filename, int* array, int& actualArrayLength);

// outputs error message when can't open a file
void cerrCantOpenFile(const char* fname);


#endif
