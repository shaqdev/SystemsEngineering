#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	if (i >= 0 && i < sizeof(unsigned))
	{
		x = x & ~(0xFF << i*8);
		unsigned temp = (unsigned)b << i*8;
		x = x | temp;
	}
	else
		printf("Invalid byte position\n");

return x;
}

int main()
{
	unsigned x = 0x12345678;
	int i = 2;
	unsigned char b = 0xab;
	x = replace_byte(x,i,b);
	printf("replace_byte : %x\n",x);
return 0; 
}