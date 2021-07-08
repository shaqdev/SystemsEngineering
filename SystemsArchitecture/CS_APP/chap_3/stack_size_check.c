#include <stdio.h>

void proc(long, long*, int, int*, short, short*, char, char*);

int main() {

  long a,*ap;
  int b, *bp;
  short c, *cp;
  char d, *dp;
  a = 10;
  ap = &a;
  b = 20;
  bp = &b;
  c = 30;
  cp = &c;
  d = 40;
  dp = &d;

  proc(a, ap, b, bp, c, cp, d, dp);
  return 0;
}

void proc(long a, long* ap, int b, int* bp, short c, short* cp, char d, char* dp) {
  *ap += a;
  *bp += b;
  *cp += c;
  *dp += d;
}