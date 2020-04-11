// invert() that returns x with n bits from position p inverted.

#include <stdio.h>

unsigned invert(unsigned x, unsigned n, unsigned p)
{
	return x ^ ((~0 << (p+1)) ^ (~0 << p+1-n));
}

int main()
{
	unsigned x = 0xabcdefab;
	unsigned n = 4;
	unsigned p = 3;
	x = invert(x,n,p);
	printf("inverted x : %x\n", x);
return 0;
}