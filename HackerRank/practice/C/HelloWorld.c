/* This challenge requires you to print  on a single line, 
   and then print the already provided input string to stdout. */

#include <stdio.h>
#define MAX 100

int main(int argc, char **argv)
{
    char s[MAX];

    scanf("%[^\n]%*c", s);
    printf("Hello, World!\n%s\n", s);

    return 0;
}