/* 프로그램 9.2 함수 포인터의 배열 */ 
#include <stdio.h> 

 /* 함수원형 */
int sum(int, int);
 
int product(int, int);
int difference(int, int);

void main() 
{ 
	int i = 0; 														/* 루프 카운터 				*/ 
	int a = 10; 													/* a의 초기값 				*/ 
	int b = 5; 														/* b의 초기값 				*/ 
	int result = 0; 												/* 결과를 저장할 변수 		*/ 
	int (*pfun[3])(int, int); 										/* 함수 포인터 배열을 선언	*/ 

	/* 포인터 초기화 */
	pfun[0] = sum;
	pfun[1] = product;
	pfun[2] = difference;

	/* 포인터가 가리키는 함수를 실행 */
	for( i = 0 ; i < 3 ; i++)
	{
		result = pfun[i](a, b); 									/* 포인터를 통해 함수를 호출*/ 
		printf("\nresult = %d", result); 							/* 결과 출력 				*/ 
	} 

	/* 하나의 표현식에서 포인터를 이용해 3개의 함수를 모두 호출 */
	result = pfun[1](pfun[0](a, b), pfun[2](a, b));
	printf("\n\nsum과 difference를 곱한 값 = %d\n", result); 
} 

/* 함수 sum의 정의 */
int sum(int x, int y)
{
	return x + y;
}

/* 함수 product의 정의 */
int product(int x, int y)
{
	return x * y;
}

/* 함수 difference의 정의 */
int difference(int x, int y)
{
	return x - y;
}
