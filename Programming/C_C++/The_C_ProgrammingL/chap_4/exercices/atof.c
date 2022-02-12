#include <stdio.h>
#include <ctype.h>
#include "atof.h"

double atof(char str[])
{
  double int_val = 0.0, Frac_val = 0.0, power = 1;
  int i = 0, sign = 0, power_sign = 0, power_val = 0;

  // skip all white spaces
  for (; str[i] == ' '; ++i)
    ;
  
  // store sign 
  sign = (str[i] == '-') ? -1 : 1;

  // skip sign symbol
  if (str[i] == '-' || str[i] == '+')
    ++i;

  // converting integer part
  for (; isdigit(str[i]); ++i){
    int_val = 10 * int_val + (str[i] - '0');
  }

  // skip period 
  if (str[i] == '.')
    ++i;

  for (; isdigit(str[i]); ++i){
    Frac_val = 10 * Frac_val + (str[i] - '0');
    power = 10 * power;
  }

  Frac_val = Frac_val/power;
  int_val = int_val + Frac_val;
  
  if (str[i] == 'e' || str[i] == 'E')
    ++i;

  power_sign = (str[i] == '-') ? -1 : 1;

  if (str[i] == '-' || str[i] == '+')
    ++i;

  for (; isdigit(str[i]); ++i){
    power_val = 10 * power_val + (str[i] - '0');
  }

  power = 1;

  for (int j = 0; j < power_val; ++j){
    if (power_sign == -1){
      power = power/10;
    }
    else {
      power = power * 10;
    }
  }

  int_val = int_val * power;

  printf("int_val : %0.8lf\n",int_val);

  return (sign == -1) ? int_val * -1 : int_val;
}