/* �������� 9.1 ������ �Լ��� ��ͷ� ���� */
#include <stdio.h>

double power(double x, int n);


void main()
{
  double x = 0.0;
  int n = 0;
  for(x = 2.0 ; x<= 5.0; x += 0.5)
    for(n = 0 ; n<5 ; n++)
      printf("%.2lf�� %d������ %.2lf�Դϴ�.\n", x, n, power(x,n));
}

/* x�� n ������ ���ϴ� �Լ�*/
double power(double x, int n)
{
  if(n == 0)
    return 1.0;
  else
    return x*power(x,n-1);
}