// Print operator precedence table 

#include <stdio.h>

int main() {
  
  printf("%16s%41s\n","Operator","Associativity");
  printf("\n");
  printf("%24s%33s\t%s\n","() [] -> . ++ --", "left to right", "Post inc/dec");
  printf("%39s%18s\t%s\t%s\n","! ~ ++ -- + - (type) * & sizeof", "right to left", "Pre inc/dec", "Unary Ops");
  printf("%13s%44s\n", "* / %", "left to right");
  printf("%11s%46s\n", "+ -", "left to right");
  printf("%13s%44s\n", "<< >>", "left to right");
  printf("%17s%40s\n", "< <= > >=", "left to right");
  printf("%13s%44s\n", "== !=", "left to right");
  printf("%9s%48s\n", "&", "left to right");
  printf("%9s%48s\n", "^", "left to right");
  printf("%9s%48s\n", "|", "left to right");
  printf("%10s%47s\n", "&&", "left to right");
  printf("%10s%47s\n", "||", "left to right");
  printf("%10s%47s\n", "?:", "right to left");
  printf("%41s%16s\n", "= += -= *= /= %= <<= >>= &= ^= |=", "right to left");
  printf("%9s%48s\n", ",", "left to right");
  printf("\n");

  return 0;
}