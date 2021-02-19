/* 프로그램 2.14 char형을 이용한 산술연산 */ 
#include <stdio.h> 

void main() 
{ 
	char first = 'A'; 
	char second = 'B'; 
	char last = 'Z'; 
	char number = 40; 

	char ex1 = first + 2; 					/* 'A'에 2를 더함	*/
	char ex2 = second - 1; 					/* 'B'에서 1을 뺌 	*/
	char ex3 = last + 2; 					/* 'Z'에 2를 더함 	*/ 

	printf("문자의 값           	%-5c%-5c%-5c", ex1, ex2, ex3); 
	printf("\n문자에 해당하는 수	%-5d%-5d%-5d", ex1, ex2, ex3); 
	printf("\n%d은 문자 %c의 문자코드입니다.\n", number, number); 
} 
