/* Program 5.3 10개의 점수 평균 구하기 - 쉬운 방법으로 점수 저장 */ 
#include <stdio.h> 

void main() 
{ 	
	int numbers[10]; 												/* 10개의 값을 저장할 배열	*/ 
	int count = 10; 												/* 읽어들일 값의 개수 		*/ 
	long sum = 0L; 													/* 점수의 총합 				*/ 
	float average = 0.0f; 											/* 점수의 평균 				*/ 
	int i = 0; 														/* 루프 카운터 				*/ 
		
	printf("\n10개의 점수를 입력하세요.\n"); 						/* 입력 프롬프트			*/ 
		
	/* 평균을 구할 점수 10개를 읽어들임 */
	for(i = 0; i < count; i ++)
	{
		printf("%2d> ",i+1);
		scanf("%d", &numbers[i]); 									/* 점수를 읽어들임 			*/
		sum += numbers[i]; 											/* 점수를 sum에 더함 		*/
	} 
	
	average = (float)sum/count; 									/* 평균 계산 				*/ 
	printf("\n입력한 점수 10개의 평균은 %f점입니다.\n", average); 
} 
