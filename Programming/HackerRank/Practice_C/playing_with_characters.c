#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() 
{
    char ch = '\0', s[MAX_LEN] = {}, sen[MAX_LEN] = {};
    
    scanf("%c", &ch);
    scanf("%99s", s);
    scanf("\n"); // We assume only single work string is passed in to 's'
    scanf("%99[^\n]%*c", sen);  // It wont work unless we cleared input buffer till last line
    
    printf("%c\n", ch);
    printf("%s\n",s);
    printf("%s\n", sen);
    
   
    return 0;
}
