#include <stdio.h>
void staticFunc(void)
{
   double x = 10.5;
   printf("Inside the static function staticFunc() \n");
   {
      //int x = 10;
      printf("int x : %g\n",x);
   }
   printf("double x : %g\n",x);
}