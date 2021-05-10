/*
Exercise 4-1. 
Write the function strrindex(s,t), which returns the position of the rightmost occurrence of t in s, or −1 if there is none.
*/

#include <string.h>
#include <assert.h>
#include <stdio.h>

int strrindex(char s[], char t[]){
    // Assume t is string
    int pos = -1;
    int i,j,k;

    for(i = 0; s[i] != '\0'; ++i){
        for(j = i, k = 0; s[j] != '\0' && t[k] != '\0'; ++j, ++k){
            ;
        }
        if (t > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}

int main()
{
    char s[] = "khaleel";
    char t[] = "l";
    int pos = strrindex(s,t);
    printf("%d\n",pos);
    assert(pos == 6);

    return 6;
}