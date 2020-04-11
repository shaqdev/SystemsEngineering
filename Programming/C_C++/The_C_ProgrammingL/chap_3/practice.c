#include <stdio.h>

int main()
{
	int a = 10;
	{
		a = 20;
		int a = 30;
		a = 40;
	}
	printf("a*a : %d\n",a*a);

	// Switch case to count no. of digits/white space/other chars
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

return 0;
}