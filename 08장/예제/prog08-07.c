/* ���α׷� 8.7 ������ �÷��ִ� �Լ� */ 
#include <stdio.h> 

long *IncomePlus(long* pPay); 							/* IncomePlus �Լ��� ���� 		*/ 

void main() 
{ 	
	long your_pay = 300L; 								/* ������ ���� 					*/ 
	long *pold_pay = &your_pay; 						/* your_pay�� ����Ű�� ������	*/ 
	long *pnew_pay = NULL; 								/* ��ȯ���� ������ ������ 		*/ 

	pnew_pay = IncomePlus(pold_pay);
	printf("\n���� ���� = %ld����", *pold_pay);
	printf("   �� ���� = %ld����\n", *pnew_pay);
}

/* �λ�� ������ ����ϴ� �Լ� ���� */
long *IncomePlus(long *pPay)
{
	*pPay += 100L; 										/* ������ �λ��� 				*/ 
	return pPay; 										/* �ּҸ� ��ȯ 					*/ 
} 
