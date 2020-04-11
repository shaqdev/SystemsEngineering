#include <stdio.h>

int uadd_ok(unsigned x, unsigned y)
{
	return x+y >= x; 
}
int main()
{
	unsigned num1 = 0,num2 = 0;
	printf("Enter num1 & num2\n");
	scanf("%u\n%u",&num1,&num2);
	int result = uadd_ok(num1, num2);
	printf("unsigned addition is good? %d\n",result);
return 0;
}