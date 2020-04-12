// Should return True (1) if int size is 32 else False (0) 
// Trick is right operand of shift cannot be greater or equal to width or it cannot be negative

#include <stdio.h>

char b_bad_int_size_is_32()
{
	int beyond_32 = 1 << 31 << 1;

	return !beyond_32; 
}

char c_bad_int_size_is_32()
{
	int msb_32 = 1 << 15 << << 15 << 1;
	int beyond_32 = msb_32 << 1;

	return !beyond_32;  
}

int main()
{
	printf("bad_int_size_is_32 : %d\n", c_bad_int_size_is_32());
return 0;
}