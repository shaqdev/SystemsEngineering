#include <stdio.h>
#include <stdlib.h>

float sum_elements(float a[], unsigned length)
{
	float result = 0;
	for (int i = 0; i < length; ++i)
	{
		result =  result + a[i];
	}
return result;
}

int main()
{
	unsigned arr_size = 0;
	scanf("%u",&arr_size);
	float *farr = (float *)calloc(1,arr_size*sizeof(float));
	for (size_t i = 0;i < arr_size; ++i)
	{
		farr[i] = i+1;
	}
	float result = sum_elements(farr, arr_size);
	printf("Sum of first n natural numbers is : %f\n",result);
return 0;
}