/* 프로그램 5.7 틱택토 */ 
#include <stdio.h> 

void main() 
{ 
	int i = 0; 															/* 루프 카운터 					*/	
	int player = 0; 													/* 플레이어 번호 - 1이나 2		*/	
	int winner = 0; 													/* 승리한 플레이어 				*/	
	int choice = 0; 													/* 선택한 격자 번호				*/
	int row = 0; 														/* 격자의 행 인덱스 번호		*/
	int column = 0; 													/* 격자의 열 인덱스 번호		*/
	int line = 0;														/* 검사 루프에서 행/열 인덱스	*/

	char board[3][3] = { 												/* 말판 						*/	
		{'1','2','3'}, 													/* 이 배열의 초기값은 			*/ 
		{'4','5','6'}, 													/* 말판에서 빈 칸을 알려주는	*/ 
		{'7','8','9'} 													/* 격자 번호다. 				*/ 
	}; 		

	/* 메인 게임 루프 */
	/* 승자가 결정되지 않으면 게임은 9회에 끝난다.*/
	for( i = 0; i<9 && winner==0; i++)
	{
		/* 말판 출력 */
		printf("\n\n");
		printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
		printf("--+--+--\n");
		printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
		printf("--+--+--\n");
		printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
			
		player = i%2 + 1; 												/* 플레이어 선택 */

		/* 플레이어가 올바른 격자를 선택하게 함 */
		do
		{
			printf("\n플레이어 %d님이 말을 놓을 차례입니다. " 
				"말 %c를 놓을 위치의 번호를 입력해주세요: ", 
				player,(player==1)?'X':'O'); 
			scanf("%d", &choice); 
			
			row = --choice/3; 											/* 격자의 행 인덱스 값을 구함 */ 
			column = choice%3; 											/* 격자의 열 인덱스 값을 구함 */
		}while(choice<0 || choice>9 || board[row][column]>'9'); 
		
		/* 플레이어의 말을 출력 */
		board[row][column] = (player == 1) ? 'X' : 'O'; 

		/* 먼저 대각선에서 일렬로 늘어선 말이 있는지 검사 */ 
		if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||
			(board[0][2]==board[1][1] && board[0][2]==board[2][0]))
			winner = player;

		else
			/* 가로, 세로 방향 검사 */
			for(line = 0; line <= 2; line ++)
				if((board[line][0]==board[line][1] && 
						board[line][0]==board[line][2])||
					(board[0][line]==board[1][line] && 
						board[0][line]==board[2][line]))
					winner = player;
	} 
	/* 게임이 끝났으므로 말판의 마지막 상태를 출력한다. */
	printf("\n\n");
	printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("--+--+--\n");
	printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("--+--+--\n");
	printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]); 

	/* 결과 메시지 출력 */
	if(winner == 0)
		printf("\n아쉽게도 비겼습니다.\n");
	else
		printf("\n축하합니다, 플레이어 %d님. 당신이 승리했습니다!\n", 	winner);
} 
