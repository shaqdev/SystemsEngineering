#include <stdio.h>

#define POS_INFINITY 2E308
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1.0/POS_INFINITY)

int main(){
	printf("POS_INFINITY : %e\nNEG_INFINITY : %e\nNEG_ZERO : %e\n", 
			POS_INFINITY, NEG_INFINITY, NEG_ZERO);

return 0;
}
