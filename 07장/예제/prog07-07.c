/* ���α׷� 7.7 2���� �迭�� ������ */ 
#include <stdio.h> 

void main() { 
	char board[3][3] = 	{
							{'1','2','3'},
							{'4','5','6'},
							{'7','8','9'}
						}; 

	printf("board�� �ּ�            : %p\n", board);
	printf("board[0][0]�� �ּ�      : %p\n", &board[0][0]);
	printf("board[0]�� ����ִ� ��  : %p\n", board[0]);
} 
