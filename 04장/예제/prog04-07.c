/* 프로그램 4.7 	행운번호 맞히기 게임 */ 
#include <stdio.h> 	

void main() 	
{ 	
	long chosen = 15; 											/* 행운번호 			*/ 
	int guess = 0; 												/* 사용자가 고른 번호	*/ 
	int count = 3; 												/* 최대 도전 가능 회수	*/ 

	printf("\n행운번호 맞히기 게임입니다."); 
	printf("\n컴퓨터가 1번부터 20번 가운데 하나를 추첨합니다."
					"이 번호를 맞혀보세요.\n"); 

	for( ; count>0 ; --count) 
	{ 
		printf("\n%d번의 기회%s 남아있습니다.", count, count == 1 ? "만" : "가"); 
		printf("\n번호를 입력하세요: "); 						/* 번호 입력을 지시		*/ 
		scanf("%d", &guess); 									/* 번호를 읽어들임 		*/ 

		/* 행운번호를 맞혔는지 검사 */ 		
		if (guess == chosen) 		
		{ 		
			printf("\n맞았습니다!\n"); 		
			return; 											/* 프로그램 종료 		*/ 
		} 		

		/* 올바르지 않은 번호인지 검사  */ 		
		if(guess<1 || guess > 20) 		
			printf("1부터 20까지의 수를 입력하셔야 합니다.\n"); 
		else 
			printf("저런, %d은(는) 행운번호가 아니네요.\n", guess); 
	} 
	printf("\n3번 만에 맞히지 못하셨네요. 행운번호는 %ld입니다.\n", chosen); 
} 
