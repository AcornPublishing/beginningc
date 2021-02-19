/* 프로그램 9.1 함수 포인터 */ 
#include <stdio.h> 

/* 함수원형 */ 
int sum(int, int); 
int product(int, int); 
int difference(int, int); 

void main() 
{ 
	int a = 10; 											/* a의 초기값							*/ 
	int b = 5; 												/* b의 초기값							*/
	int result = 0; 										/* 결과를 저장할 변수 					*/
	int (*pfun)(int, int); 									/* 함수 포인터 선언						*/ 

	pfun = sum; 											/* 함수 sum()을 가리킴 					*/
	result = pfun(a, b); 									/* 포인터를 통해 sum()을 호출 			*/
	printf("\npfun = sum          result = %d", result);

	pfun = product; 										/* 함수 product()를 가리킴 				*/
	result = pfun(a, b); 									/* 포인터를 통해 product()를 호출 		*/
	printf("\npfun = product      result = %d", result);

	pfun = difference; 										/* 함수 difference()를 가리킴 			*/
	result = pfun(a, b); 									/* 포인터를 통해 difference()를 호출	*/
	printf("\npfun = difference   result = %d\n", result);  
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
