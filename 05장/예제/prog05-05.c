/* ���α׷� 5.5 & ������ */
#include<stdio.h>

void main()
{
	/* ������ ���� ���� */
	long a = 1L;
	long b = 2L;
	long c = 3L;

	/* �Ǽ��� ���� ���� */
	double d = 4.0;
	double e = 5.0;
	double f = 6.0;

	printf("long�� ������ %d����Ʈ�� �����մϴ�.", sizeof(long));
	printf("\n������ long�� �������� �ּ��Դϴ�.");
	printf("\na�� �ּҴ� %p�̰�, b�� �ּҴ� %p�̸�,", &a, &b);
	printf("\nc�� �ּҴ� %p�Դϴ�.", &c);
	printf("\n\ndouble�� ������ %d����Ʈ�� �����մϴ�.", sizeof(double));
	printf("\n������ double�� �������� �ּ��Դϴ�.");
	printf("\nd�� �ּҴ� %p�̰�, e�� �ּҴ� %p�̸�,", &d, &e);
	printf("\nf�� �ּҴ� %p�Դϴ�.\n", &f);
}
