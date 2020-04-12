// Return first location in string s1 where any character in the string s2 occurs
#include <stdio.h>

int any(char s1[], char s2[])
{
	int location = -1;

	int i,j;
	int local_location = 0;

	while (s1[local_location] != '\0')
			local_location++;

	for (j = 0; s2[j] != '\0'; ++j)
	{
		for (i= 0; i<local_location; ++i)
		{
			if (s1[i] == s2[j])
			{
				location = local_location = i;
				break;
			}
		}
	}

return location;
}

int main()
{
	char s1[] = "khaleel";
	char s2[] = "gal";
	int location = any(s1,s2);
	printf("location : %d\n",location);
return 0;
}