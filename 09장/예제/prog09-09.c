/* ���α׷� 9.9 ������ ���� */ 
#include <stdio.h> 
#include <ctype.h>

#define SIZE 6 																		/* ������ ũ�� - �ݵ�� ¦������ ��	*/ 

/* �Լ����� */ 
void display(char board[][SIZE]); 
int valid_moves(char board[][SIZE], int moves[][SIZE], char player);
void make_move(char board[][SIZE], int row, int col, char player); 
void computer_move(char board[][SIZE], int moves[][SIZE], char player); 
int best_move(char board[][SIZE], int moves[][SIZE], char player); 
int get_score(char board[][SIZE], char player); 

void main() 
{ 
	char board [SIZE][SIZE] = { 0 }; 												/* ���� 						*/ 
	int moves [SIZE][SIZE] = { 0 };													/* ���� ���� �� �ִ� ����		*/
	int row = 0; 																	/* ������ �� �ε���				*/ 
	int col = 0; 																	/* ������ �� �ε���				*/ 
	char again = 0;																	/* ������ �� �� ������ ���� 	*/
	int no_of_games = 0; 															/* ���� ȸ�� 					*/
	int no_of_moves = 0; 															/* ���� ���� ȸ�� 				*/
	int invalid_moves = 0; 															/* �ùٸ��� ���� ��ġ�� ���� 	*/
	int comp_score = 0; 															/* ��ǻ���� ���� 				*/
	int user_score = 0; 															/* �÷��̾��� ���� 				*/
	char y = 0;																		/* �� ���� 						*/
	int x = 0;																		/* �� ��ȣ						*/
	int player = 0; 																/* ���� ���� �÷��̾� 			*/ 

	printf("\n������\n\n");
	printf("ù ���� ��� ���� �Ͻʽÿ�. �׸��� �������ʹ� ������ ���� �����ô�.\n");
	printf("����� ������Դϴ�(O).\n �׸��� ���� �������� ��ڽ��ϴ�(@).\n");
	printf("���� �� ��ġ�� �Է��Ϸ��� �� ��ȣ(����)�� �� ��ȣ(���ĺ�)�� "
					"������� ������ �Է��ϸ� �˴ϴ�.\n"); 
	printf("\n����� ���ϴ�! �����Ϸ��� Enter�� �����ʽÿ�.\n"); 
	scanf("%c", &again); 

	/* ���� ���� ���� */
	do
	{
		/* ¦����° ���ӿ����� �÷��̾ ���� ���� */
		/* Ȧ����° ���ӿ����� ��ǻ�Ͱ� ���� ���� 	*/
		player = ++no_of_games % 2; 
		no_of_moves = 4; 															/* 4���� ���� ���� ���� ���¿��� ���� ���� 	*/

	/* ������ ��� ���ڸ� ��� */ 
	for(row = 0 ; row < SIZE ; row++)
		for(col = 0 ; col < SIZE ; col++)
			board[row][col] = ' ';

	/* ���� �Ѱ���� 4���� ���� �⺻���� ���� */ 
	board[SIZE/2 - 1][SIZE/2 - 1] = board[SIZE/2][SIZE/2] = 'O'; 
	board[SIZE/2 - 1][SIZE/2] = board[SIZE/2][SIZE/2 - 1] = '@'; 

	/* ���� ���� ���� */
		do
		{

	display(board); 																/* ������ ��� 		*/ 
			if(player++ % 2)
			{	/* �÷��̾ ���� ���� ���� */
								if(valid_moves(board, moves, 'O')) 
				{
					/* �ùٸ� ��ġ�� �Է��� ������ ������� �Է��� �޾Ƶ��� */
					for(;;)
					{
						fflush(stdin); 												/* Ű���� ���۸� ���			*/
						printf("���� ���� ��ġ�� �Է��ϼ��� (���ȣ ������): "); 
						scanf("%d%c", &x, &y); 										/* �Է°��� �о����			*/
						y = tolower(y) - 'a'; 										/* �� ���ڸ� �� �ε����� ��ȯ 	*/ 
						x--; 														/* �� ��ȣ�� �� �ε����� ��ȯ	*/ 
						if( x>=0 && y>=0 && x<SIZE && y<SIZE && moves[x][y]) 
						{ 
							make_move(board, x, y, 'O');
							no_of_moves++; 											/* ���� ������ 1 ������Ŵ 		*/
							break;
						} 
						else 
							printf("�ùٸ��� ���� ��ġ�Դϴ�. �ٽ� �Է��ϼ���.\n"); 
					} 
				} 
				else 																/* ���� ���� ���� ���� ���		*/ 
					if(++invalid_moves<2) 
					{ 
						fflush(stdin); 
						printf("\n�� ���� �����Ƿ� �׳� �Ѿ�ϴ�. ����Ű�� ��������."); 
						scanf("%c", &again); 
					} 
					else 
						printf("\n�츮 ��� �� ���� ���� ������. ������ �����ô�.\n");

			}
			else
			{	/* ��ǻ�Ͱ� ���� ���� ���� */
								if(valid_moves(board, moves, '@')) 					/* �ùٸ� ��ġ���� �˻� 	*/ 
				{ 
					invalid_moves = 0; 												/* invalid_moves �ʱ�ȭ		*/ 
					computer_move(board, moves, '@'); 
					no_of_moves++; 													/* ���� ������ 1 ������Ŵ	*/ 
				}
				else
				{
					if(++invalid_moves<2) 
						printf("\n���� ���� ���� ���׿�. ��� �����Դϴ�.\n");		/* ���� ���� ���� ����		*/ 
					else 
						printf("\n�츮 ��� �� ���� ���� ������. ������ �����ô�.\n"); 
				}

			}
		}while(no_of_moves < SIZE*SIZE && invalid_moves<2);

		/* ���� �� */
		display(board); 															/* ���� ������ ������		*/

		/* ���� ������ ����� ��� */
		comp_score = user_score = 0; 
		for(row = 0; row < SIZE; row++)
			for(col = 0; col < SIZE; col++) 
			{
				comp_score += board[row][col] == '@';
				user_score += board[row][col] == 'O';
			} 
		printf("���� ����\n"); 
		printf("��ǻ�� : %d\n ����� : %d\n\n", comp_score, user_score); 

		fflush(stdin); 																/* �Է¹��۸� ��� 	*/
		printf("�ѹ� �� �Ͻðڽ��ϱ�?(y/n): ");
		scanf("%c", &again); 														/* y�� n�� �Է¹���	*/
	}while(tolower(again) == 'y'); 													/* y�̸� �ѹ� �� 	*/ 

	printf("\n�ȳ��� ������!\n"); 
	
} 

/**********************************************************************
 * ���ڸ� �ĺ��� �� �ֵ��� �� ��ȣ�� �� ���ڸ� �ٿ� ��������� ������ *
 * ����ϴ� �Լ�. �Ű������� �迭 board��.							  *
 **********************************************************************/
void display(char board[][SIZE]) 
{ 
	int row = 0; 																	/* �� �ε��� 	*/
	int col = 0; 																	/* �� �ε��� 	*/
	char col_label = 'a'; 															/* �� �� 		*/

	printf("\n "); 																	/* �� ���� ����	*/
	for(col = 0 ; col<SIZE ; col++) 
		printf(" %c", col_label+col); 												/* �� ���� ��� */
	printf("\n"); 																	/* �� ���� �� 	*/

	/* �߰� �� ��� */ 
	for(row = 0 ; row < SIZE ; row++)
	{
		printf("	+"); 
		for(col = 0 ; col<SIZE ; col++) 
			printf("---+"); 
		printf("\n%2d|",row + 1); 

		for(col = 0 ; col<SIZE ; col++) 
			printf(" %c |", board[row][col]); 										/* ���� ���� ���	*/ 
		printf("\n"); 
	} 

	printf("	+");																/* �� �Ʒ��� ���� 	*/ 
	for(col = 0 ; col<SIZE ; col++) 
		printf("---+"); 															/* �� �Ʒ��� ��� 	*/ 
	printf("\n"); 																	/* �� �Ʒ��� �� 	*/ 
} 

/********************************************************************************
 * �÷��̾ ���� �� �ִ� �ùٸ� ���� ��ġ�� ����ϴ� �Լ�. �ùٸ� ���� ��ġ�� *
 * �迭 moves�� �����.1�� �ùٸ� ��ġ, 0�� �ùٸ��� ���� ��ġ�� �ǹ�.			*
 * ù��° �Ű����� : �迭 board													*
 * �ι�° �Ű����� : �迭 moves													*
 * ����° �Ű����� : ���� ���� �÷��̾ ��Ÿ���� ����							*
 * ��ȯ�� : �ùٸ� ���� ��ġ�� ����												*
 ********************************************************************************/
int valid_moves(char board[][SIZE], int moves[][SIZE], char player) 
{ 
	int rowdelta = 0; 																/* �� ������ �� ������ 		*/ 
	int coldelta = 0; 																/* �� ������ �� ������ 		*/ 
	int row = 0; 																	/* �� �ε��� 				*/ 
	int col = 0; 																	/* �� �ε��� 				*/ 
	int x = 0; 																		/* �˻��� �� �ε��� 		*/ 
	int y = 0; 																		/* �˻��� �� �ε��� 		*/ 
	int no_of_moves = 0; 															/* �ùٸ� �� ��ġ�� ����	*/ 
	/* ���� ���� */ 
	char opponent = (player == 'O')? '@' : 'O'; 

	/* �迭 moves�� 0���� �ʱ�ȭ */
	for(row = 0; row < SIZE; row++)
		for(col = 0; col < SIZE; col++)
			moves[row][col] = 0;

	/* ���� ���� �� �ִ� �ùٸ� ��ġ�� �˻� 						*/ 
	/* ���� ���� �� �ִ� �ùٸ� ��ġ�� �ݵ�� �� �����̾�� �ϸ�, 	*/
	/* �÷��̾��� �� 2���� �ϳ� �̻��� ������ ���� �ѷ��ξ� �Ѵ�.	*/ 
	for(row = 0; row < SIZE; row++) 
		for(col = 0; col < SIZE; col++) 
		{ 
			if(board[row][col] != ' ') 												/* �� �����ΰ�? 				*/ 
				continue; 															/* �ƴϸ� ���� ���ڷ� �Ѿ	*/ 

			/* �� ���� �ѷ��� �ִ� ��� ���ڸ� Ȯ���� ������ ���� �����ִ��� �˻� */
			for(rowdelta = -1; rowdelta <= 1; rowdelta++) 
				for(coldelta = -1; coldelta <= 1; coldelta++) 
				{ 
					/* �迭 ���� �ٱ��ʰ� ���� ���ڴ� �˻����� ���� */ 
					if (row + rowdelta < 0 || row + rowdelta >= SIZE || 
							col + coldelta < 0 || col + coldelta >= SIZE || 
							(rowdelta==0 && coldelta==0)) 
						continue; 
	
					/* ���ڸ� �˻� */
					if(board[row + rowdelta][col + coldelta] == opponent)
					{
						/* ������ ���� ã������, �� �������� ��� ���ư��鼭 	*/
						/* �÷��̾��� ���� ã��									*/
						x = row + rowdelta; 										/* ������ ����	*/
						y = col + coldelta; 										/* �̵� 			*/

						/* ���� �������� ��� �Ѿ�鼭 �÷��̾��� ���� ã�� */
						for(;;)
						{
							x += rowdelta; 											/* ���� ������ 			*/ 
							y += coldelta; 											/* ���� ���ڷ� �Ѿ	*/ 

							/* �迭 �ٱ����� �Ѿ������ �˻��� �ߴ� */ 
							if(x < 0 || x >= SIZE || y < 0 || y >= SIZE) 
								break; 

							/* �� ���ڰ� ������ �˻��� �ߴ� */ 
							if(board[x][y] == ' ')
								break; 
							/* ���ڿ� �÷��̾��� ���� ������ 		*/ 
							/* ���� ���� �� �ִ� �ùٸ� ��ġ�� 	*/ 
							if(board[x][y] == player) 
							{ 
								moves[row][col] = 1; 								/* �ùٸ� ��ġ���� ǥ�� 			*/ 
								no_of_moves++; 										/* �ùٸ� ��ġ�� ������ 1 ���� 		*/ 
								break; 												/* �ٸ� ���ڷ� �Ѿ �˻��� ���	*/ 
							} 	
						} 	
					} 	
				} 	
		} 	
	return no_of_moves; 	
} 		

/*******************************************************************************
 * ���� ���� �Լ�. ���ڿ� ���� ���� �� �� ���� ���� ������ ���� ��� ������. *
 * ù��° �Ű����� : �迭 board												   *
 * �ι�°/����° �Ű����� : �� �ε����� �� �ε���							   *
 * �׹�° �Ű����� : �÷��̾ ǥ���ϴ� ����								   *
 *******************************************************************************/ 
void make_move(char board[][SIZE], int row, int col, char player) 
{ 
	int rowdelta = 0; 																/* �� ������ 			*/ 
	int coldelta = 0; 																/* �� ������ 			*/ 
	int x = 0; 																		/* �˻��� �� �ε��� 	*/ 
	int y = 0; 																		/* �˻��� �� �ε��� 	*/ 
	char opponent = (player == 'O')? '@' : 'O';										/* ���� ǥ�� 			*/ 

	board[row][col] = player; 														/* �÷��̾��� ���� ����	*/ 

	/* �� ���ڸ� �ѷ��ΰ� �ִ� ���ڿ� ������ ���� ���� �ִ��� �˻� */
	for(rowdelta = -1; rowdelta <= 1; rowdelta++)
		for(coldelta = -1; coldelta <= 1; coldelta++) 
		{ 
			/* ������ �ٱ��̳� ���� ���ڴ� �˻����� ���� */ 
			if (row + rowdelta < 0 || row + rowdelta >= SIZE || 
					col + coldelta < 0 || col + coldelta >= SIZE || 
					(rowdelta==0 && coldelta== 0)) 
				continue; 

			/* ���ڸ� �˻� */
			if(board[row + rowdelta][col + coldelta] == opponent)
			{
				/* ������ ���� ã������ ���� ��������		*/
				/* ��� ���ư��鼭 �÷��̾��� ���� ã��		*/ 
				x = row + rowdelta; 												/* ������ ����	*/ 
				y = col + coldelta; 												/* �̵� 			*/ 

				for(;;) 
				{ 
					x += rowdelta; 													/* ���� ���ڷ�		*/ 
					y += coldelta; 													/* �̵� 			*/ 

					/* ������ ������ ����� �˻��� �ߴ� */ 
					if(x < 0 || x >= SIZE || y < 0 || y >= SIZE) 
						break; 
						/* ���ڰ� ��������� �˻��� �ߴ� */ 
					if(board[x][y] == ' ') 
						break; 

					/* �÷��̾��� ���� ã���� �� ��ġ���� �ݴ�� �Ž��� ���鼭	*/
					/* ������ ���� ��� �÷��̾��� ���� �ٲ�					*/
					if(board[x][y] == player) 
					{ 	
						while(board[x-=rowdelta][y-=coldelta]==opponent) 			/* ������ ���ΰ�? */ 
							board[x][y] = player; 									/* �׷��ٸ� �ٲ�	*/ 
						break; 														/* �۾� �Ϸ� 		*/ 
					} 	
				}
			}
		}
}

/************************************************************************************
 * ���� ���ǿ��� �÷��̾��� ������ ���. �÷��̾��� ���� +1��, ������ ���� -1��	*
 * ù��° �Ű����� : �迭 board														*
 * �ι�° �Ű����� : �÷��̾ ǥ���ϴ� ����										*
 * ��ȯ�� : ����																	*
 ************************************************************************************/ 
int get_score(char board[][SIZE], char player) 
{ 
	int score = 0; 																	/* ���� ������ ���� 	*/ 
	int row = 0; 																	/* �� �ε��� 			*/ 
	int col = 0; 																	/* �� �ε��� 			*/ 
	char opponent = player == 'O' ? '@' : 'O'; 										/* ������ ���� �ĺ�	*/ 

	/* ���ǿ� �ִ� ��� ���� �˻� */
	for(row = 0; row < SIZE; row++)
		for(col = 0; col < SIZE; col++)
		{ 
			score -= board[row][col] == opponent; 									/* ������ ���̸� 1�� ���� 	*/ 
			score += board[row][col] == player; 									/* �÷��̾��� ���̸� 1�� �߰�	*/ 
		}
	return score; 
}

/********************************************************************************
 * ���� ���ǿ��� �÷��̾ ���� �� �ִ� �� ��� ���� ���� ���� ������ ���	*
 * ù��° �Ű����� : �迭 board													*
 * �ι�° �Ű����� : �ùٸ� ��ġ�� �����ϰ� �ִ� �迭 moves						*
 * ����° �Ű����� : �÷��̾ ��Ÿ���� ����									*
 * ��ȯ�� : ���� ���� ���� ������ ���� ����										*
 ********************************************************************************/ 
int best_move(char board[][SIZE], int moves[][SIZE], char player) 
{ 
	int row = 0; 																	/* �� �ε��� 			*/
	int col = 0; 																	/* �� �ε��� 			*/
	int i = 0; 																		/* ���� �ε��� 			*/
	int j = 0; 																		/* ���� �ε��� 			*/
	
	char opponent = player=='O'?'@':'O'; 											/* ������ ���� �ĺ�	*/

	char new_board[SIZE][SIZE] = { 0 }; 											/* ������ ���纻 		*/
	int score = 0; 																	/* �ֻ��� ���� 			*/
	int new_score = 0; 																/* ���� �������� ����	*/

	/* ������ ��� ���� �˻��� �ֻ��� ���� ã�� */ 
	for(row = 0 ; row<SIZE ; row++) 
		for(col = 0 ; col<SIZE ; col++) 
		{ 
			if(!moves[row][col]) 													/* �ùٸ� ���� �ƴѰ�?	*/ 
				continue; 															/* �������� �Ѿ 		*/ 

			/* ������ ���� */ 		
			for(i = 0 ; i<SIZE ; i++) 		
				for(j = 0 ; j<SIZE ; j++) 		
					new_board[i][j] = board[i][j]; 

			/* ������ ���纻�� ���� ���ƺ� */
			make_move(new_board, row, col, player); 

			/* ���� ������ ���� ���� ��� */
			new_score = get_score(new_board, player); 
			if(score<new_score) 													/* ���� ������� �� ������ ������?	*/ 
				score = new_score; 													/* �׷��ٸ� �ֻ��� ������ ��� 		*/ 
		} 
	return score; 																	/* �ֻ��� ������ ��ȯ 				*/ 
} 

/************************************************************************************************
* ��ǻ�Ͱ� �� �� �ִ� �ֻ��� ���� ã�� �Լ�. ������ ������ ������ ��� ���� �ֻ��� ���� ����.	*
* ù��° �Ű����� : �迭 board																	*
* �ι�° �Ű����� : �ùٸ� ���� �����ϴ� �迭 moves												*
* ����° �Ű����� : ��ǻ�͸� �ǹ��ϴ� ���� 														*
*************************************************************************************************/ 
void computer_move(char board[][SIZE], int moves[][SIZE], char player) 
{ 
	int row = 0; 																	/* �� �ε��� 					*/
	int col = 0; 																	/* �� �ε��� 					*/
	int best_row = 0; 																/* �ֻ��� �� �ε��� 			*/
	int best_col = 0; 																/* �ֻ��� �� �ε��� 			*/
	int i = 0; 																		/* ���� �ε��� 					*/
	int j = 0; 																		/* ���� �ε��� 					*/
	int new_score = 0; 																/* ���� ���� ������ ���� ����	*/
	int score = 100; 																/* ������ ���� ���� 			*/
	char temp_board[SIZE][SIZE]; 													/* ������ ���纻 				*/
	int temp_moves[SIZE][SIZE]; 													/* �ùٸ� ��ġ�� �迭 			*/
	char opponent = (player == 'O')? '@' : 'O'; 									/* ������ ���� �ĺ� 			*/

	/* ���� �� �ִ� ���� ��� �˻� */ 
	for(row = 0; row < SIZE; row++)
		for(col = 0; col < SIZE; col++)
		{
			if(moves[row][col] == 0)
				continue;

			/* ���� �迭 board�� moves�� ���纻�� ���� */ 
			for(i = 0; i < SIZE; i++) 
				for(j = 0; j < SIZE; j++) 
					temp_board[i][j] = board[i][j]; 

			/* ������ ���纻�� ���� ���ƺ� */ 
			make_move(temp_board, row, col, player); 

			/* �� ���� ���� �� ������ ���� ���� �� �ִ� ��ġ�� �˻� */ 
			valid_moves(temp_board, temp_moves, opponent); 

			/* ������ �ֻ��� ���� ���� ���� ������ ��� */ 
			new_score = best_move(temp_board, temp_moves, opponent); 
 
			if(new_score<score) 													/* ���� �������� �� ������? 		*/ 
			{ 																		/* �׷��ٸ� �� ���� ���� 			*/ 
				score = new_score; 													/* ������ ���ο� ���� ������ ����	*/ 
				best_row = row; 													/* �ֻ��� ���� �� �ε����� 			*/ 
				best_col = col; 													/* �� �ε����� ��� 				*/ 
			} 		
		} 		
	/* �ֻ��� ��ġ�� ���� ���� */ 		
	make_move(board, best_row, best_col, player); 
} 
