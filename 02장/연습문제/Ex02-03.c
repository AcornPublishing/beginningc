/* �������� 2.3  ��ǰ �ܰ� ��� */

#include <stdio.h>

void main()
{
  int total_price = 0;                     /* ��ü ����   */
  int type = 0;                            /* ��ǰ ����   */
  int quantity = 0;                        /* �ֹ��� ���� */
  const int type1_price = 5000;
  const int type2_price = 8000;

   /* ��ǰ ���� �Է� */
   printf("��ǰ�� ������ �Է��ϼ��� (�Ϲ���-1, �����-2): ");
   scanf("%d", &type);

   /* ��ǰ ���� �Է� */
   printf("��ǰ�� ������ �Է��ϼ���: ");
   scanf("%d", &quantity);

   /* ��ü ���� ��� */
   total_price = quantity*(type1_price + (type-1)*(type2_price-type1_price));

   /* ���� ��� */
   printf("%d�� ��ǰ  %d���� ������ %d���Դϴ�.\n",
     type, quantity, total_price);
}
