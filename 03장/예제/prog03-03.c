/* 프로그램 3.3 중첩 if문을 이용한 수치 분석 */
#include <stdio.h>
#include <limits.h> 									/* LONG_MAX를 사용하기 위해 포함 */

void main() 
{ 
	long test = 0L; 									/* 검사할 정수를 저장 			 */ 

	printf("%ld보다 작은 정수를 입력하세요: ", LONG_MAX); 
	scanf("%ld", &test); 

	/* 입력받은 정수를 2로 나눈 나머지로 짝수인지 홀수인지 판별 */
	if(test % 2L == 0L) 
	{
		printf("입력하신 수 %ld은(는) 짝수입니다.", test); 

		/* 이 수를 반으로 나눈 수도 짝수인지 검사 */
		if ((test/2L) % 2L == 0L)
		{
			printf("\n%ld을(를) 반으로 나눈 수도 짝수입니다.", test);
			printf("\n재미있지 않습니까?\n");
		}
	}
	else
		printf("입력하신 수 %ld은(는) 홀수입니다.\n", test); 
} 
