/* 프로그램 4.9 합계 구하기 */ 
#include <stdio.h> 

void main() 
{ 	
	long sum = 0L; 											/* 정수의 합을 저장할 변수 		*/ 
	int i = 1; 												/* 바깥쪽 루프의 제어변수 		*/ 
	int j = 1; 												/* 안쪽 루프의 제어변수 		*/ 
	int count = 0; 											/* 계산해야 할 합계의 수 		*/ 

	/* count 값의 입력을 지시하고 읽어들임 */
	printf("\n정수를 하나 입력하세요: ");
	scanf("%d", &count);

	for( i = 1 ; i <= count ; i++ ) 
	{ 
		sum = 0L; 											/* 안쪽 루프에서 sum을 초기화	*/ 

		/* 1부터 i까지 정수의 합계를 계산 */
		for(j = 1 ; j <= i ; j++ )
			sum += j;

		printf("\n%d\t%ld", i, sum); 						/* 1부터 i까지 합계를 출력 		*/ 
	} 
} 
