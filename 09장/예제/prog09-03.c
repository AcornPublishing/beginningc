/* ���α׷� 9.3 �Լ��� ������ �Ѱ��ֱ� */
#include <stdio.h>

/* �Լ����� */
int sum(int,int);
int product(int,int);
int difference(int,int);
int any_function(int(*pfun)(int, int), int x, int y);

void main()
{ 
	int a = 10; 												/* a�� �ʱⰪ 			*/ 
	int b = 5; 													/* b�� �ʱⰪ 			*/ 
	int result = 0; 											/* ����� ������ ����	*/ 
	int (*pf)(int, int) = sum; 									/* �Լ� ������ 			*/ 

	/* �Լ��� ����Ű�� �����͸� �Ѱ��� */
	result = any_function(pf, a, b); 

	printf("\nresult = %d", result ); 

	/* �Լ��� �ּҸ� �Ѱ��� */
	result = any_function(product, a, b); 

	printf("\nresult = %d", result ); 

	printf("\nresult = %d\n", any_function(difference, a, b)); 
} 

/* �Լ��� ȣ���ϴ� �Լ��� ���� */ 
int any_function(int(*pfun)(int, int), int x, int y) 
{ 
	return pfun(x, y); 
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
