/* ���α׷� 8.5 �̷���� �� �ִ� ��� */ 
#include <stdio.h> 	

int change(int* pnumber); 									/* �Լ� ���� 				*/ 

void main() 	
{ 	
	int number = 10; 										/* ���۰� 					*/ 
	int* pnumber = &number; 								/* ���۰��� ����Ű�� ������	*/ 
	int result = 0; 										/* ��ȯ���� ������ ���� 	*/ 

	result = change(pnumber); 		
	printf("\n�Լ� main���� result = %d\tnumber = %d", result, number); 
} 

/* �Լ� change()�� ���� */
int change(int* pnumber)
{
	*pnumber *= 2;
	printf("\n�Լ� change���� *pnumber = %d\n", *pnumber );
	return *pnumber;
} 
