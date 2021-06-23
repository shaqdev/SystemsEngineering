#include <ctype.h>
#include <stdio.h>

#define BUF_SIZE 100
int buf[BUF_SIZE];
int buf_p = 0;

// If there is only one char of pushback, use char but not char []

// Get a char
int getch(void){
  return (buf_p > 0) ?  buf[--buf_p] : getchar();
}

// Unget a char
void ungetch(int c){
  if (buf_p >= BUF_SIZE)
    printf("ungetch: Too many charaters\n");
  else
    buf[buf_p++] = c;
}

void ungets(char s[]){
  int i = 0;
  while (s[i] != '\0')
    ungetch(s[i++]);
}



/* GET OPERATOR OR OPERAND */
int getop(char s[]){
  int i, c;

  static int last_c = 0;

  if (!last_c){
    c = last_c;
    last_c = 0;
  }
  else
    c = getch();  

  // Skip white and tab spaces
  while((s[0] = c) == ' ' || c == '\t')
    c = getch();

  s[1] = '\0';

  if(!isdigit(c) && c != '.')
    return c;

  i = 0;

  if(isdigit(c))
    while(isdigit(s[++i] = c = getch()))
      ;

  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';

  if(c != EOF)
    last_c = c;


  return 0;
}