/* Program 5.2 10개의 점수 평균 구하기 - 까다로운 방법으로 점수 저장 */ 
#include <stdio.h> 

void main() { 
	int number0 = 0, number1 = 0, number2 = 0, number3 = 0, number4 = 0; 
 
	int number5 = 0, number6 = 0, number7 = 0, number8 = 0, number9 = 0; 

	long sum = 0L; 											/* 수의 합		*/ 
	float average = 0.0f; 									/* 수의 평균	*/ 
	/* 평균을 구할 10개의 수를 읽어들임 */
	printf("처음 5개의 점수를 입력하세요.\n");
	printf("점수와 점수 사이에는 스페이스나 엔터를 누르세요.\n");
	scanf("%d%d%d%d%d", &number0, &number1, &number2, &number3, &number4);
	printf("나중 5개의 점수를 입력하세요.\n");
	printf("점수와 점수 사이에는 스페이스나 엔터를 누르세요.\n");
	scanf("%d%d%d%d%d", &number5, &number6, &number7, &number8, &number9);
	/* 이제 10개의 점수를 모두 얻었으므로, 평균을 계산할 수 있다 */
	sum = number0 + number1+ number2 + number3 + number4 +	
				number5 + number6 + number7 + number8 + number9;
	average = (float)sum/10.0f;

	printf("\n입력한 점수 10개의 평균은 %f점입니다.\n", average); 
} 
