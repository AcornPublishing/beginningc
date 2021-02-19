/* 프로그램 9.5 전역변수 */ 
#include <stdio.h> 

int count = 0; 													/* 전역변수를 선언 */

/* 함수원형 */ 
void test1(void); 
void test2(void); 

void main() 
{ 
	int count = 0; 												/* 전역변수를 감춤 */

	for( ; count < 5; count++) 
	{
		test1();
		test2();
	} 
} 

/* 전역변수를 사용하는 함수 test1 */
void test1(void)
{
	printf("\ntest1 		count = %d ", ++count); 
} 

/* 정적변수를 사용하는 함수 test2 */
void test2(void)
{
	static int count; 											/* 전역변수를 감춤 */ 
	printf("\ntest2 		count = %d ", ++count); 
} 
