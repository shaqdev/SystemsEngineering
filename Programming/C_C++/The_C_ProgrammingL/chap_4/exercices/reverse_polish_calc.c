// REVERSE POLISH CALUCLATOR

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "getop_imp.h"
#include "stack_imp.h"

#define NUMBER 0
#define TOP_OF_STACK 'T'
#define SWAP_TOP_OF_STACK 'S'
#define CLEAR_STACK 'C'
#define MAX_VAR 26

#define MAX_OP 100 // Max length of the operand

int main(){
  int type = 0;
  char s[MAX_OP]; 
  double op2;
  double tos;
  double variable[MAX_VAR]; // They must be initialized
  for (int i=0; i < MAX_VAR; ++i)
      variable[i] = 0.0;

  while((type = getop(s)) != EOF){
    switch(type){
      case NUMBER:
            push(atof(s));
            break;
      case '+':
            push(pop() + pop());
            break;
      case '-':
            op2 = pop();
            push(pop() - op2);
            break;
      case '*':
            push(pop() * pop());
            break;
      case '/':
            op2 = pop();
            if(!op2)
              printf("Error: Zero divisor");
            else
              push(pop()/op2);
            break;
      case '%':
            // Modulus op (%) not applied on float or double type.
            op2 = pop();
            push((int)pop() % (int)op2);
            break;
      case TOP_OF_STACK:
            top_of_stack();
            break;
      case SWAP_TOP_OF_STACK:
            swap_top_of_stack();
            break;
      case CLEAR_STACK:
            clear();
            break;
      case '\n':
            tos = pop();
            printf("Value : %0.8g\n",tos);
            break;
      default:
            if (type >= 'A' && type <= 'Z')
                  push(variable[type-'A']);
            else
                  printf("Error: Unknown Command, %s\n", s);
            break;
    }
  }

  return 0;
}

