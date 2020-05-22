/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats n as a hexadecimal integer in s.

Kernighan, Brian W.. C Programming Language (p. 64). Pearson Education. Kindle Edition. 
*/
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <string.h>

void reverse(char[]);

#define MAX 25

void itob(int, char[], int);

int main()
{
    char s[sizeof(int)*2+1];
    memset(s,48,9);
    int n,base;
    printf("Enter integer 'n' and required base format 'base'\n");
    scanf("%d%d",&n,&base);

    itob(n,s,base);

    printf("%d format : %s\n",base,s);

}

void itob(int n, char s[], int b)
{
    int sign, v, i = 0;

    // save the sign 
    if ((sign = n) < 0){
        if (n = INT_MIN){
            s[i] = 8 + '0';
            s[8] = '\0';
            return;
        }
        else{
            n = -n;
        }
    }

    s[i++] = '\0';
    do{
        if ((n < b) && (sign < 0))
            v = (n % b) + 8;
        else
            v = n % b;
        if (v >= 0 && v <= 9)
            s[i++] = v + '0';
        else if(v >= 10 && v <= 15)
            s[i++] = v%10 + 'A';
    } while((n /= b) > 0);

    reverse(s);
}

void reverse(char str[])
{
    int last_idx = 8;
    char tmp;

    for (int i = 0; i < last_idx; ++i, --last_idx){
        tmp = str[i];
        str[i] = str[last_idx];
        str[last_idx] = tmp;
    }
}
