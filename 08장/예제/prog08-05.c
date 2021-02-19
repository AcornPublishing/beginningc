/* 프로그램 8.5 이루어질 수 있는 사랑 */ 
#include <stdio.h> 	

int change(int* pnumber); 									/* 함수 원형 				*/ 

void main() 	
{ 	
	int number = 10; 										/* 시작값 					*/ 
	int* pnumber = &number; 								/* 시작값을 가리키는 포인터	*/ 
	int result = 0; 										/* 반환값을 저장할 변수 	*/ 

	result = change(pnumber); 		
	printf("\n함수 main에서 result = %d\tnumber = %d", result, number); 
} 

/* 함수 change()의 정의 */
int change(int* pnumber)
{
	*pnumber *= 2;
	printf("\n함수 change에서 *pnumber = %d\n", *pnumber );
	return *pnumber;
} 
