/* 연습문제 9.2 배열 요소의 산술 */
#include <stdio.h>

double add(double a, double b);      /* a+b 반환 */
double subtract(double a, double b); /* a-b 반환 */
double multiply(double a, double b); /* a*b 반환 */
double array_op(double array[], int size, double (*pfun)(double,double));


void main()
{
  double array[] = {11.0, 10.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
  int i = 0;
  int length = sizeof array/sizeof(double);

  for(i = 0 ; i< length ; i++)
  {
    printf("%.2lf%s", array[i], (i<length-1?" + ":"\n"));
  }
  printf(" = %.2lf\n", array_op(array,length,add));

  for(i = 0 ; i< length ; i++)
  {
    printf("%.2lf%s", array[i], (i<length-1?(i%2==0?" - ":" + "):"\n"));
  }
  printf(" = %.2lf\n", array_op(array, length, subtract));

  for(i = 0 ; i< length ; i++)
  {
    printf("%.2lf%s", array[i], (i<length-1?" * ":"\n"));
  }
  printf(" = %.2lf\n", array_op(array, length, multiply));
}

/* a+b를 계산하는 함수 */
double add(double a, double b)
{
  return a+b;
}

/* a-b를 계산하는 함수 */
double subtract(double a, double b)
{
  return a-b;
}

/* a*b를 계산하는 함수 */
double multiply(double a, double b)
{
  return a*b;
}

/* 배열의 모든 값을 연산하는 함수 */
double array_op(double array[], int size, double (*pfun)(double,double))
{
  double result = array[size-1];
  int i = 0;
  /* 마지막 요소부터 차례로 계산해 뺄셈이 원하는 대로 되도록 함 */
  for(i = size-1 ; i>0 ; i--)
    result = pfun(array[i-1], result);
  return result;
}
