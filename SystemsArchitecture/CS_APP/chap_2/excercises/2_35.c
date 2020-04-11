#include <stdio.h>
#include <stdint.h>

// DETERMINING THE OVERFLOW WITH DIVISION
int tmult_ok(int x, int y)
{
	int p = x*y;
	return !x || p/x==y;
}

//DETERMINING THE OVERFLOW WITHOUT DEVISION BUT USING INT65_T PRECISION
int tmult_ok_2(int x, int y)
{
	int64_t result = (int64_t) x*y;
	return (int)result == result;
}

int main(int argc, char const *argv[])
{
	int x,y;
	printf("Enter x & y values below\n");
	scanf("%d\n%d",&x,&y);
	int tmult_result = tmult_ok(x,y);
	printf("multiplication is good : %d\n", tmult_result);	
	return 0;
}