#include <stdio.h>

#define log_ptr(ptr) printf(#ptr": %p\n",ptr);
#define log_int(val) printf(#val": %d\n",val);

char geteof(void) {
  return EOF;
}

int main(int argc, char **argv) {
  char ch;

  ch = geteof();

  printf("ch is :%c\n", ch);
  printf("EOF is :%d\n", EOF);  

  return 0;
}