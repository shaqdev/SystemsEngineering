#include "./../include/getint.h"

int getint(int *ip) {
  int c, sign;

  // Skip blank spaces
  while((c = getch()) == ' ')
    ;
  
  // Return 0 if not digit or sign
  if (!isdigit(c) && c != '+' && c != '-' && c != EOF)
    //ungetch(c);
    return 0;

  sign = (c == '-') ? -1 : 1;

  if(c == '+' || c == '-')
    getch();

  for(*ip = 0; isdigit(c); c = getch())
    *ip = 10 * *ip + (c - '0');

  *ip *= sign;

  return c;
  
}