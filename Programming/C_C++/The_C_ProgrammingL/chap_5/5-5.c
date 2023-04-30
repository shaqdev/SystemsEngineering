#include <stdio.h>

char* strncpy_k(char *s, char *t, int n);
char* strncat_k(char *s, char *t, int n);
int strncmp_k(char *s, char *t, int n);

int main() {

  char s[] = "khaleel";
  char t[] = "pasha";
  char *ncpy = strncpy_k(s,t,3);
  printf("strncpy_k gives %s\n", ncpy);
  char *ncat = strncat_k(s, t, 3);
  printf("strncat_k gives %s\n", ncat);
  int ncmp = strncmp_k(s, t, 3);
  printf("strncmp_k gives %d\n", ncmp);



  return 0;
}

char * strncpy_k(char *s, char *t, int n) {
  int i;
  for (i = 0; i < n && (s[i] = t[i]) != '\0'; ++i)
    ;
  if (i >= n)
    s[i] = '\0';
  return s;
 }

char * strncat_k(char *s, char *t, int n) {
  int i;
  for (i = 0; s[i] != '\0'; i++)
    ;
  for (int j = 0; j < n && t[j] != '\0'; ) {
    s[i++] = t[j++];
  }
  s[i] = '\0';
  return s;
 }

 int strncmp_k(char *s, char *t, int n) {
   for (int i =0; s[i] == t[i]; ++i){
     if (s[i] == '\0' || --n <= 0)
      return 0;
   }
   return *s - *t;
 }
