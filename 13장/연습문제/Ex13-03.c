/* �������� 13.3 ǥ������ ���� ����ϴ� ��ũ�� */
#include <stdio.h>

#define print_value(expr) printf("\n" #expr " = %lf", (double)expr);

void main()
{
  int n = 10;
  double y = 5.5;

  print_value(n);
  print_value(y);
  printf("\n");

  print_value(y*y + 4.0);
  print_value(n/2 + 3);
  print_value(3*4 + 12/2 - 8);
  printf("\n");
}

