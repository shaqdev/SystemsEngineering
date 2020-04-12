#include <stdio.h>
#include <assert.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
	int left_shifts = (sizeof(packed_t) << 3) - (bytenum+1 << 3);

	return	((int)word << left_shifts) >> 24;
}

int main()
{
	assert(xbyte(0b11111111, 0));
	printf("xbyte : %.8x\n", xbyte(0b11111111, 0));
return 0;
}