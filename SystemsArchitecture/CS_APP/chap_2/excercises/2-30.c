#include <stdio.h>

int tadd_ok(int x, int y)
{
	int pos_of = x >= 0 && y >= 0 && x + y < 0;
	int neg_of = x <0 && y < 0 && x+y >= 0;
	return !pos_of && !neg_of;
}

int tsub_ok(int x, int y)
{
	return tadd_ok(x, -y);
}

int main()
{
	int x,y;
	printf("Enter x, y\n");
	scanf("%d\n%d",&x,&y);
	int result = tadd_ok(x,y);
	printf("No overflow : %d\n",result);
return 0;
}