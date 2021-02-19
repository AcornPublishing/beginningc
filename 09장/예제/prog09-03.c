/* 프로그램 9.3 함수에 포인터 넘겨주기 */
#include <stdio.h>

/* 함수원형 */
int sum(int,int);
int product(int,int);
int difference(int,int);
int any_function(int(*pfun)(int, int), int x, int y);

void main()
{ 
	int a = 10; 												/* a의 초기값 			*/ 
	int b = 5; 													/* b의 초기값 			*/ 
	int result = 0; 											/* 결과를 저장할 변수	*/ 
	int (*pf)(int, int) = sum; 									/* 함수 포인터 			*/ 

	/* 함수를 가리키는 포인터를 넘겨줌 */
	result = any_function(pf, a, b); 

	printf("\nresult = %d", result ); 

	/* 함수의 주소를 넘겨줌 */
	result = any_function(product, a, b); 

	printf("\nresult = %d", result ); 

	printf("\nresult = %d\n", any_function(difference, a, b)); 
} 

/* 함수를 호출하는 함수의 정의 */ 
int any_function(int(*pfun)(int, int), int x, int y) 
{ 
	return pfun(x, y); 
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
