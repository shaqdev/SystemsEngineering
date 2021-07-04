#include <stdio.h>
#include <string.h>
#include "reverse.h"

#define MAX_LEN 100

int main(){
  char src[MAX_LEN];
  int beg, end; 
  scanf("%[^\n]%*c",src); // Note: String received through scanf is NULL TERMINATED 
  beg = 0;
  end = strlen(src) - 1;
  reverse(src, beg, end);
  printf("Reverse : %s\n",src);
  return 0;
}

