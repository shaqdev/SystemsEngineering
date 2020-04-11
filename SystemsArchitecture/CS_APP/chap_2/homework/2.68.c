// set lower n bits to 1
#include <stdio.h>

int lower_one_mask(int n)
{
	return ~0U >> ((sizeof(int) << 3) - n);
}

int main()
{
	int n = 0;
	printf("Enter lower no. of bits (1 to %lu) : ", sizeof(int) << 3);
	scanf("%d",&n);
	(n >= 1 && n <= sizeof(int)*8) ? printf("lower one mask : %.8x\n", lower_one_mask(n)) : printf("Invalid n value bro...!\n");;
return 0;
}