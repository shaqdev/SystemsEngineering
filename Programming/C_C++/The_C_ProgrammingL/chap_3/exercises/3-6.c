/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.

Kernighan, Brian W.. C Programming Language (p. 64). Pearson Education. Kindle Edition. 
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 25

void itoa(int, char[], int);
void reverse(char[]);

int main()
{
    printf("3-4 - itoa, integer to integer string\n");
    char istr[MAX] = {'0'};    // Initializing string with all 
                               // '0' but not 0 => "0"/{'0'}
    int n,w;

    printf("Enter integer value\n");
    int ret = scanf("%d",&n);

    printf("Enter positive width value\n");
    int ret2 = scanf("%d",&w);

    n = INT_MIN;
    printf("INT_MIN = %d\n",INT_MIN);

    itoa(n, istr, w);

    
    printf("Integer String : %s\n",istr);

    return 0;
}

void itoa(int n, char istr[], int w)
{
    int i = 0, sign = 0;
    unsigned un;
    sign = n;

    if (n == INT_MIN)
        un = n;
    else if (n < 0)
        un = -n;
    
    do{
        istr[i++] = un % 10 + '0';
    } while ((un /= 10) > 0 && i < w);

    while(i < w){
        istr[i++] = '0';
    }

    if (sign < 0)
        istr[i++] = '-';
    istr[i] = '\0';

    reverse(istr);

    // dynamically allocate an array of given width and assign istr to it.


}

void reverse(char str[])
{
    int last_idx = strlen(str) - 1;
    char tmp;

    for (int i = 0; i < last_idx; ++i, --last_idx){
        tmp = str[i];
        str[i] = str[last_idx];
        str[last_idx] = tmp;
    }
}
