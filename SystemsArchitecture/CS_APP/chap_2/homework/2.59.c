// Yeild a word consisting lsb byte of x and remaining bytes of y
#include <stdio.h>

unsigned merge(unsigned x, unsigned y)
{
	return ((y >> 8) << 8) | (x & 0xFF);
}

int main()
{
	unsigned x = 0x89abcdef;
	unsigned y = 0x76543210;
	y = merge(x,y);
	printf("Merged hex : 0x%x\n",y);
return 0;
}