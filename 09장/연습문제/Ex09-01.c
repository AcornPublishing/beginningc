/* 연습문제 9.1 제곱근 함수를 재귀로 구현 */
#include <stdio.h>

double power(double x, int n);


void main()
{
  double x = 0.0;
  int n = 0;
  for(x = 2.0 ; x<= 5.0; x += 0.5)
    for(n = 0 ; n<5 ; n++)
      printf("%.2lf의 %d제곱은 %.2lf입니다.\n", x, n, power(x,n));
}

/* x의 n 제곱을 구하는 함수*/
double power(double x, int n)
{
  if(n == 0)
    return 1.0;
  else
    return x*power(x,n-1);
}