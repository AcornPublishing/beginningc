/* 프로그램 2.8 테이블의 둘레와 면적 */ 
#include <stdio.h> 
 
void main() 
{ 
	float radius = 0.0f; 										/* 테이블의 반지름 */ 
	float diameter = 0.0f; 										/* 테이블의 지름   */ 
	float circumference = 0.0f; 								/* 테이블의 둘레   */ 
	float area = 0.0f; 											/* 테이블의 면적   */ 
	float Pi = 3.14159265f; 

	printf("테이블의 지름을 입력하세요:");
	scanf("%f", &diameter); 									/* 키보드에 입력한 지름을 읽어들임 */
	radius = diameter/2.0f; 									/* 반지름 계산					   */
	circumference = 2.0f*Pi*radius; 							/* 둘레 계산					   */
	area = Pi*radius*radius; 									/* 면적 계산					   */

	printf("\n둘레는 %.2f입니다.", circumference);
	printf("n면적은 %.2f입니다.\n", area);
} 
