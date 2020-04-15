#include <stdio.h>
#include <ctype.h> // to include isspace() and isdigit()
#include <string.h>

// Switch case to count no. of digits/white space/other chars
void count_char();

// atoi for converting string to its numeric equivalent.
// It should copy with leading whitespaces and + or - signs
int atoi();

// shell sort
void shellsort(int[], int);

// reverse string
void reverse(char[]);

int main()
{
	int i;
	int a = 10;
	{
		a = 20;
		int a = 30;
		a = 40;
	}
	printf("a*a : %d\n",a*a);

	// Switch case to count no. of digits/white space/other chars
	count_char();

	// atoi for converting string to its numeric equivalent.
	int atoi_ret = atoi();
	printf("atoi version 2, atoi_ret : %d\n", atoi_ret);

	//shell sort
	int shell_arr[8] = {5,6,4,2,8,1,7,9};

	printf("Before shell sort :\t");
	for (i = 0; i < 8; ++i)
		printf("%d\t",shell_arr[i]);
	printf("\n");

	shellsort(shell_arr, 8);
	
	printf("After shell sort  :\t");
	for (i = 0; i < 8; ++i)
		printf("%d\t",shell_arr[i]);
	printf("\n");

	// Reverse str
	char s[] = "khaleel";
	reverse(s);
	printf("reversed string : %s\n",s);

return 0;
}

void count_char()
{
	int digits = 0, white = 0, other = 0;
	char ch;

	while ((ch = getchar()) != 'x' && ch != 'X')
	{
		switch(ch)
		{
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				++digits;
				break;
			case ' ': case '\n': case '\t':
				++white;
				break;
			default :
				++other;
				break;
		}
	}
	printf("digits : %d\nwhite : %d\nother : %d\n",digits, white, other);
}

//atoi : Converts string to integer; version 2
int atoi()
{
	int i, n, sign;
	char s[] = "  -12365";

	//leave the leading white spaces
	for (i = 0; isspace(s[i]); ++i);

	//store the sign
	sign = (s[i] == '-') ? -1 : 1;

	//if sign character exists in string, increment the i
	if (s[i] == '+' || s[i] == '-')
		++i;

	for (n = 0; isdigit(s[i]); ++i)
		n = n * 10 + (s[i] - '0');

	return sign * n;
}

// shell sort 
/*
	first for : iterates through gap
	second for : iterates through elements
	third for : sorts and iterate backwards till first element
*/
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; ++i)
		{
			for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap)
			{
				temp = v[j+gap];
				v[j+gap] = v[j];
				v[j] = temp;
			}
		}
	}
}

// reverse a string
void reverse(char s[])
{
	char temp;
	int i, j;
	for (i = 0, j = strlen(s)-1; i < j ; ++i,--j){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

