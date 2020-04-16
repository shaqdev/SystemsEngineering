#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

//Expand // EXPECTED SOL
void expand_expected(char s1[], char s2[]) {
  char c;
  int i = 0;
  int j = 0;
  while ((c = s1[i]) != '\0') {
    char nextc = s1[i + 1];
    if (nextc == '-') {
      char thirdc = s1[i + 2];
      if (
          isdigit(c) && isdigit(thirdc) 
          ||
          isupper(c) && isupper(thirdc)
          ||
          islower(c) && islower(thirdc)
      ) {
        if (c < thirdc) {
          while (c <= thirdc) {
            s2[j++] = c;
            c++;
          }
        } else {
          while (c >= thirdc) {
            s2[j++] = c;
            c--;
          }
        }
        i += 3;
      } else {
        s2[j++] = s1[i++];
      }
    } else {
      s2[j++] = s1[i++];
    }
  }
  s2[j] = '\0';
}

// Expand strings ACTUAL SOL
void expand_actual(char s1[], char s2[])
{
    int i=0,j= 0;
    char first;

    while ((first = s1[i]) != '\0'){
        char second = s1[i+1];
        if (second == '-'){
            char third = s1[i+2];
            if (isdigit(first) && isdigit(third) 
                ||
                isupper(first) && isupper(third)
                ||
                islower(first) && islower(third)){
                    if (first < third) {
                        while (first <= third) {
                            s2[j++] = first;
                            first++;
                        }
                    } else {
                        while (first >= third) {
                            s2[j++] = first;
                            first--;
                        }
                    }
                i += 3;
            } else {
                s2[j++] = s1[i++]; 
            }
        }
        else
            s2[j++] = s1[i++]; 
    }
    s2[j] = '\0';
}

int main()
{
    char s1[] = "-c-e, e-c-a, a-a, a-Z, a-9\n-A-C, E-C-a, A-A, A-z, A-9\n-0-2, 4-2-0, 0-0, 0-z, 0-Z\n";
    char s2[1000];

    expand_expected(s1, s2);
    printf("Expected string : %s\n",s2);

    char s3[] = "-c-e, e-c-a, a-a, a-Z, a-9\n-A-C, E-C-a, A-A, A-z, A-9\n-0-2, 4-2-0, 0-0, 0-z, 0-Z\n";
    char s4[1000];
    expand_actual(s3, s4);
    printf("Actual string : %s\n",s4);

    assert(s2 == s4);

    return 0;
}