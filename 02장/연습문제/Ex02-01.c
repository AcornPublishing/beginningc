/* �������� 2.1 ��ġ�� �ߵ�, ��Ʈ, ��ġ�� ��ȯ */
#include <stdio.h>

void main()
{
  int inches = 0;
  int yards = 0;
  int feet = 0;
  const int inches_per_foot = 12;
  const int feet_per_yard = 3;
  printf("�Ÿ��� ��ġ ������ �Է��ϼ���: ");
  scanf("%d", &inches);

  feet = inches/inches_per_foot;  /* ��Ʈ ���			*/
  yards = feet/feet_per_yard;     /* �ߵ� ���			*/
  feet %= feet_per_yard;          /* ������ ��Ʈ ���   */
  inches %= inches_per_foot;      /* ������ ��ġ ���   */

  printf("\n�Է��Ͻ� �Ÿ��� %d�ߵ� %d��Ʈ %d��ġ�Դϴ�.\n",
          yards, feet, inches);
}
