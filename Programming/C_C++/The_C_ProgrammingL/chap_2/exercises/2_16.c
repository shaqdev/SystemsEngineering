#include <stdio.h>

int main(){
	int x = 0xF4000000;
	x = x >> -31;
	printf("For signed x, x >> -1 : %x\n",x);
	printf("size of int : %lu\n", sizeof(int));
return 0;
}