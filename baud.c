#include <stdio.h>

int baud[16]={ 1200,  2400,  3600,   4800,   7200,   9600,  14400,   19200,
							28800, 38400, 57600, 115200, 230400, 250000, 512000, 1024000};
							/* 115200 이후 부터는 정화한 수치 아님*/

float spl[12]={1, 1.8432, 2, 3.6864, 4, 7.3728, 8, 11.0592, 12, 14.7456, 16, 20};

float fosc[12]={1000000,  1843200,  2000000,  3686400,  4000000, 7372800,
							  8000000, 11059200, 12000000, 14745600, 16000000, 20000000};
							/*   1Mhz, 1.8432Mhz,  2Mhz, 3.6864Mhz,  4Mhz, 7.3728Mhz
							     8Mhz, 110592Mhz, 12Mhz, 14.7456Mhz, 16Mhz, 20Mhz*/

int crystal();
int printbaud();

int main(int argc, char *argv[])
{
	int i, num;
	
	float result16, result8, result;

	printf("\n  Microchip AVR Baud Calculator\n\n");
	printf("  Select the frequency of Fosc\n\n");

	crystal();
	printbaud();
	
	//printf("\n\n");

	printf(" (* is not an exact number)\n\n"); // *표시는 정확한 수치 아님

	printf(" Fosc : ");
	scanf("%d", &num);

	printf("\t\t\t\t%7.4fMhz\n", spl[num-1]);

	for(i=0; i<43; i++)
		putchar('-');
	putchar('\n');

	printf("        BAUD  Async X1  Async X2       Sync\n");
	for(i=0; i<16; i++) {
		result16 = ( (fosc[num-1]/baud[i])/16.0 )-1.0; // Asynchronous X1
		result8  = ( (fosc[num-1]/baud[i])/ 8.0 )-1.0; // Asynchronous X2
		result   = ( (fosc[num-1]/baud[i])/ 2.0 )-1.0; // Synchronous

		printf(" %2d %8d  %6.2f     %7.2f    %7.2f\n", i+1, baud[i], result16, result8, result);
	}
	
  return 0;	
}

int crystal() /* crystal 주파수 화면 출력 함수 */
{
	int i;

	for(i=0; i<6; i++)
		printf(" %2d) %7.4fMhz", i+1, spl[i]);
	putchar('\n');
	for(i=6; i<12; i++)
		printf(" %2d) %7.4fMhz", i+1, spl[i]);
	printf("\n\n");
}

int printbaud() /* Baud 속도 화면 출력 함수*/
{
	int i;

	for(i=0; i<16; i++) {
		if(i>11)
			printf(" %2d %8d *\n", i+1, baud[i]);
		else
			printf(" %2d %8d\n", i+1, baud[i]); // 230400 부터 * 표시
		}
}