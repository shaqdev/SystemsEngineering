#include <stdio.h>
#include <string.h>

void escape_vis2esc(char s[], char t[])
{
	int s_i = 0,t_i = 0;

	while(s[s_i] != '\0' && t[t_i] != '\0')
	{
		switch (t[t_i])
		{
			case '\t':
			{
				s[s_i++] = '\\'; 
				s[s_i++] = 't';
				++t_i;
				break;
			}
			default :
			{
				s[s_i] = t[t_i];
				++s_i;
				++t_i;
				break;
			}
		}
	}
	s[s_i] = '\0';
}

int main()
{
	char s[10];
	char t[15] = "khaleel	pasha1	";

	escape_vis2esc(s, t);

	int i;
	printf("s : ");
	for (i = 0; i < 10; ++i)
		printf("%c",s[i]);
	printf("\n");
	printf("t : ");
	for (i = 0; i < 15; ++i)
		printf("%c",t[i]);
	printf("\n");

	printf("strlen(s) : %lu\n", strlen(s));

return 0;
}

