/* 프로그램 7.7A 2차원 배열 */
#include <stdio.h>

void main()
{
	char board[3][3] = 	{ 
							{'1','2','3'}, 
							{'4','5','6'}, 
							{'7','8','9'} 
						}; 

	printf("board[0][0]의 값 : %c\n", board[0][0]);
	printf("board[0]의 값    : %c\n", *board[0]);
	printf("board의 값       : %c\n", **board); 
} 
