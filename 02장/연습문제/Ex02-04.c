/* �������� 2.4  �ð��� ����ӱ� ��� */
#include <stdio.h>

void main()
{
  int pay = 0;                     /* ����            */
  int hours = 0;                   /* �� �ٹ� �ð�	  */
  double payperhour = 0.0;         /* �ð��� ����ӱ� */

   /* ���� �Է� */
   printf("������ �Է��ϼ���: ");
   scanf("%d", &pay);

  /* �ٹ��ð� �Է� */
   printf("�� �ٹ��ð��� �Է��ϼ���: ");
   scanf("%d", &hours);

   /* ����ӱ� ��� */
   payperhour = (double)pay/(double)hours;

   /* �ð��� ����ӱ� ��� */
   printf("����� �ð��� ����ӱ��� %.2f���Դϴ�.\n", payperhour);
}
