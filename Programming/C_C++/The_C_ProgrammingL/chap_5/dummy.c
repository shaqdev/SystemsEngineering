#include <stdio.h>

#define log_ptr(ptr) printf(#ptr": %p\n",ptr);
#define log_int(val) printf(#val": %d\n",val);

int main(int argc, char **argv) {
  int x = 10;
  int *ip = &x;
  *ip++;
  log_int(*ip);

  return 0;
}