#include <stdio.h>
#include <string.h>

#define LIMIT 25

int main()
{
	int i = 0, count = 0;
	char charr[LIMIT];
	char c = '\0';

	for (i = 0; i < LIMIT;++i)
	{
		c = getchar();
		if (c != '\n')
		{
			if (c != EOF)
			{
				charr[i] = c;
				++count;
			}
			else
				break;
		}
		else
			break;
	}

	for (i=0;i<count;++i)
	{
		printf("%c", charr[i]);
		if (i == count - 1)
			printf("\n");
	}

return 0;
}