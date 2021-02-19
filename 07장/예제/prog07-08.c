/* 프로그램 7.8 2차원 배열에 있는 모든 값 가져오기 */
#include <stdio.h>

void main() 
{
	int i = 0; 									/* 루프 카운터 */
	char board[3][3] = 	{
							{'1','2','3'},
							{'4','5','6'},
							{'7','8','9'}
						}; 

	/* 모든 배열요소를 출력 */
	for(i = 0; i < 9; i++)
		printf(" board: %c\n", *(*board + i));
}
