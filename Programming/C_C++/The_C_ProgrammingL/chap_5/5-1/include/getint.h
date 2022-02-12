// Takes char from input stream and convert's its equivalent int and store it back to calling function
// Handle whitespaces and sign
// Returns 
//    0               : if not valid number
//    positive number : Valid number
//    EOF              : If end of file

#include "iochar.h"
#include <ctype.h>

int getint(int *);