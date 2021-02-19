/* 프로그램 7.3 scanf에 들어가는 포인터 인자 */ 
#include <stdio.h> 

void main() 
{ 
	int value = 0; 
	int *pvalue = NULL; 

	pvalue = &value; 									/* 포인터가 value를 참조하도록 설정	*/ 

	printf ("정수를 입력하세요: "); 
	scanf(" %d", pvalue); 								/* 포인터를 통해 값을 읽어들임		*/ 

	printf("\n%d를 입력하셨습니다.\n", value); 			/* 입력받은 값을 출력 				*/ 
} 
