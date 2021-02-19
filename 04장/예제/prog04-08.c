/* 프로그램 4.8 while문을 이용한 합계 구하기 */ 
#include <stdio.h> 

void main() 
{ 	
	long sum = 0L; 										/* 정수의 합계를 저장할 변수 	*/ 
	int i = 1; 											/* 인덱스						*/ 
	int count = 0; 										/* 합계를 구해야 할 정수의 개수 */ 

	/* 합계를 구해야 할 정수의 개수를 입력받음 */ 
	printf("\n정수를 하나 입력하세요: "); 
	scanf(" %d", &count); 

	/* 1부터 count까지의 정수를 모두 더함 */
	while(i <= count)
		sum += i++;

	printf("1부터 %d까지의 정수를 모두 더하면 %ld이(가) 됩니다.\n", count, sum); 
} 
