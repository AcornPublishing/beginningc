/* �������� 3.3 ���ε� ���� ��� */
#include <stdio.h>

void main()
{
  	const int level1 = 30;           /* 30�� �ʰ� ���ź��� �������� discount1 */
	const int level2 = 50;           /* 50�� �ʰ� ���ź��� �������� discount2 */
	const double discount1 = 0.10;   /* 10% ���� */
	const double discount2 = 0.15;   /* 15% ���� */
	const double unit_price = 5000.;
	int quantity = 0;
	int qty_over_level1 = 0;
	int qty_over_level2 = 0;
	printf("���ϴ� ������ �Է��ϼ���: ");
	scanf("%d", &quantity);

	if(quantity > level1)							/* ���ż����� 30�� �̻��̸� */
	{
		qty_over_level1 = quantity - level1;		/* 30���� �ʰ��ϴ� ���� ��� */

		if(quantity > level2)						/* ���ż����� 50�� �̻��̸� */
		{
	  		qty_over_level2 = quantity - level2;	/* 50���� �ʰ��ϴ� ���� ��� */
			qty_over_level1 = level2 - level1;		/* �̶� qty_over_level1�� �ڵ����� 20���� ��*/
		}
	}

	printf("\n%d���� �����Ͻø� ���%.0lf���Դϴ�.\n", quantity,
		unit_price*(quantity - discount1*qty_over_level1 - discount2*qty_over_level2));
}
