#include <stdio.h>
#include "add_foo.h"

int main()
{
    int res = add_foo(2,3);

    printf("result of add_foo : %d\n",res);

    return 0;
}
