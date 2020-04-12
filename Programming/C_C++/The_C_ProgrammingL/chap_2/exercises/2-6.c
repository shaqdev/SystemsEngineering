// setbits() that returns x with the n bits that begins at position p set to rightmost n bits of y
// leaving otherbits unchanged
#include <stdio.h>

unsigned setbits(unsigned x, unsigned n, unsigned p, unsigned y)
{
	// fetch n bits out of x
	x = (x >> p+1-n) & ~(~0 << n);
	x = (y & (~0 << n)) | x;
return x;
}

int main()
{
	unsigned x = 0xabcdefab,n = 4,p = 3,y = 0x12345678;
//	printf("Enter values of x, n, p, y respectively\n");
//	scanf("%u %u %u %u",&x,&n,&p,&y);
	x = setbits(x,n,p,y);
	printf("setbits of x :%x\n",x	);
return 0;
}