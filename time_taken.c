#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
  clock_t start = clock();

  int sum=0;
  
  for(int i=0; i<=1000000000; i++)
    sum += i;  

  clock_t end = clock();
  printf("Time Taken : %lf\n", (double)(end-start)/CLOCKS_PER_SEC );
  
  return 0;
}