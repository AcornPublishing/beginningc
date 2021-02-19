/* 프로그램 4.2 상자 그리기 */ 
#include <stdio.h> 

void main() 
{ 
	int count = 0; 
	printf("\n***************"); 					/* 상자 위쪽 그리기	*/ 

	for(count = 1 ; count <= 8 ; ++count) 
		printf("\n*             *"); 				/* 상자 옆쪽 그리기	*/ 

	printf("\n***************\n"); 					/* 상자 바닥 그리기	*/ 
} 			
