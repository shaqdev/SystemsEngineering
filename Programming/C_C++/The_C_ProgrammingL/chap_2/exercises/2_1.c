#include <limits.h>
#include <float.h>
#include <stdio.h>

int main()
{
	unsigned int num_print_char = printf("Range of Signed CHAR : (%d, %d)\nRange of UnSigned CHAR : (%u, %u)\n", SCHAR_MIN, SCHAR_MAX, 0, UCHAR_MAX);
	printf("Size of CHAR : %lu \n",sizeof(char));
	printf("printf return of CHAR : %u\n",num_print_char);

	unsigned int num_print_short = printf("\nRange of Signed SHORT : (%d, %d)\nRange of UnSigned SHORT : (%u, %u)\n", SHRT_MIN, SHRT_MAX, 0, USHRT_MAX);
	printf("Size of SHORT : %lu\n",sizeof(short));
	printf("printf return of SHORT : %u\n",num_print_short);
	
	unsigned int num_print_int = printf("\nRange of Signed INT : (%d, %d)\nRange of UnSigned INT : (%u, %u)\n", INT_MIN, INT_MAX, 0, UINT_MAX);
	printf("Size of INT : %ld\n",sizeof(int));
	printf("printf return of INT : %u\n",num_print_int);

	unsigned int num_print_long = printf("\nRange of Signed LONG : (%ld, %ld)\nRange of UnSigned LONG : (%u, %lu)\n", LONG_MIN, LONG_MAX, 0, ULONG_MAX);
	printf("Size of LONG : %ld\n",sizeof(long));
	printf("printf return of LONG : %u\n",num_print_long);

	unsigned int num_print_float = printf("\nRange of FLOAT : (%G, %G)\n", FLT_MAX, FLT_MIN);	
	unsigned int num_print_double = printf("\nRange of DOUBLE : (%e, %e)\n", DBL_MAX, DBL_MIN);
	unsigned int num_print_long_double = printf("\nRange of LONG DOUBLE : (%LG, %LG)\n", LDBL_MAX, LDBL_MIN);

return 0;
}