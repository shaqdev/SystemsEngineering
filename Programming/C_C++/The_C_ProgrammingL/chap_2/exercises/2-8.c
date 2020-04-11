// rightrot() rotates x by n bits towards right

#include <stdio.h>

int rightrot(int x, unsigned n)
{
	unsigned temp = x & ~(~0U << n);
	unsigned w = sizeof(int) << 3;
	temp = temp << (w-n);
	return ((x >> n) & (~0U >> n)) | temp; 
}

int main()
{
	unsigned x = 0xabcdefab;
	unsigned n = 4;
	x = rightrot(x,n);
	printf("rightrot x : %x\n",x);
return 0;
}