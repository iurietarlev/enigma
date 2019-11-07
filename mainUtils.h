#ifndef MAIN_UTILS_H
#define MAIN_UTILS_H

#include"pbClass.h"
#include"rfClass.h"

// PLUGBOARD TRANSFORMATION FUNCTION
void pbOp(Pb &pb, int* encMsg, const int msgLength);

//REFLECTOR TRANSFORMATION FUNCTION
void rfOp(Reflector &pb, int& encMsg, const int msgLength);


#endif
