#include <stdio.h>

unsigned rotate_left(unsigned x, int n)
{
	// n is the number of bits to be shifted
	int w = sizeof(unsigned) << 3;
	return (x >> w-n) | (x << n);
}

int main()
{
	unsigned x;
	int n;
	printf("Enter hex value followed by space & number of bits to rotate left\t:0x");
	scanf("%x %d",&x,&n);
	printf("rotate_left : 0x%x\n",rotate_left(x, n));
return 0;
}