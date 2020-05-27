#include <stdio.h>

void fibonacci_foo(void)
{
    int first = 0, second = 1, counter = 1, temp = 0;
    if(counter > 10)
        return;
    printf("Fibonocci series for first 10 numbers : ");
    body:
        temp = first + second;
        first = second;
        second = temp;
        printf("%d\t",temp);
        ++counter;
    if(counter <= 10)
        goto body;
    printf("\n");
}