#include <stdio.h>
int main()
{
	signed char val1 = -128;
	val1 = -val1;
	unsigned char val2 = 128;
	val2 = -val2;
	printf("hex value signed Tmin is :%.2x\n",val1); 
	printf("hex value unsigned eq is:%.2x\n",val2);
return 0;
}