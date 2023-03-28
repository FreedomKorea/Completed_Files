#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j;
	int baud[16]={  1200,  2400,   3600,    4800,  7200,   9600,
							 14400, 19200,  28800,   38400, 57600, 115200,
							230400, 25000, 512000, 1024000};
							/* 115200 이후 부터는 정화한 수치 아님*/
	float fosc[11]={1000000,  1843200,  2000000,  3686400,  4000000, 7372800,
								  8000000, 11059200, 12000000, 14745600, 16000000};
							/*   1Mhz, 1.8432Mhz,  2Mhz, 3.6864Mhz,  4Mhz, 7.3728Mhz
							     8Mhz, 110592Mhz, 12Mhz, 14.7456Mhz, 16Mhz*/
	float result=0;

	
		result = ((fosc[6]/(8*9600))-1.0);
		printf("%7d %.2f\n", baud[5], result);
	
	
  return 0;	
}

/*result = ( (fosc[0]/baud[i])/16.0 )-1.0; // 비동기 1배속
	result = ( (fosc[0]/baud[i])/ 8.0 )-1.0;  // 비동기 2배속
	result = ( (fosc[0]/baud[i])/ 2.0 )-1.0;  // 동기
*/