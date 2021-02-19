/* 프로그램 9.6 재귀를 이용한 계승 계산 */ 
#include <stdio.h> 

long factorial(long); 

void main() 
{ 
	long number = 0; 
	printf("\n정수를 하나 입력하세요: "); 
	scanf(" %ld", &number); 
	printf("\n%ld의 계승은 %ld입니다.\n", number, factorial(number)); 
} 

/* 계승을 구하는 재귀함수 */
long factorial(long n)
{
	if(n < 2) 
		return n; 
	else 
		return n*factorial(n - 1); 
} 
