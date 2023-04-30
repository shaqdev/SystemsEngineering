#include <stdio.h>

char* strcat_k(char *s, char *t) {
  char tmp[100];
  int i = 0;
  for (i = 0; *s != '\0'; i++)
    tmp[i] = *s++;
  for (; *t != '\0'; i++)
    tmp[i] = *t++;
  tmp[i+1] = '\0';
  s = tmp;
}
int main() {
  char *s = "khaleel";
  char *t = "pasha";
  s = strcat_k(s, t);
  printf("concatenate string is %s\n",s);
  return 0;
}