/* 프로그램 2.10 테이블의 둘레와 면적 - 좀 더 간단하게 */ 
#include <stdio.h> 

void main() 
{ 	
	float diameter = 0.0f; 									/* 테이블의 지름 		   */
	float radius = 0.0f; 									/* 테이블의 반지름 		   */
	const float Pi = 3.14159f; 								/* Pi를 고정된 값으로 정의 */

	printf("테이블의 지름을 입력하세요:");
	scanf("%f", &diameter);
	radius = diameter/2.0f;
	printf("\n둘레는 %.2f입니다.", 2.0f*Pi*radius);
	printf("\n면적은 %.2f입니다.", Pi*radius*radius);
} 
