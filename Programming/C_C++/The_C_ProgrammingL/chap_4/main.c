#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
//#include "add_foo.h"

#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char pattern[]);

char pattern[] = "ould";

int main()
{
    /*
    //int res = add_foo(2,3);
    int res = 1;
    printf("result of add_foo : %d\n",res);

    return 1;
    */

   /* FIND ALL LINE MATCHING PATTERN */

   char line[MAXLINE];
   int found = 0;

    while (getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0){
            printf("%s",line);
            found++;
        }

    return found;
}

/*
getline(...) : get line in to char array 's' and return length
*/

int getline(char s[], int lim)
{
    int c, i;
    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/*
strindex(...) : return index of pattern in line, -1 if none
*/

int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++){
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}


