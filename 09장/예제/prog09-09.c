/* 프로그램 9.9 오델로 게임 */ 
#include <stdio.h> 
#include <ctype.h>

#define SIZE 6 																		/* 말판의 크기 - 반드시 짝수여야 함	*/ 

/* 함수원형 */ 
void display(char board[][SIZE]); 
int valid_moves(char board[][SIZE], int moves[][SIZE], char player);
void make_move(char board[][SIZE], int row, int col, char player); 
void computer_move(char board[][SIZE], int moves[][SIZE], char player); 
int best_move(char board[][SIZE], int moves[][SIZE], char player); 
int get_score(char board[][SIZE], char player); 

void main() 
{ 
	char board [SIZE][SIZE] = { 0 }; 												/* 말판 						*/ 
	int moves [SIZE][SIZE] = { 0 };													/* 말을 놓을 수 있는 격자		*/
	int row = 0; 																	/* 말판의 행 인덱스				*/ 
	int col = 0; 																	/* 말판의 열 인덱스				*/ 
	char again = 0;																	/* 게임을 더 할 것인지 선택 	*/
	int no_of_games = 0; 															/* 게임 회수 					*/
	int no_of_moves = 0; 															/* 말을 놓은 회수 				*/
	int invalid_moves = 0; 															/* 올바르지 않은 위치의 개수 	*/
	int comp_score = 0; 															/* 컴퓨터의 점수 				*/
	int user_score = 0; 															/* 플레이어의 점수 				*/
	char y = 0;																		/* 열 문자 						*/
	int x = 0;																		/* 행 번호						*/
	int player = 0; 																/* 말을 놓을 플레이어 			*/ 

	printf("\n오델로\n\n");
	printf("첫 판은 당신 먼저 하십시오. 그리고 다음부터는 번갈아 선을 잡읍시다.\n");
	printf("당신은 흰색말입니다(O).\n 그리고 나는 검은색을 잡겠습니다(@).\n");
	printf("말을 둘 위치를 입력하려면 행 번호(숫자)와 열 번호(알파벳)를 "
					"공백없이 나란히 입력하면 됩니다.\n"); 
	printf("\n행운을 빕니다! 시작하려면 Enter를 누르십시오.\n"); 
	scanf("%c", &again); 

	/* 메인 게임 루프 */
	do
	{
		/* 짝수번째 게임에서는 플레이어가 먼저 시작 */
		/* 홀수번째 게임에서는 컴퓨터가 먼저 시작 	*/
		player = ++no_of_games % 2; 
		no_of_moves = 4; 															/* 4개의 말을 먼저 놓은 상태에서 게임 시작 	*/

	/* 말판의 모든 격자를 비움 */ 
	for(row = 0 ; row < SIZE ; row++)
		for(col = 0 ; col < SIZE ; col++)
			board[row][col] = ' ';

	/* 말판 한가운데에 4개의 말을 기본으로 놓음 */ 
	board[SIZE/2 - 1][SIZE/2 - 1] = board[SIZE/2][SIZE/2] = 'O'; 
	board[SIZE/2 - 1][SIZE/2] = board[SIZE/2][SIZE/2 - 1] = '@'; 

	/* 게임 실행 루프 */
		do
		{

	display(board); 																/* 말판을 출력 		*/ 
			if(player++ % 2)
			{	/* 플레이어가 말을 놓을 차례 */
								if(valid_moves(board, moves, 'O')) 
				{
					/* 올바른 위치를 입력할 때까지 사용자의 입력을 받아들임 */
					for(;;)
					{
						fflush(stdin); 												/* 키보드 버퍼를 비움			*/
						printf("말을 놓을 위치를 입력하세요 (행번호 열문자): "); 
						scanf("%d%c", &x, &y); 										/* 입력값을 읽어들임			*/
						y = tolower(y) - 'a'; 										/* 열 문자를 열 인덱스로 변환 	*/ 
						x--; 														/* 행 번호를 행 인덱스로 변환	*/ 
						if( x>=0 && y>=0 && x<SIZE && y<SIZE && moves[x][y]) 
						{ 
							make_move(board, x, y, 'O');
							no_of_moves++; 											/* 말의 개수를 1 증가시킴 		*/
							break;
						} 
						else 
							printf("올바르지 않은 위치입니다. 다시 입력하세요.\n"); 
					} 
				} 
				else 																/* 말을 놓을 곳이 없는 경우		*/ 
					if(++invalid_moves<2) 
					{ 
						fflush(stdin); 
						printf("\n둘 곳이 없으므로 그냥 넘어갑니다. 엔터키를 누르세요."); 
						scanf("%c", &again); 
					} 
					else 
						printf("\n우리 모두 둘 곳이 전혀 없군요. 게임을 끝냅시다.\n");

			}
			else
			{	/* 컴퓨터가 말을 놓을 차례 */
								if(valid_moves(board, moves, '@')) 					/* 올바른 위치인지 검사 	*/ 
				{ 
					invalid_moves = 0; 												/* invalid_moves 초기화		*/ 
					computer_move(board, moves, '@'); 
					no_of_moves++; 													/* 말의 개수를 1 증가시킴	*/ 
				}
				else
				{
					if(++invalid_moves<2) 
						printf("\n저는 놓을 곳이 없네요. 당신 차례입니다.\n");		/* 말을 놓을 곳이 없음		*/ 
					else 
						printf("\n우리 모두 둘 곳이 전혀 없군요. 게임을 끝냅시다.\n"); 
				}

			}
		}while(no_of_moves < SIZE*SIZE && invalid_moves<2);

		/* 게임 끝 */
		display(board); 															/* 최종 말판을 보여줌		*/

		/* 최종 점수를 계산해 출력 */
		comp_score = user_score = 0; 
		for(row = 0; row < SIZE; row++)
			for(col = 0; col < SIZE; col++) 
			{
				comp_score += board[row][col] == '@';
				user_score += board[row][col] == 'O';
			} 
		printf("최종 점수\n"); 
		printf("컴퓨터 : %d\n 사용자 : %d\n\n", comp_score, user_score); 

		fflush(stdin); 																/* 입력버퍼를 비움 	*/
		printf("한번 더 하시겠습니까?(y/n): ");
		scanf("%c", &again); 														/* y나 n을 입력받음	*/
	}while(tolower(again) == 'y'); 													/* y이면 한번 더 	*/ 

	printf("\n안녕히 가세요!\n"); 
	
} 

/**********************************************************************
 * 격자를 식별할 수 있도록 행 번호와 열 문자를 붙여 현재상태의 말판을 *
 * 출력하는 함수. 매개변수는 배열 board임.							  *
 **********************************************************************/
void display(char board[][SIZE]) 
{ 
	int row = 0; 																	/* 행 인덱스 	*/
	int col = 0; 																	/* 열 인덱스 	*/
	char col_label = 'a'; 															/* 열 라벨 		*/

	printf("\n "); 																	/* 맨 윗줄 시작	*/
	for(col = 0 ; col<SIZE ; col++) 
		printf(" %c", col_label+col); 												/* 맨 윗줄 출력 */
	printf("\n"); 																	/* 맨 윗줄 끝 	*/

	/* 중간 행 출력 */ 
	for(row = 0 ; row < SIZE ; row++)
	{
		printf("	+"); 
		for(col = 0 ; col<SIZE ; col++) 
			printf("---+"); 
		printf("\n%2d|",row + 1); 

		for(col = 0 ; col<SIZE ; col++) 
			printf(" %c |", board[row][col]); 										/* 놓인 말을 출력	*/ 
		printf("\n"); 
	} 

	printf("	+");																/* 맨 아랫줄 시작 	*/ 
	for(col = 0 ; col<SIZE ; col++) 
		printf("---+"); 															/* 맨 아랫줄 출력 	*/ 
	printf("\n"); 																	/* 맨 아랫줄 끝 	*/ 
} 

/********************************************************************************
 * 플레이어가 놓을 수 있는 올바른 말의 위치를 계산하는 함수. 올바른 말의 위치는 *
 * 배열 moves에 저장됨.1은 올바른 위치, 0은 올바르지 않은 위치를 의미.			*
 * 첫번째 매개변수 : 배열 board													*
 * 두번째 매개변수 : 배열 moves													*
 * 세번째 매개변수 : 말을 놓을 플레이어를 나타내는 문자							*
 * 반환값 : 올바른 말의 위치의 개수												*
 ********************************************************************************/
int valid_moves(char board[][SIZE], int moves[][SIZE], char player) 
{ 
	int rowdelta = 0; 																/* 말 주위의 행 증가분 		*/ 
	int coldelta = 0; 																/* 말 주위의 열 증가분 		*/ 
	int row = 0; 																	/* 행 인덱스 				*/ 
	int col = 0; 																	/* 열 인덱스 				*/ 
	int x = 0; 																		/* 검색시 행 인덱스 		*/ 
	int y = 0; 																		/* 검색시 열 인덱스 		*/ 
	int no_of_moves = 0; 															/* 올바른 말 위치의 개수	*/ 
	/* 상대방 설정 */ 
	char opponent = (player == 'O')? '@' : 'O'; 

	/* 배열 moves를 0으로 초기화 */
	for(row = 0; row < SIZE; row++)
		for(col = 0; col < SIZE; col++)
			moves[row][col] = 0;

	/* 말을 놓을 수 있는 올바른 위치를 검색 						*/ 
	/* 말을 놓을 수 있는 올바른 위치는 반드시 빈 격자이어야 하며, 	*/
	/* 플레이어의 말 2개가 하나 이상의 상대방의 말을 둘러싸야 한다.	*/ 
	for(row = 0; row < SIZE; row++) 
		for(col = 0; col < SIZE; col++) 
		{ 
			if(board[row][col] != ' ') 												/* 빈 격자인가? 				*/ 
				continue; 															/* 아니면 다음 격자로 넘어감	*/ 

			/* 빈 격자 둘레에 있는 모든 격자를 확인해 상대방의 말이 놓여있는지 검색 */
			for(rowdelta = -1; rowdelta <= 1; rowdelta++) 
				for(coldelta = -1; coldelta <= 1; coldelta++) 
				{ 
					/* 배열 범위 바깥쪽과 현재 격자는 검사하지 않음 */ 
					if (row + rowdelta < 0 || row + rowdelta >= SIZE || 
							col + coldelta < 0 || col + coldelta >= SIZE || 
							(rowdelta==0 && coldelta==0)) 
						continue; 
	
					/* 격자를 검사 */
					if(board[row + rowdelta][col + coldelta] == opponent)
					{
						/* 상대방의 말을 찾았으면, 그 방향으로 계속 나아가면서 	*/
						/* 플레이어의 말을 찾음									*/
						x = row + rowdelta; 										/* 상대방의 말로	*/
						y = col + coldelta; 										/* 이동 			*/

						/* 같은 방향으로 계속 넘어가면서 플레이어의 말을 찾음 */
						for(;;)
						{
							x += rowdelta; 											/* 같은 방향의 			*/ 
							y += coldelta; 											/* 다음 격자로 넘어감	*/ 

							/* 배열 바깥으로 넘어가버리면 검색을 중단 */ 
							if(x < 0 || x >= SIZE || y < 0 || y >= SIZE) 
								break; 

							/* 빈 격자가 있으면 검색을 중단 */ 
							if(board[x][y] == ' ')
								break; 
							/* 격자에 플레이어의 말이 있으면 		*/ 
							/* 말을 놓을 수 있는 올바른 위치임 	*/ 
							if(board[x][y] == player) 
							{ 
								moves[row][col] = 1; 								/* 올바른 위치임을 표시 			*/ 
								no_of_moves++; 										/* 올바른 위치의 개수를 1 증가 		*/ 
								break; 												/* 다른 격자로 넘어가 검색을 계속	*/ 
							} 	
						} 	
					} 	
				} 	
		} 	
	return no_of_moves; 	
} 		

/*******************************************************************************
 * 말을 놓는 함수. 격자에 말을 놓은 뒤 양 옆이 막힌 상대방의 말을 모두 뒤집음. *
 * 첫번째 매개변수 : 배열 board												   *
 * 두번째/세번째 매개변수 : 행 인덱스와 열 인덱스							   *
 * 네번째 매개변수 : 플레이어를 표시하는 문자								   *
 *******************************************************************************/ 
void make_move(char board[][SIZE], int row, int col, char player) 
{ 
	int rowdelta = 0; 																/* 행 증가분 			*/ 
	int coldelta = 0; 																/* 열 증가분 			*/ 
	int x = 0; 																		/* 검색용 행 인덱스 	*/ 
	int y = 0; 																		/* 검색용 열 인덱스 	*/ 
	char opponent = (player == 'O')? '@' : 'O';										/* 상대방 표시 			*/ 

	board[row][col] = player; 														/* 플레이어의 말을 놓음	*/ 

	/* 이 격자를 둘러싸고 있는 격자에 상대방의 말이 놓여 있는지 검사 */
	for(rowdelta = -1; rowdelta <= 1; rowdelta++)
		for(coldelta = -1; coldelta <= 1; coldelta++) 
		{ 
			/* 말판의 바깥이나 현재 격자는 검사하지 않음 */ 
			if (row + rowdelta < 0 || row + rowdelta >= SIZE || 
					col + coldelta < 0 || col + coldelta >= SIZE || 
					(rowdelta==0 && coldelta== 0)) 
				continue; 

			/* 격자를 검사 */
			if(board[row + rowdelta][col + coldelta] == opponent)
			{
				/* 상대방의 말을 찾았으면 같은 방향으로		*/
				/* 계속 나아가면서 플레이어의 말을 찾음		*/ 
				x = row + rowdelta; 												/* 상대방의 말로	*/ 
				y = col + coldelta; 												/* 이동 			*/ 

				for(;;) 
				{ 
					x += rowdelta; 													/* 다음 격자로		*/ 
					y += coldelta; 													/* 이동 			*/ 

					/* 말판의 범위를 벗어나면 검색을 중단 */ 
					if(x < 0 || x >= SIZE || y < 0 || y >= SIZE) 
						break; 
						/* 격자가 비어있으면 검색을 중단 */ 
					if(board[x][y] == ' ') 
						break; 

					/* 플레이어의 말을 찾으면 그 위치에서 반대로 거슬러 가면서	*/
					/* 상대방의 말을 모두 플레이어의 말로 바꿈					*/
					if(board[x][y] == player) 
					{ 	
						while(board[x-=rowdelta][y-=coldelta]==opponent) 			/* 상대방의 말인가? */ 
							board[x][y] = player; 									/* 그렇다면 바꿈	*/ 
						break; 														/* 작업 완료 		*/ 
					} 	
				}
			}
		}
}

/************************************************************************************
 * 현재 말판에서 플레이어의 점수를 계산. 플레이어의 말은 +1점, 상대방의 말은 -1점	*
 * 첫번째 매개변수 : 배열 board														*
 * 두번째 매개변수 : 플레이어를 표시하는 문자										*
 * 반환값 : 점수																	*
 ************************************************************************************/ 
int get_score(char board[][SIZE], char player) 
{ 
	int score = 0; 																	/* 현재 말판의 점수 	*/ 
	int row = 0; 																	/* 행 인덱스 			*/ 
	int col = 0; 																	/* 열 인덱스 			*/ 
	char opponent = player == 'O' ? '@' : 'O'; 										/* 상대방의 말을 식별	*/ 

	/* 말판에 있는 모든 말을 검사 */
	for(row = 0; row < SIZE; row++)
		for(col = 0; col < SIZE; col++)
		{ 
			score -= board[row][col] == opponent; 									/* 상대방의 말이면 1점 감점 	*/ 
			score += board[row][col] == player; 									/* 플레이어의 말이면 1점 추가	*/ 
		}
	return score; 
}

/********************************************************************************
 * 현재 말판에서 플레이어가 놓을 수 있는 수 가운데 가장 좋은 수의 점수를 계산	*
 * 첫번째 매개변수 : 배열 board													*
 * 두번째 매개변수 : 올바른 위치를 정의하고 있는 배열 moves						*
 * 세번째 매개변수 : 플레이어를 나타내는 문자									*
 * 반환값 : 가장 좋은 수를 놓았을 때의 점수										*
 ********************************************************************************/ 
int best_move(char board[][SIZE], int moves[][SIZE], char player) 
{ 
	int row = 0; 																	/* 행 인덱스 			*/
	int col = 0; 																	/* 열 인덱스 			*/
	int i = 0; 																		/* 루프 인덱스 			*/
	int j = 0; 																		/* 루프 인덱스 			*/
	
	char opponent = player=='O'?'@':'O'; 											/* 상대방의 말을 식별	*/

	char new_board[SIZE][SIZE] = { 0 }; 											/* 말판의 복사본 		*/
	int score = 0; 																	/* 최상의 점수 			*/
	int new_score = 0; 																/* 현재 수에서의 점수	*/

	/* 가능한 모든 수를 검사해 최상의 수를 찾음 */ 
	for(row = 0 ; row<SIZE ; row++) 
		for(col = 0 ; col<SIZE ; col++) 
		{ 
			if(!moves[row][col]) 													/* 올바른 수가 아닌가?	*/ 
				continue; 															/* 다음으로 넘어감 		*/ 

			/* 말판을 복사 */ 		
			for(i = 0 ; i<SIZE ; i++) 		
				for(j = 0 ; j<SIZE ; j++) 		
					new_board[i][j] = board[i][j]; 

			/* 말판의 복사본에 말을 놓아봄 */
			make_move(new_board, row, col, player); 

			/* 말을 놓았을 때의 점수 계산 */
			new_score = get_score(new_board, player); 
			if(score<new_score) 													/* 이전 결과보다 더 점수가 좋은가?	*/ 
				score = new_score; 													/* 그렇다면 최상의 점수로 기록 		*/ 
		} 
	return score; 																	/* 최상의 점수를 반환 				*/ 
} 

/************************************************************************************************
* 컴퓨터가 둘 수 있는 최상의 수를 찾는 함수. 상대방이 최저의 점수를 얻는 수를 최상의 수로 간주.	*
* 첫번째 매개변수 : 배열 board																	*
* 두번째 매개변수 : 올바른 수를 포함하는 배열 moves												*
* 세번째 매개변수 : 컴퓨터를 의미하는 문자 														*
*************************************************************************************************/ 
void computer_move(char board[][SIZE], int moves[][SIZE], char player) 
{ 
	int row = 0; 																	/* 행 인덱스 					*/
	int col = 0; 																	/* 열 인덱스 					*/
	int best_row = 0; 																/* 최상의 행 인덱스 			*/
	int best_col = 0; 																/* 최상의 열 인덱스 			*/
	int i = 0; 																		/* 루프 인덱스 					*/
	int j = 0; 																		/* 루프 인덱스 					*/
	int new_score = 0; 																/* 현재 수를 놓았을 때의 점수	*/
	int score = 100; 																/* 상대방의 최하 점수 			*/
	char temp_board[SIZE][SIZE]; 													/* 말판의 복사본 				*/
	int temp_moves[SIZE][SIZE]; 													/* 올바른 위치의 배열 			*/
	char opponent = (player == 'O')? '@' : 'O'; 									/* 상대방의 말을 식별 			*/

	/* 놓을 수 있는 수를 모두 검사 */ 
	for(row = 0; row < SIZE; row++)
		for(col = 0; col < SIZE; col++)
		{
			if(moves[row][col] == 0)
				continue;

			/* 먼저 배열 board와 moves의 복사본을 만듦 */ 
			for(i = 0; i < SIZE; i++) 
				for(j = 0; j < SIZE; j++) 
					temp_board[i][j] = board[i][j]; 

			/* 말판의 복사본에 말을 놓아봄 */ 
			make_move(temp_board, row, col, player); 

			/* 이 수를 놓은 뒤 상대방이 말을 놓을 수 있는 위치를 검색 */ 
			valid_moves(temp_board, temp_moves, opponent); 

			/* 상대방이 최상의 수를 뒀을 때의 점수를 계산 */ 
			new_score = best_move(temp_board, temp_moves, opponent); 
 
			if(new_score<score) 													/* 이전 점수보다 더 낮은가? 		*/ 
			{ 																		/* 그렇다면 이 수를 저장 			*/ 
				score = new_score; 													/* 상대방의 새로운 최저 점수를 저장	*/ 
				best_row = row; 													/* 최상의 수의 행 인덱스와 			*/ 
				best_col = col; 													/* 열 인덱스를 기록 				*/ 
			} 		
		} 		
	/* 최상의 위치에 말을 놓음 */ 		
	make_move(board, best_row, best_col, player); 
} 
