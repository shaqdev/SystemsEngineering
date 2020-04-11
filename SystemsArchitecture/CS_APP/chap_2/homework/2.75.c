#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int signed_high_prod(int x, int y)
{
	int64_t s_prod = (int64_t)x * y;
	return s_prod >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
	int sign_x = x >> 31;
	int sign_y = y >> 31;

	return signed_high_prod(x,y) + sign_x * y + sign_y * x;
}

unsigned traditional_unsigned_high_prod(unsigned x, unsigned y)
{
	uint64_t us_prod = (uint64_t)x * y;
	return us_prod >> 32;	
}

int main()
{
	assert(unsigned_high_prod(0xFFFFFFFF,0X12345678) 
			== traditional_unsigned_high_prod(0xFFFFFFFF,0X12345678));
return 0;
}