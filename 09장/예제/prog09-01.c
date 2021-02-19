/* ���α׷� 9.1 �Լ� ������ */ 
#include <stdio.h> 

/* �Լ����� */ 
int sum(int, int); 
int product(int, int); 
int difference(int, int); 

void main() 
{ 
	int a = 10; 											/* a�� �ʱⰪ							*/ 
	int b = 5; 												/* b�� �ʱⰪ							*/
	int result = 0; 										/* ����� ������ ���� 					*/
	int (*pfun)(int, int); 									/* �Լ� ������ ����						*/ 

	pfun = sum; 											/* �Լ� sum()�� ����Ŵ 					*/
	result = pfun(a, b); 									/* �����͸� ���� sum()�� ȣ�� 			*/
	printf("\npfun = sum          result = %d", result);

	pfun = product; 										/* �Լ� product()�� ����Ŵ 				*/
	result = pfun(a, b); 									/* �����͸� ���� product()�� ȣ�� 		*/
	printf("\npfun = product      result = %d", result);

	pfun = difference; 										/* �Լ� difference()�� ����Ŵ 			*/
	result = pfun(a, b); 									/* �����͸� ���� difference()�� ȣ��	*/
	printf("\npfun = difference   result = %d\n", result);  
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
