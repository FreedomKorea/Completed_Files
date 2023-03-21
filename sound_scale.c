/*  12음계 Table
 *   https://kwanulee.github.io/iot/docs/sound_control/sound_control.html
 *
 *   C   도   261.63 Hz   440 X 2^(-9/12)
 *   C#       277.18 Hz   440 X 2^(-8/12)
 *   D   레   293.66 Hz   440 X 2^(-7/12)
 *   D#       311.13 Hz   440 X 2^(-6/12)
 *   E   미   329.63 Hz   440 X 2^(-5/12)
 *   F   파   349.23 Hz   440 X 2^(-4/12)
 *   F#       369.99 Hz   440 X 2^(-3/12)
 *   G   솔   392.00 Hz   440 X 2^(-2/12)
 *   G#       415.30 Hz   440 X 2^(-1/12)
 *   A   라   440.00 Hz   440 X 2^(0/12)
 *   A#       446.16 Hz   440 X 2^(1/12)
 *   B   시   493.88 Hz   440 X 2^(2/12)
 *
 */

#include <stdio.h>
#include <math.h> // pow();

int kValNo440(int i)
{
  double kVal[12]={-9.0, -8.0, -7.0, -6.0, -5.0, -4.0, -3.0, -2.0, -1.0, 0.0, 1, 2};
  /* k 값의 배열 12가지*/
  printf("%.3lf", 440 * pow(2, kVal[i] / 12.0) );  // not 12
}

int kValNo432(int i)
{
  double kVal[12]={-9.0, -8.0, -7.0, -6.0, -5.0, -4.0, -3.0, -2.0, -1.0, 0.0, 1, 2};
  /* k 값의 배열 12가지*/
  printf("%.3lf", 432 * pow(2, kVal[i] / 12.0) );  // not 12
}

void twno(int i)
{
   if(i == 0)    printf("C ");
   if(i == 1)    printf("C#");
   if(i == 2)    printf("D ");
   if(i == 3)    printf("D#");
   if(i == 4)    printf("E ");
   if(i == 5)    printf("F ");
   if(i == 6)    printf("F#");
   if(i == 7)    printf("G ");
   if(i == 8)    printf("G#");
   if(i == 9)    printf("A ");
  if(i == 10)    printf("A#");
  if(i == 11)    printf("B ");
  putchar(' ');
}

int main(int argc, char *argv[])
{ 
  printf("\n       440Hz     432Hz\n");

  for(int i=0; i<=11; i++) {
    twno(i); // i 값에 따라 12음계 표시
    printf("  ");
    kValNo440(i); // 440 주파수 공식 
     printf("   ");
    kValNo432(i); // 432 주파수 공식
  putchar('\n');
  } 

  return 0;
}