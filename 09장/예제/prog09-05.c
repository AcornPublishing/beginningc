/* ���α׷� 9.5 �������� */ 
#include <stdio.h> 

int count = 0; 													/* ���������� ���� */

/* �Լ����� */ 
void test1(void); 
void test2(void); 

void main() 
{ 
	int count = 0; 												/* ���������� ���� */

	for( ; count < 5; count++) 
	{
		test1();
		test2();
	} 
} 

/* ���������� ����ϴ� �Լ� test1 */
void test1(void)
{
	printf("\ntest1 		count = %d ", ++count); 
} 

/* ���������� ����ϴ� �Լ� test2 */
void test2(void)
{
	static int count; 											/* ���������� ���� */ 
	printf("\ntest2 		count = %d ", ++count); 
} 
