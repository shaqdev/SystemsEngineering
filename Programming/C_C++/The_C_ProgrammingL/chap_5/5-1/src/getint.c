#include "./include/getint.h"

int getint(int *ip) {
  int c;
  while((c = getch()) == ' ')
    ;
  
  if (!(isdigit(c)) && !(c == '+' || c == '-'))
    return 0;

  if 
}