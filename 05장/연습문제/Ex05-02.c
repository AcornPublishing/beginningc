/*연습문제 5.2 100개의 데이터 */
#include <stdio.h>

void main()
{
  double data[100];                    /* 데이터 저장      */
  double sum = 0.0;                    /* 역수의 합을 저장 */
  int i = 0;                           /* 루프 인덱스      */
  double sign = 1.0;

  for(i = 1 ; i<=100 ; i++)
    data[i-1] = 1.0/(2*i*(2*i+1)*(2*i+2));

  for(i = 0 ; i<100 ; i++)
  {
    sum += sign*data[i];
    sign = -sign;
  }
  /* 계산결과는 pi의 값과 같다. 흥미롭지 않은가? */
  printf("\n결과는 %.4lf입니다.\n", 4.0*sum+3);
}

