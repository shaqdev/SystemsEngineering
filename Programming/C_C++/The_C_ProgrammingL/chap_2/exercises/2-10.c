// Convert to lower case using ternary operator
#include <stdio.h>

char lower(char ch)
{
	return (ch >= 'A' && ch <= 'Z') ? (ch + 'a' - 'A') : ch;  
}

int main()
{
	char ch = '\0';
	printf("Enter char to convert in to lower case : ");
	scanf("%c",&ch);
	printf("Converted lower character : %c\n",lower(ch));
return 0;
}