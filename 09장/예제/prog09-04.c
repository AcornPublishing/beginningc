/* ���α׷� 9.4 ���������� �ڵ����� */ 
#include <stdio.h> 

/* �Լ����� */ 
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

/* �ڵ������� �ִ� �Լ� test1 */
void test1(void)
{
	int count = 0; 
	printf("\ntest1 		count = %d ", ++count ); 
} 

/* ���������� �ִ� �Լ� test2 */
void test2(void)
{
	static int count = 0; 
	printf("\ntest2 		count = %d ", ++count ); 
} 
