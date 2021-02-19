/* 프로그램 4.5 반대 순서로 합계 구하기 */ 
#include <stdio.h> 
void main() 
{ 
	long sum = 0L; 								/* 정수의 합계를 저장할 변수	*/ 
	int count = 0; 								/* 사용자에게 입력받은 정수 	*/ 
	int i = 0; 									/* 루프 카운터 					*/ 
	/* 정수를 입력받음 */ 
	printf("\n정수를 하나 입력하세요: "); 
	scanf("%d", &count); 

	/* 1부터 count까지의 정수를 모두 더함 */
	for (i = count ; i >= 1 ; sum += i-- ); 
	printf("\n1부터 %d까지의 정수를 모두 더하면 %ld이(가) 됩니다.\n", count, sum); 
} 

