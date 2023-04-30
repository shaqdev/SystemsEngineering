// Write updated getint version of example with a fix for + or - given as single char
// To handle inputs, make use of getch & ungetch functions.

#include <stdio.h>
#include "./../include/getint.h"

#define MAX_VAL 10

int main(int argc, char **argv) {
  int c, arr[MAX_VAL], getint(int *);

  for (int i = 0; i < MAX_VAL; ++i)
    printf("%d\n",arr[i]);
  
  for (c = 0; c < MAX_VAL && getint(&arr[c]) != EOF; ++c) // Bug fixes in get int
    ;
  
  for (int i = 0; i < MAX_VAL; ++i)
    printf("%d\n",arr[i]);

  return 0;
}