/* 프로그램 4.12 기억력 테스트 게임 */
#include <stdio.h> 											/* 입출력을 위해 포함 								*/
#include <ctype.h> 											/* toupper() 함수 사용을 위해 포함		*/
#include <stdlib.h> 										/* rand()와 srand() 사용을 위해 포함	*/ 
#include <time.h> 											/* time()함수 사용을 위해 포함 				*/ 

#define TRUE 1 												/* 기호 TRUE 정의 									*/ 
#define FALSE 0 											/* 기호 FALSE 정의 									*/ 

void main()
{
	/* 게임을 한번 더 할 것인지에 관한 사용자의 의사를 기록 */
	char another_game = 'Y'; 

	/* 입력한 숫자가 맞으면 TRUE, 틀리면 FALSE */
	int correct = TRUE; 

	/* 숫자를 성공적으로 입력한 회수 */  
	int counter = 0; 

	int sequence_length = 0; 								/* 숫자열의 자리수 			*/
	int i = 0; 												/* 루프 카운터 				*/
	long seed = 0; 											/* 임의의 숫자열의 초기값 	*/
	int number = 0; 										/* 입력한 숫자를 저장할 변수*/
	long now = 0;											/* 현재 시간을 저장 - 임의의 값을 생성하는데 필요한 초기값 */
	long time_taken = 0;									/* 게임하는데 걸린 시간		*/

	/* 게임 방법에 관한 설명 */
	printf("\n기억력 테스트 게임입니다!");
	printf("화면에 보이는 숫자를 그대로 입력하세요.");
	printf("\n컴퓨터는 숫자를 1초 동안만 보여주고 ");
	printf("1초가 지나면 곧바로 숫자를 지워버립니다."); 
	printf("\n여러분은 컴퓨터가 제시한 숫자를 똑같은 순서로 정확히 입력하면 "
					"됩니다."); 
	printf("\n숫자 사이는 반드시 스페이스바를 눌러 구분해주세요.\n"); 
	printf("\n행운을 빕니다!\n계속하시려면 엔터를 누르세요.\n"); 
	scanf("%c", &another_game); 

	/* 바깥쪽 루프가 1번 반복할 때마다 게임이 1번 실행 */
	do
	{
		correct = TRUE; 									/* 초기값으로 입력한 숫자가 맞았다고 표시	*/ 
		counter = 0; 										/* 성공한 회수를 초기화 					*/ 
		sequence_length = 2; 								/* 숫자열의 길이를 초기화 					*/ 
		time_taken = clock();								/* 게임을 시작한 이후로 경과한 시간 기록	*/

		/* 안쪽 루프는 입력한 숫자가 맞으면 계속 반복됨 */
		while(correct)
		{
			/* 3회 성공할 때마다 숫자열을 한 자리 증가시킴 */ 
			sequence_length += counter++%3 == 0; 

			/* 초기값을 1970년 1월 1일 이후 경과한 초로 설정 */ 
			seed = time(NULL); 

			now = clock(); 									/* 숫자열을 보여주기 시작한 시간 기록	*/

			/* 숫자열을 만들어 출력 */ 
			srand((int)seed); 								/* 임의의 숫자열 초기화					*/ 
			for(i = 1; i <= sequence_length; i++)  
				printf("%d ", rand() % 10); 				/* 임의의 숫자 출력 					*/ 
				
			/* 1초 동안 대기 */
			for( ;clock() - now < CLOCKS_PER_SEC; );

			/* 숫자열을 스페이스로 겹쳐써서 지움 */
			printf("\r"); 									/* 행의 맨 처음으로 이동 				*/
			for(i = 1; i <= sequence_length; i++)
				printf("	"); 							/* 스페이스 출력 						*/

			if(counter == 1) 								/* 첫번째 도전에서만 보여주는 메시지	*/
				printf("\n반드시 스페이스바로 구분해서 숫자를 입력하세요.\n");
				
			else
				printf("\r");				 				/* 행의 맨 처음으로 이동 */

			/* 입력 숫자열과 원래의 숫자열을 비교 */ 
			srand((int)seed); 								/* 난수를 다시 생성 	*/
			for(i = 1; i <= sequence_length; i++)
			{
				scanf("%d", &number); 						/* 입력 숫자열을 읽어들임	*/ 
				if(number != rand() % 10) 					/* 임의의 숫자열과 비교		*/ 
				{ 
					correct = FALSE; 						/* 틀렸음 					*/ 
					break; 									/* 더 이상 검사할 필요 없음 */ 
				} 
			} 
			printf("%s\n", correct? "맞았습니다!" : "틀렸습니다!"); 
		}

		/* 게임하는데 걸린 전체 시간을 초단위로 계산 */
		time_taken = (clock() - time_taken) / CLOCKS_PER_SEC;

		/* 점수 출력 */
		printf("\n\n%d점을 획득하셨습니다.", --counter * 100 / time_taken);

		fflush(stdin);
			
		/* 게임을 새로 할 것인지 묻는 코드 */
		printf("\n다시 도전하시겠습니까(y/n)? ");
		scanf("%c", &another_game);
	} while(toupper(another_game) == 'Y');
}
