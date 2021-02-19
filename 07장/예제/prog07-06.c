/* 프로그램 7.6 다양한 데이터형의 배열 */ 
#include <stdio.h> 

void main() 
{ 
	long multiple[] = {1L, 2L, 3L}; 

	printf("첫번째 요소의 주소는 %p이고, 그 값은 %d입니다.\n", 
					multiple, *multiple); 
	printf("두번째 요소의 주소는 %p이고, 그 값은 %d입니다.\n", 
					multiple + 1, *(multiple + 1)); 
	printf("세번째 요소의 주소는 %p이고, 그 값은 %d입니다.\n", 
					multiple + 2, *(multiple + 2)); 
	printf("    long형은 %d바이트를 차지합니다.\n", sizeof(long)); 
} 
