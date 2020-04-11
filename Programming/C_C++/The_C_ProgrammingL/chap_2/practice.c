#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MACRO_1 1000
#define MACRO_1 2000

void green () {
  printf("\033[1;32m");
}

void blue () {
  printf("\033[1;34m");
}

void red () {
  printf("\033[1;31m");
}

void yellow () {
  printf("\033[01;33m");
}

void margin_start () {
  yellow();
  printf("==========================================================================\n");
  red();
}

void margin_end () {
  yellow();
  printf("==========================================================================\n");
  printf("\033[0m");
}

typedef enum week1{
	SUNDAY = -1,
	MONDAY,
	TUESDAY
};

typedef enum week2{
	//TUESDAY,
	WEDNESDAY,
	//THURSDAY
};

typedef enum week3{
	THURSDAY,
	FRIDAY,
	SATURDAY
};

int main(){

	enum week1 week1 = 50;

	printf("week1 : %d\n",week1);
	printf("INTEGER VALUE FOR MONDAY : %d\n",MONDAY);
	printf("INTEGER VALUE FOR TUESDAY : %d\n",TUESDAY);
	printf("INTEGER VALUE FOR WEDNESDAY : %d\n",WEDNESDAY);

//  We cannot use modulo operator on float or double because % always returns int values.
//	float check_modulo_float1 = 2.5;
//	float check_modulo_float2 = 1.0;//

//	printf("checking modulo can be applied on float or double : %f\n",(check_modulo_float1%check_modulo_float2));

/* '/' & '%' for negative numbers. */
/*-------------------------------- */
	float div_negValue1 = -3.0; 
	float div_negValue2 = 2.0;

	margin_start();
	printf("Determining truncation for negative float\n");
	margin_end();
	printf("'/' for negative operands : %f\n", (div_negValue1/div_negValue2));

	float fremainder_value = remainder(6.5,2.5);

	printf("fremainder_value : %f\n",fremainder_value);

	// Determining truncation for positive float
	float pftrunc_value = 210000000000000000000000.9/6.7;

	margin_start();
	printf("Determining truncation for positive float\n");
	margin_end();
	printf("pftrunc_value : %f\n",pftrunc_value);

	// Determining truncation for int division
	int itrunc_pvalue1 = 2;
	int itrunc_nvalue1 = -2;
	int itrunc_value2 = 7;

	margin_start();
	printf("Determining truncation for int division\n");
	margin_end();

	printf("positive division result : %d\nnegative division result : %d\n",
		  (itrunc_pvalue1/itrunc_value2),(itrunc_nvalue1/itrunc_value2));

	// Determining sign for int modulus
	int imod_pvalue1 = 2;
	int imod_nvalue1 = -2;
	int imod_value2 = 7;

	margin_start();
	printf("Determining sign for int modulus\n");
	margin_end();

	printf("positive modulus result : %d\nnegative modulus result : %d\n",
		  (imod_pvalue1%imod_value2),(imod_nvalue1%imod_value2));

	
	//Determining int overflow - machine dependent as is the action is undefined
	int value_check_p1 = 2147483648; //INT MAX VALUE + 1
	int value_check_p2 = 2147483649; //INT MAX VALUE + 2		
	margin_start();
	printf("Determining int overflow\n");
	margin_end();

	printf("INT MAX VALUE + 1 : %d\n", value_check_p1);
	printf("INT MAX VALUE + 2 : %d\n", value_check_p2);

	//Determine right operand of shift operator can be negative?
	unsigned shift_neg = 0xabcd >> -8;
	printf("shift operator with negative operand : %x\n",shift_neg);

return 0;
}