#include <stdio.h>
#include <assert.h>

int fits_bits(int x, int n)
{
/*
NOT A OPTIMUM SOLUTION

	// Toggle sign bit of x 
	x = x & (~0U >> 1);

	// set lsb n bits to zero and remaining to 1s and perform & with x
	return !(x & ~0U << (n-1));
*/

	// 	OPTIMUM SOLUTION 
	// example (assuem int as 8 bit): int x = -1; x has binary : 10000001
	// 2,s complement : -128+1 = -127 = 1111 11 11
	// if we compare binary and 2 complement representatin : if the 2's comp is left shift
	// by n and right shift by n, if the value remains same, then the value can be represented
	// with n bits

	int w = sizeof(int) << 3;
	int offset = w-n;
	return (x << offset >> offset) == x;

}

int main()
{
	assert(fits_bits(0xFFFFFFFF, 1)); // if int is 1 bit it has range -1 to 0
return 0;
}