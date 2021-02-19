/* 프로그램 7.4 배열과 포인터 - 간단한 프로그램 */ 
#include <stdio.h> 

void main() 
{ 	
	char multiple[] = "I am a string"; 

	printf("\n배열 첫번째 요소의 주소 : %p", &multiple[0]); 
	printf("\n배열 이름이 가리키고 있는 주소 : %p\n", multiple); 
} 		
