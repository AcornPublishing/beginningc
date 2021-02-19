/* 프로그램 9.4 정적변수와 자동변수 */ 
#include <stdio.h> 

/* 함수원형 */ 
void test1(void); 
void test2(void); 

void main() 
{ 
	int i = 0; 

	for( i = 0; i < 5; i++ ) 
	{
		test1();
		test2();
	} 
} 

/* 자동변수가 있는 함수 test1 */
void test1(void)
{
	int count = 0; 
	printf("\ntest1 		count = %d ", ++count ); 
} 

/* 정적변수가 있는 함수 test2 */
void test2(void)
{
	static int count = 0; 
	printf("\ntest2 		count = %d ", ++count ); 
} 
