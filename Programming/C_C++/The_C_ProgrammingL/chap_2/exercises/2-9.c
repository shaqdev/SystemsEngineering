// Brian Kernighan's Algorithm for counting set bits in hex
#include <stdio.h>

unsigned countSetBits(int x)
{
	unsigned count = 0;
	for (count = 0; x != 0; ++count)
		x &= x-1; // very optimum way of counting than using shifting
return count;
}

int main()
{
	int x = 0x80000000;
	unsigned count = countSetBits(x);
	printf("countSetBits : %u\n",count);

return 0;
}