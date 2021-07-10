#include <stdio.h>

#define log_ptr(ptr) printf(#ptr": %p\n",ptr);
#define log_int(val) printf(#val": %d\n",val);

int main(int argc, char **argv) {
  int x = 10;
  int *ip = &x;
  int *xp = &x;
  *ip++;  // Post inc has high priority than *. Pointer is inc first and then deref
  (*xp)++;
  log_int(*ip);
  log_int(*xp);

  return 0;
}