#include <stdio.h>

#ifndef VERSION
#define VERSION 2
#endif

int main(){

  printf("khaleel\n");
  #if VERSION == 3
  printf("pasha\n");
  #endif

  return 0;
}