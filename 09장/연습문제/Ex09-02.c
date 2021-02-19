/* �������� 9.2 �迭 ����� ��� */
#include <stdio.h>

double add(double a, double b);      /* a+b ��ȯ */
double subtract(double a, double b); /* a-b ��ȯ */
double multiply(double a, double b); /* a*b ��ȯ */
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

/* a+b�� ����ϴ� �Լ� */
double add(double a, double b)
{
  return a+b;
}

/* a-b�� ����ϴ� �Լ� */
double subtract(double a, double b)
{
  return a-b;
}

/* a*b�� ����ϴ� �Լ� */
double multiply(double a, double b)
{
  return a*b;
}

/* �迭�� ��� ���� �����ϴ� �Լ� */
double array_op(double array[], int size, double (*pfun)(double,double))
{
  double result = array[size-1];
  int i = 0;
  /* ������ ��Һ��� ���ʷ� ����� ������ ���ϴ� ��� �ǵ��� �� */
  for(i = size-1 ; i>0 ; i--)
    result = pfun(array[i-1], result);
  return result;
}
