/* ���α׷� 9.2 �Լ� �������� �迭 */ 
#include <stdio.h> 

 /* �Լ����� */
int sum(int, int);
 
int product(int, int);
int difference(int, int);

void main() 
{ 
	int i = 0; 														/* ���� ī���� 				*/ 
	int a = 10; 													/* a�� �ʱⰪ 				*/ 
	int b = 5; 														/* b�� �ʱⰪ 				*/ 
	int result = 0; 												/* ����� ������ ���� 		*/ 
	int (*pfun[3])(int, int); 										/* �Լ� ������ �迭�� ����	*/ 

	/* ������ �ʱ�ȭ */
	pfun[0] = sum;
	pfun[1] = product;
	pfun[2] = difference;

	/* �����Ͱ� ����Ű�� �Լ��� ���� */
	for( i = 0 ; i < 3 ; i++)
	{
		result = pfun[i](a, b); 									/* �����͸� ���� �Լ��� ȣ��*/ 
		printf("\nresult = %d", result); 							/* ��� ��� 				*/ 
	} 

	/* �ϳ��� ǥ���Ŀ��� �����͸� �̿��� 3���� �Լ��� ��� ȣ�� */
	result = pfun[1](pfun[0](a, b), pfun[2](a, b));
	printf("\n\nsum�� difference�� ���� �� = %d\n", result); 
} 

/* �Լ� sum�� ���� */
int sum(int x, int y)
{
	return x + y;
}

/* �Լ� product�� ���� */
int product(int x, int y)
{
	return x * y;
}

/* �Լ� difference�� ���� */
int difference(int x, int y)
{
	return x - y;
}
