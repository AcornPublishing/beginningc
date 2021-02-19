/* 프로그램 5.1 - 10개의 점수를 저장하지 않고 평균 구하기 */
#include <stdio.h>

void main() 
{ 
	int number = 0; 											/* 수를 저장할 변수 	*/ 
	int count = 10; 											/* 읽어들일 값의 개수	*/ 
	long sum = 0L; 												/* 수의 합 				*/ 
	float average = 0.0f; 										/* 수의 평균 			*/ 
	int i = 0; 													/* 루프 카운터 			*/ 

	/* 평균을 구할 10개의 수를 읽어들임 */
	for(i = 0; i < count; i ++)
	{
		printf("점수를 입력하세요: ");
		scanf("%d", &number); 								/* 수를 읽어들임 			*/
		sum += number; 										/* 읽어들인 수를 sum에 더함 */
	} 

	average = (float)sum/count; 										/* 평균 계산	*/ 

	printf("\n학생 10명의 평균은 %f점입니다.\n", average); 
} 
