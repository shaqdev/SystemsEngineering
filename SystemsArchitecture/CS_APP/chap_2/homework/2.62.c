//Return 1 if int shifts are arithmatic else 0 for logic

#include <stdio.h>

int int_sifts_are_arithmatic()
{
	return ~(~0 >> 1) ? 0 : 1;
}

int main()
{
	printf("Shifts are arithmatic : %d\n", int_sifts_are_arithmatic());
return 0;
}