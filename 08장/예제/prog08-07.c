/* 프로그램 8.7 월급을 올려주는 함수 */ 
#include <stdio.h> 

long *IncomePlus(long* pPay); 							/* IncomePlus 함수의 원형 		*/ 

void main() 
{ 	
	long your_pay = 300L; 								/* 이전의 월급 					*/ 
	long *pold_pay = &your_pay; 						/* your_pay를 가리키는 포인터	*/ 
	long *pnew_pay = NULL; 								/* 반환값을 저장할 포인터 		*/ 

	pnew_pay = IncomePlus(pold_pay);
	printf("\n이전 월급 = %ld만원", *pold_pay);
	printf("   새 월급 = %ld만원\n", *pnew_pay);
}

/* 인상된 월급을 계산하는 함수 정의 */
long *IncomePlus(long *pPay)
{
	*pPay += 100L; 										/* 월급을 인상함 				*/ 
	return pPay; 										/* 주소를 반환 					*/ 
} 
