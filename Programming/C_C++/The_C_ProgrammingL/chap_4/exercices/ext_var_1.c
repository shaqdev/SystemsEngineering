#include <stdio.h>
#include "ext_var_2.h"

void loc_foo(void);

extern int extVar_c = 50;

int main()
{
	printf("From ext_var_2.h in main: %d\n", extVar_h);
	printf("From ext_var_2.c in main: %d\n", extVar_c);
	loc_foo();
	return 0;
}

void loc_foo(void){
	printf("From ext_var_2.h in loc_foo: %d\n", extVar_h);
	printf("From ext_var_2.c in loc_foo: %d\n", extVar_c);
}