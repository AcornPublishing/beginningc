/* ���α׷� 7.9 ������ �迭�� ������ */ 
#include <stdio.h> 

void main() 
{ 
	int i = 0; 										/* ���� ī���� */ 
	char board[3][3] = 	{ 
							{'1','2','3'}, 
							{'4','5','6'}, 
							{'7','8','9'} 
						}; 

	char *pointer = *board; 						/* char�� ������ */ 

	for(i = 0; i < 9; i++) 
		printf("board: %c\n", *(pointer + i)); 
} 
