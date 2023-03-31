#include <stdio.h>
/* 1uF 1000nF 1000000pF*/

int main(int argc, char *argv[])
{
  char cap;
  float num;

  printf(" Capacitor Unit Conversion\n");
  printf(" Capacitor Capacity Input\n");
  printf(" ex) 22u\t10n\t15p\n ");

  scanf("%f%c", &num, &cap);

  putchar('\n');
  
  if(cap == 'u' || cap == 'U')
    printf(" %.5fuF %.4fnF %.1fpF\n", num, num*1000.0, num*1000000);

  if(cap == 'n' || cap == 'N' )
    printf(" %.5fuF %.4fnF %.1fpF\n", num/1000.0, num, num*1000);

  if(cap == 'p' || cap == 'P' )
    printf(" %.5fuF %.4fnF %.1fpF\n", num/1000000.0, num/1000.0, num);

  return 0;
}