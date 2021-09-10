#include "./../include/getint.h"

int getint(int *ip) {
  int c, sign;

  // Skip blank spaces
  while((c = getch()) == ' ')
    ;
  
  // Return 0 if not digit or sign
  if (!(isdigit(c)) && !(c == '+' || c == '-'))
    return 0;

  // Return positive value if digit 
  // Return signed value if sign followed by digit
  // Return sign if only sign is given
  if (isdigit(c))
    return (*ip = atoi(c));
  else {
    sign = (c == '-') ? -1 : 1;
    if(isdigit(c = getch())){
      *ip = sign * atoi(c);
      return *ip;
    }
    else
      return sign;
  }

  // if EOF unget the char and return
  if (c == EOF) {
    ungetch(c);
    return c;
  }
}