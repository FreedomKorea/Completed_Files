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
#define SCREEN 1
#define FILEOUTPUT 2
#define BOTH 3

int main(int argc, char *argv[])
{ 

  char kwno[12][2]={
    {'C',' '},
    {'C','#'},
    {'D',' '},
    {'D','#'},
    {'E',' '},
    {'F',' '},
    {'F','#'},
    {'G',' '},
    {'G','#'},
    {'A',' '},
    {'A','#'},
    {'B',' '},
  };
int i;
float kVal[12]={-9.0, -8.0, -7.0, -6.0, -5.0, -4.0, -3.0, -2.0, -1.0, 0.0, 1, 2};

printf(" 12 Sound Scale Table\n");
printf(" 1 Screen Output. 2 File Output. 3 Both\n\n");

scanf("%d", &i);
FILE *fp;

switch(i) {
  case SCREEN:
    printf("       440Hz     432Hz\n");
    for(int i=0; i<=11; i++)
      printf("%c%c   %.3f   %.3f\n", kwno[i][0], kwno[i][1], 440 * pow(2, kVal[i] / 12.0), 432 * pow(2, kVal[i] / 12.0));
    break;
  case FILEOUTPUT:
    fp = fopen("sound_scale.txt", "w");

    if(fp == NULL)
      printf("The file could not be opened.\n");
    else {
    fputs("       440Hz     432Hz\n", fp);
    for(int i=0; i<=11; i++) {
      fprintf(fp, "%c%c   %.3f   %.3f\n", kwno[i][0], kwno[i][1], 440 * pow(2, kVal[i] / 12.0), 432 * pow(2, kVal[i] / 12.0));
      } /* kwno 문자 출력 440 주파수 공식. 432 주파수 공식*/
    }
    fclose(fp);

    printf("\nsound_scale.txt\n");
    printf("File save complete.\n");
    break;
  case BOTH:
    fp = fopen("sound_scale.txt", "w");

    if(fp == NULL)
      printf("The file could not be opened.\n");
    else {
    fputs("       440Hz     432Hz\n", fp);
    for(int i=0; i<=11; i++) {
      fprintf(fp, "%c%c   %.3f   %.3f\n", kwno[i][0], kwno[i][1], 440 * pow(2, kVal[i] / 12.0), 432 * pow(2, kVal[i] / 12.0));
      } /* kwno 문자 출력 440 주파수 공식. 432 주파수 공식*/
    }

    printf("       440Hz     432Hz\n");
      for(int i=0; i<=11; i++) {
        printf("%c%c   %.3f   %.3f\n", kwno[i][0], kwno[i][1], 440 * pow(2, kVal[i] / 12.0), 432 * pow(2, kVal[i] / 12.0));
    } /* kwno 문자 출력 440 주파수 공식. 432 주파수 공식*/

    fclose(fp);

    printf("\nsound_scale.txt\n");
    printf("File save complete.\n");
    break;

  default: break;
}

return 0;
}