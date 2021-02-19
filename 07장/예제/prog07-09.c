/* 프로그램 7.9 다차원 배열과 포인터 */ 
#include <stdio.h> 

void main() 
{ 
	int i = 0; 										/* 루프 카운터 */ 
	char board[3][3] = 	{ 
							{'1','2','3'}, 
							{'4','5','6'}, 
							{'7','8','9'} 
						}; 

	char *pointer = *board; 						/* char형 포인터 */ 

	for(i = 0; i < 9; i++) 
		printf("board: %c\n", *(pointer + i)); 
} 
