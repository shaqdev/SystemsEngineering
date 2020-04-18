#include <stdio.h>

int main()
{
	unsigned char ch = 130;
	unsigned char *sp = &ch;
	unsigned *dp;

	//*sp = 64;

	*dp = (unsigned) *sp;
	printf("unsigned *dp : %u\n",*dp);
return 0;
}