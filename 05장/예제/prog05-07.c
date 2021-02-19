/* ���α׷� 5.7 ƽ���� */ 
#include <stdio.h> 

void main() 
{ 
	int i = 0; 															/* ���� ī���� 					*/	
	int player = 0; 													/* �÷��̾� ��ȣ - 1�̳� 2		*/	
	int winner = 0; 													/* �¸��� �÷��̾� 				*/	
	int choice = 0; 													/* ������ ���� ��ȣ				*/
	int row = 0; 														/* ������ �� �ε��� ��ȣ		*/
	int column = 0; 													/* ������ �� �ε��� ��ȣ		*/
	int line = 0;														/* �˻� �������� ��/�� �ε���	*/

	char board[3][3] = { 												/* ���� 						*/	
		{'1','2','3'}, 													/* �� �迭�� �ʱⰪ�� 			*/ 
		{'4','5','6'}, 													/* ���ǿ��� �� ĭ�� �˷��ִ�	*/ 
		{'7','8','9'} 													/* ���� ��ȣ��. 				*/ 
	}; 		

	/* ���� ���� ���� */
	/* ���ڰ� �������� ������ ������ 9ȸ�� ������.*/
	for( i = 0; i<9 && winner==0; i++)
	{
		/* ���� ��� */
		printf("\n\n");
		printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
		printf("--+--+--\n");
		printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
		printf("--+--+--\n");
		printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
			
		player = i%2 + 1; 												/* �÷��̾� ���� */

		/* �÷��̾ �ùٸ� ���ڸ� �����ϰ� �� */
		do
		{
			printf("\n�÷��̾� %d���� ���� ���� �����Դϴ�. " 
				"�� %c�� ���� ��ġ�� ��ȣ�� �Է����ּ���: ", 
				player,(player==1)?'X':'O'); 
			scanf("%d", &choice); 
			
			row = --choice/3; 											/* ������ �� �ε��� ���� ���� */ 
			column = choice%3; 											/* ������ �� �ε��� ���� ���� */
		}while(choice<0 || choice>9 || board[row][column]>'9'); 
		
		/* �÷��̾��� ���� ��� */
		board[row][column] = (player == 1) ? 'X' : 'O'; 

		/* ���� �밢������ �Ϸķ� �þ ���� �ִ��� �˻� */ 
		if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||
			(board[0][2]==board[1][1] && board[0][2]==board[2][0]))
			winner = player;

		else
			/* ����, ���� ���� �˻� */
			for(line = 0; line <= 2; line ++)
				if((board[line][0]==board[line][1] && 
						board[line][0]==board[line][2])||
					(board[0][line]==board[1][line] && 
						board[0][line]==board[2][line]))
					winner = player;
	} 
	/* ������ �������Ƿ� ������ ������ ���¸� ����Ѵ�. */
	printf("\n\n");
	printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("--+--+--\n");
	printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("--+--+--\n");
	printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]); 

	/* ��� �޽��� ��� */
	if(winner == 0)
		printf("\n�ƽ��Ե� �����ϴ�.\n");
	else
		printf("\n�����մϴ�, �÷��̾� %d��. ����� �¸��߽��ϴ�!\n", 	winner);
} 
