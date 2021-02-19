/* 프로그램 7.7 2차원 배열과 포인터 */ 
#include <stdio.h> 

void main() { 
	char board[3][3] = 	{
							{'1','2','3'},
							{'4','5','6'},
							{'7','8','9'}
						}; 

	printf("board의 주소            : %p\n", board);
	printf("board[0][0]의 주소      : %p\n", &board[0][0]);
	printf("board[0]에 들어있는 값  : %p\n", board[0]);
} 
