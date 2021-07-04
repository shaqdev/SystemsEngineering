#include <stdio.h>

void itoa_rex(int, char []);
void reverse_rex(char [], int, int);
void swap(char [], int, int);

int main()
{
  int val, low, len;
  val = -25657;
  char str[10];

  itoa_rex(val, str);
  len = 0;
  for (int i =0; str[i] != '\0'; ++i)
    ++len;
  reverse_rex(str, 0, len - 1);

  printf("itoa_rex of val, %d : %s\n", val, str);
  return 0;
}

void itoa_rex(int val, char s[]){
  static int i = 0;
  if (val < 0){
    s[i++] = '-';
    val = -val;
  }

  if (val/10){
    itoa_rex(val/10, s);
  }

  s[i++] = (val % 10) + '0';
  s[i] = '\0';
}

void reverse_rex(char s[], int low, int high){
   if (low >= high){
     return;
   }
   if (low < high){
     swap(s, low, high);
     low++;
     high--;
   }
   reverse_rex(s, low, high);

}

void swap(char s[], int low, int high){
  char tmp = s[high];
  s[high] = s[low];
  s[low] = tmp;
}