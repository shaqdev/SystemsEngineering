#include <stdio.h>

void foo(int a, int b) {
  int z = 9;
  int x = a * b;
  x += a;
  x /= b;
  x += z;
}
int main(int argc, char **argv) {
  foo(5, 2);
  return 0;
}