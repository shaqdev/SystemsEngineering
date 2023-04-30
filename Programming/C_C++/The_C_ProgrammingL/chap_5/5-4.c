#include <stdio.h>

int strend_k(char *s, char *t) {
  
  char *tmp_s = s, *tmp_t = t;
  int i;
  
  while(*s != '\0') {
    while(*tmp_s == *tmp_t) {
      if (*tmp_s == '\0')
        return 1;
      tmp_s++;
      tmp_t++;
    }
    s++;
    tmp_t = t;
    tmp_s = s;
  }
  
  return *s == *t;
}

int main() {
  char *s = "khaleel";
  char *t = "";
  int res = strend_k(s, t);
  printf("Returns %d\n", res);
  return 0;
}