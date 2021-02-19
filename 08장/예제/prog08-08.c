/* 프로그램 8.8 월급을 올려주는 함수지만... */ 
#include <stdio.h> 

long *IncomePlus(long* pPay); 						/* IncomePlus 함수의 원형 		*/ 

void main() 
{ 	
	long your_pay = 300L; 							/* 이전의 월급 					*/ 
	long *pold_pay = &your_pay; 					/* your_pay를 가리키는 포인터	*/ 
	long *pnew_pay = NULL; 							/* 반환값을 저장할 포인터 		*/ 

	pnew_pay = IncomePlus( pold_pay );
	printf("\n이전 월급 = %ld만원", *pold_pay);
	printf("		새 월급 = %ld만원\n", *pnew_pay);
}

/* 인상된 월급을 계산하는 함수 정의 */
long *IncomePlus(long *pPay)
{
	long pay = 0; 									/* 결과를 저장할 지역변수		*/

	pay = *pPay + 100; 								/* 월급여를 증가시킴 			*/ 
	return &pay; 									/* 주소를 반환 					*/ 
} 
