/*�������� 5.2 100���� ������ */
#include <stdio.h>

void main()
{
  double data[100];                    /* ������ ����      */
  double sum = 0.0;                    /* ������ ���� ���� */
  int i = 0;                           /* ���� �ε���      */
  double sign = 1.0;

  for(i = 1 ; i<=100 ; i++)
    data[i-1] = 1.0/(2*i*(2*i+1)*(2*i+2));

  for(i = 0 ; i<100 ; i++)
  {
    sum += sign*data[i];
    sign = -sign;
  }
  /* ������� pi�� ���� ����. ��̷��� ������? */
  printf("\n����� %.4lf�Դϴ�.\n", 4.0*sum+3);
}

