#include <stdio.h>
#include <math.h>

int div16(int x)
{
	int den = pow(2,4); // 2^k
	// BIAS (x >> (2^4 - 1) & (2^4 - 1)) = (2^K - 1)
	return (x + (x >> (den - 1) & (den - 1))) >> 4;
}

int main(int argc, char *argv[])
{
	int x;
	printf("Enter input value\t:");
	scanf("%d",&x);
	printf("Result\t:%d\n",div16(x));
	return 0; 
}