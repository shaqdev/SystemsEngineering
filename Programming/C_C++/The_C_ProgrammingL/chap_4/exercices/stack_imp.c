/* STACK */
#include <stdio.h>

#define ST_SIZE 100
double st[ST_SIZE];
int st_p = 0;

void push(double val){
  if (st_p > ST_SIZE)
    printf("Error: Stack Full, can't push %g\n",val);
  else
    st[st_p++] = val;
}

double pop(void){
  if (st_p > 0)
    return st[--st_p];
  else{
    printf("Error: Stack is empty\n");
    return 0.0;
  }
}

void top_of_stack(void){
  if(st_p > 0)
    printf("Top of Stack is : %0.8g\n", st[st_p - 1]);
  else
    printf("Stack is Empty\n");
}

void swap_top_of_stack(void){
  if (st_p > 1){
    st[st_p-2] = st[st_p - 2] + st[st_p -1];
    st[st_p - 1] = st[st_p-2] - st[st_p - 1];
    st[st_p-2] = st[st_p-2] - st[st_p - 1];
  }
}

void clear(void){
  while(st_p > 0)
    pop();
}