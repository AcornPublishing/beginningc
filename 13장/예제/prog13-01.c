/* 프로그램 13.1 전처리기 지시자를 이용한 디버그 */
#include <stdio.h>
#include <stdlib.h>

#define random(NumValues) ((int)(((double)(rand())*(NumValues))/(RAND_MAX+1.0)))
#define test
#define testf

/* 함수원형 */
int sum(int, int);
int product(int, int);
int difference(int, int);

void main() 
{ 
	int i = 0; 												/* 루프 카운터 				*/ 
	int j = 0; 												/* 함수 선택을 위한 인덱스	*/ 
	int a = 10, b = 5; 										/* 시작값 					*/ 
	int result = 0; 										/* 결과를 저장할 변수 		*/ 
	int (*pfun[3])(int, int); 								/* 함수 포인터 배열 선언	*/ 

	/* 포인터 초기화 */
	pfun[0] = sum;
	pfun[1] = product;
	pfun[2] = difference;

	#ifndef notrandom
	srand((unsigned int)time(NULL)); 						/* 난수 초기값 생성 		*/
	#endif

	/* 함수 포인터가 가리키는 함수를 실행 */
	for(i = 0 ; i < 10 ; i++)
	{ 
		j = random(3); 										/* 0~2 범위의 난수 생성		*/ 
		
		#ifdef test
		printf("\n난수 = %d", j );
		if( j>2 )
		{
			printf("\n올바르지 않은 배열 인덱스 = %d", j);
			break;
		}
		#endif 

		result = pfun[j](a , b); 							/* 임의의 함수 호출 		*/ 
		printf("\nresult = %d", result );
	}
	result = pfun[1](pfun[0](a , b), pfun[2](a , b));
	printf("\n\n합과 차의 곱 = %d\n", result);
}

/* sum 함수 정의 */
int sum(int x, int y)
{
	#ifdef testf
	printf("\nsum 함수 호출됨");
	#endif

		return x + y; 
} 

/* product 함수 정의 */
int product( int x, int y )
{
	#ifdef testf
	printf("\nproduct 함수 호출됨.");
	#endif

	return x * y; 
} 

/* difference 함수 정의 */
int difference(int x, int y)
{
	#ifdef testf
	printf("\ndifference 함수 호출됨");
	#endif

	return x - y; 
} 
