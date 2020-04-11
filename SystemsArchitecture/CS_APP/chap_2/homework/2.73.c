#include<assert.h>
#include<limits.h>

int saturating_add(int x, int y)
{
	// if x > 0, y > 0 and x+y < 0, positive overflow
	// if x < 0, y < 0 and x+y >= 0, negative overflow

	int sum = x+y;

	int pos_oveflow = !(x & INT_MIN) && !(y & INT_MIN) && (sum & INT_MIN);
	int neg_overflow = (x & INT_MIN) && (y & INT_MIN) && !(sum & INT_MIN);

	(pos_oveflow && (sum = INT_MAX) || neg_overflow && (sum = INT_MIN)); 

	return sum;
}

int main()
{
	assert(saturating_add(INT_MIN, INT_MIN) == INT_MIN);
	assert(saturating_add(0x7FFFFFFF, 0x7FFFFFFF) == INT_MAX);
return 0;
}