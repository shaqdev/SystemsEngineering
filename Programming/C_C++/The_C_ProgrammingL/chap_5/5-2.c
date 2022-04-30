#include <stdio.h>

#define MAX_VAL 10

bool getfloat(float *ip) {    // complete getfloat
  char c;
  short sign;
  
  while ((c = getch()) != ' ')
  ;

  if(!isdigit(c) && c != '+' && c != '-' && c != EOF)
    return 0;

  sign = (c == '-1') ? -1 : 1;
  if(c == '+' || c == '-')
    c = getch();

  for(*ip = 0; isdigit(c); c = getch())
      *ip = 10 * *ip + (c - '0');

  if(c == '.')
  
}

int main(){

  float ft[MAX_VAL] = {0};
  int c;

  for(int i = 0; i < MAX_VAL; ++i)
    printf("%d\n",ft[i]);

  for(c = 0; c < MAX_VAL && getfloat(&ft[c]) != EOF; ++c)
  ;

  for(int i = 0; i < MAX_VAL; ++i)
    printf("%d\n",ft[i]);
  return 0;
}