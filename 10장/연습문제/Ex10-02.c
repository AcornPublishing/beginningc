/* �������� 10.2 �� ��� */
/*
  �Է� ���� ���ڿ����� '$', �����̽�, ��ǥ�� �����ϸ� ��
*/
#include <stdio.h>

void main()
{
  double amounts[4] = {0.0};
  double total = 0.0;
  int i = 0;

   printf("4���� ���� �Է��ϼ���:\n");
   for(i = 0 ; i<4 ; i++)
   {
     scanf("%*[ ,$]%lf", &amounts[i]);
     total += amounts[i];
   }
     
   printf("�Է��Ͻ� ���� �հ�� $%.2lf�Դϴ�.\n", total);
}

