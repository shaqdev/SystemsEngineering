#include "./../include/iochar.h"

#define MAX_BUF 100
char buff[MAX_BUF];   // only used for unget chars
int cnt = 0;

char getch(void) {
  return (cnt > 0) ? buff[--cnt] : getchar();
}

void ungetch(char ch) {
  if (cnt >= MAX_BUF) {
    printf("Buffer is Full ! Cannot insert %c in to buffer\n",ch);
  }
  else {
    buff[cnt++] = ch;
  }
}