#include <stdio.h>
#include "atof.h"

#define MAXLINE 100

int main(){

  char str[MAXLINE] = "123.45E-6";
  double val = atof(str);

  printf("double precision FP value : %g\n",val);

  return 0;
}

