#include <stdio.h>

#define swap(t, x, y) t z = x; \
                      x = y;   \
                      y = z   \

int main(){
  int a, b;
  a=10;
  b = 20;
  printf("Before swap\na : %d\nb : %d\n",a,b);
  swap(int, a, b);
  printf("After swap\na : %d\nb : %d\n",a,b);
  return 0;
}