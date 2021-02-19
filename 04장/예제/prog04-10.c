/* 프로그램 4.10 for 루프에 중첩된 while 루프로 합계 구하기 */ 
#include <stdio.h> 

void main() 
{ 
	long sum = 1L; 											/* 정수의 합을 저장할 변수 		*/ 
	int i = 1; 												/* 바깥쪽 루프의 제어변수 		*/ 
	int j = 1; 												/* 안쪽 루프의 제어변수 		*/ 
	int count = 0; 											/* 계산해야 할 합계의 수 		*/ 

	/* count 값의 입력을 지시하고 읽어들임 */
	printf("\n정수를 하나 입력하세요: ");
	scanf("%d", &count);

	for( i = 1 ; i <= count ; i++ ) 
	{ 
		sum = 1L; 											/* 안쪽 루프에서 sum을 초기화	*/ 
		j=1; 												/* 더해줄 정수 초기화 			*/ 
		printf("\n1"); 

		/* 1부터 i까지 정수의 합계를 계산 */
		while(j < i) 
		{ 
			sum += ++j; 
			printf("+%d", j); 								/* 같은 행에 +j를 출력 			*/ 
		}
		printf(" = %ld\n", sum); 							/* sum을 출력 					*/ 
	} 				
} 
