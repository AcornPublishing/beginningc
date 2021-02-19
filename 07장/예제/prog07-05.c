/* 프로그램 7.5 배열과 포인터 2탄 */ 
#include <stdio.h> 

void main() 
{
 
	char multiple[] = "abcdefg";

	printf("\n두번째 요소의 값 : %c\n", multiple[1]); 
	printf("multiple에 1을 더한 주소의 값 : %c\n", *(multiple + 1)); 
} 
