/* ���α׷� 9.6 ��͸� �̿��� ��� ��� */ 
#include <stdio.h> 

long factorial(long); 

void main() 
{ 
	long number = 0; 
	printf("\n������ �ϳ� �Է��ϼ���: "); 
	scanf(" %ld", &number); 
	printf("\n%ld�� ����� %ld�Դϴ�.\n", number, factorial(number)); 
} 

/* ����� ���ϴ� ����Լ� */
long factorial(long n)
{
	if(n < 2) 
		return n; 
	else 
		return n*factorial(n - 1); 
} 
