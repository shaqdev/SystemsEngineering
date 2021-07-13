// Write updated getint version of example with a fix for + or - given as single char
// To handle inputs, make use of getch & ungetch functions.

#include <stdio.h>
#include "getint.h"

#define MAX_VAL 10

int main(int argc, char **argv) {
  int c, arr[MAX_VAL], getint(int *);
  for (c = 0; i < MAX_VAL && getint(&arr[c]) != EOF; ++c)
    ;
  
  
  for (int i = 0; printf("%d\n",arr[i]) && c >= 0; ++i, --c)
    ;
  return 0;
}