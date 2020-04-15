#include <string.h>
#include <stdio.h>
#include <ctype.h>

//Expand // EXPECTED SOL


// Expand strings ACTUAL SOL
void expand(char s1[], char s2[])
{
    int i;
    char first = '\0', second = '\0';

    for (i = 0; !(isupper(s1[i]) || islower(s1[i]) || isdigit(s1[i])) && i < strlen(s1); ++i);

    first = s1[i];

    for (; s1[i] != '-' && i < strlen(s1); ++i);

    for (; !(isupper(s1[i]) || islower(s1[i]) || isdigit(s1[i])) && i < strlen(s1); ++i);

    second = s1[i]; 

    for (i = 0; !(first == '\0' || second == '\0') && first <= second; ++i, ++first){
        s2[i] = first;
    }
}

int main()
{
    char s1[] = "-1-6";
    char s2[50];

    expand(s1, s2);

    printf("expanded string : %s\n",s2);

    return 0;
}