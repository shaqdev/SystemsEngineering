#include <stdio.h>
#include <string.h>
#include <math.h>

#define HTOI_FAILED 0

int htoi(char*);

int main()
{
	int result = 0;
	char s[8];
	printf("Enter hex input string : ");
	scanf("%s",s);
	printf("Entered hex string is %s\n", s);
	result = htoi(s);
	printf("Result of htoi : %d\n", result);

return 0;
}

int htoi(char *s)
{
	int result_temp = 0;
	int max_index = strlen(s) - 1; // since we limited string size to 8, no need to worry about strlen > Tmax
	for (int i = max_index; i >= 0; --i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			result_temp = result_temp * 10 + (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <='F')
			result_temp = result_temp + (int)pow(16,max_index-i) * (s[i] - 'A' + 10);
		else if (s[i] >= 'a' && s[i] <='f')
			result_temp = result_temp + (int)pow(16,max_index-i) * (s[i] - 'a' + 10);
		else
			return HTOI_FAILED;
	}
return result_temp;
}