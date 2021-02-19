/* 프로그램 8.4 이루어질 수 없는 사랑 */
#include <stdio.h>

int change(int number); 										/* 함수원형 				*/ 

void main() 
{ 
	int number = 10; 											/* 시작값 					*/ 
	int result = 0; 											/* 반환된 값을 저장할 변수	*/ 

	result = change(number); 
	printf("\nmain 함수에서 result = %d\tnumber = %d", result, number); 
} 

/* 함수 change()의 정의 */
int change(int number)
{
	number = 2 * number;
	printf("\nchange 함수에서 number = %d\n", number);
	return number;
} 
