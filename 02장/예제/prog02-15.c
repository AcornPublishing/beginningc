/* 프로그램 2.15 한계 알아내기 */
#include <stdio.h>
#include <limits.h> 				/* 정수형의 한계를 알려주는 헤더파일 */
#include <float.h> 					/* 실수형의 한계를 알려주는 헤더파일 */

void main() 
{ 
	printf("char형 변수가 저장할 수 있는 값은 %d부터 %d까지 입니다.", 
			CHAR_MIN, CHAR_MAX); 
	printf("\nunsigned char형 변수가 저장할 수 있는 값은 0부터 %u까지 입니다.", 
			UCHAR_MAX); 
	printf("\nshort형 변수가 저장할 수 있는 값은 %d부터 %d까지 입니다.", 
			SHRT_MIN, SHRT_MAX); 
	printf("\nunsigned short형 변수가 저장할 수 있는 값은 0부터 %u까지 입니다.", 
			USHRT_MAX); 
	printf("\nint형 변수가 저장할 수 있는 값은 %d부터 %d까지 입니다.", INT_MIN, INT_MAX); 
	printf("\nunsigned int형 변수가 저장할 수 있는 값은 0 부터 %u까지 입니다.", 
			UINT_MAX); 
	printf("\nlong형 변수가 저장할 수 있는 값은 %d부터 %d까지 입니다.", 
			LONG_MIN, LONG_MAX); 
	printf("\nunsigned long 형 변수가 저장할 수 있는 값은 0부터 %u까지 입니다.", 
			ULONG_MAX); 
		
	printf("\n\nfloat형에서 0이 아닌 가장 작은 양수의 크기는 %.3e입니다.", 
			FLT_MIN); 
	printf("\nfloat형에서 가장 큰 값은 %.3e입니다.", FLT_MAX); 
	printf("\ndouble형에서 0이 아닌 가장 작은 양수의 크기는 %.3e입니다.", 
			DBL_MIN); 
	printf("\ndouble형에서 가장 큰 값은 %.3e입니다.", DBL_MAX); 
	printf("\nlong double형에서 0이 아닌 가장 작은 양수의 크기는 %.3e입니다.", 
			DBL_MIN); 
 
	printf("\nlong double형에서 가장 큰 값은 %.3e입니다.\n", 
			DBL_MAX); 
} 
