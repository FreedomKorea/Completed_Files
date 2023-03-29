#include <stdio.h>
#define MAXLENGTH 10

int arrex(int arr[], int a); //함수 배열

int main()
{
  int i;
  int numarr[MAXLENGTH];

  arrex(numarr, MAXLENGTH); // (배열이름, 배열 길이) (배열 이름[], )는 아님

  for(i=0; i<MAXLENGTH; i++) {
    printf(" %d", numarr[i]);
  }

  return 0;
}

int arrex(int arr[], int a)
{
  int i, sum;

  for(i=1; i<=10; i++) {
    sum = i * 2; // 각 배열 원소에 2를 곱한 값을 sum에 대입
    arr[i-1]=sum; // i-1은 배열 요서 0부터 시작
  }

}