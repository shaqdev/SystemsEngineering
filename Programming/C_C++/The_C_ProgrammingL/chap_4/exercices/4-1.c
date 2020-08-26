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
    int i,j;

    for(i = 0; strlen(s) >= strlen(t) + i; ++i){
        for(j = 0; j < strlen(t); ++j){
            if (s[i+j] == t[j]){
                if(j == strlen(t) - 1)
                    pos = i;
                continue;
            }
            else 
                break;
        }
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

    return 0;
}