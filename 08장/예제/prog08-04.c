/* ���α׷� 8.4 �̷���� �� ���� ��� */
#include <stdio.h>

int change(int number); 										/* �Լ����� 				*/ 

void main() 
{ 
	int number = 10; 											/* ���۰� 					*/ 
	int result = 0; 											/* ��ȯ�� ���� ������ ����	*/ 

	result = change(number); 
	printf("\nmain �Լ����� result = %d\tnumber = %d", result, number); 
} 

/* �Լ� change()�� ���� */
int change(int number)
{
	number = 2 * number;
	printf("\nchange �Լ����� number = %d\n", number);
	return number;
} 
