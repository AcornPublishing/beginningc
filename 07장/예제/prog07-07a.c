/* ���α׷� 7.7A 2���� �迭 */
#include <stdio.h>

void main()
{
	char board[3][3] = 	{ 
							{'1','2','3'}, 
							{'4','5','6'}, 
							{'7','8','9'} 
						}; 

	printf("board[0][0]�� �� : %c\n", board[0][0]);
	printf("board[0]�� ��    : %c\n", *board[0]);
	printf("board�� ��       : %c\n", **board); 
} 
