/*Write getfloat, the floating-point analog of getint. 
  What type does getfloat return as its function value? */


#include <stdio.h>
#include <ctype.h>

#define BUF_LEN 10
float input_buf[BUF_LEN] = {0.0};
int cnt = 0;
char getch(){
  char ch;
  if (cnt > 0)
    ch = input_buf[cnt];
  else
    ch = getchar();
}

void ungetch(char ch) {
  if (cnt >= BUF_LEN) {
    printf("Input buffer is full ! Unable to insert !");
    return;
  }
  else {
    input_buf[cnt] = ch;
    cnt++;
  }
}

#define MAX_VAL 10

int getfloat(float *ip) {    // complete getfloat
  char c;
  short sign;
  *ip = 0.0;
  
  while ((c = getch()) == ' ')
  ;

  if(!isdigit(c) && c != '+' && c != '-' && c != EOF && c != '.')
    return 0;

  sign = (c == '-') ? -1 : 1;
  if(c == '+' || c == '-')
    c = getch();

  float dec;
  float fc = 0.0;
  for(dec = 0.0; isdigit(c); c = getch())
      dec = 10 * dec + (c - '0');

  if(c == '.') {
    c = getch();

    for (int n = 1; isdigit(c); c = getch(), ++n) {
      fc = fc + (float)(c - '0')/(float)(n*10);
    }
  }

  *ip = sign * (dec + fc);


  //if (c != EOF)
  //  ungetch(c);
  
  return c;
}

int main(){

  float ft[MAX_VAL] = {0};
  int c;

  for(int i = 0; i < MAX_VAL; ++i)
    printf("%f\n",ft[i]);

  for(c = 0; c < MAX_VAL && getfloat(&ft[c]) != EOF; ++c)
  ;

  for(int i = 0; i < MAX_VAL; ++i)
    printf("%f\n",ft[i]);
  return 0;
}