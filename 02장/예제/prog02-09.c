/* 프로그램 2.9 테이블의 둘레와 면적*/
#include <stdio.h>
#define PI 3.14159f 					/* 기호 PI의 정의 */

void main() 
{ 
	float radius = 0.0f; 
	float diameter = 0.0f; 
	float circumference = 0.0f; 
	float area = 0.0f; 

	printf("테이블의 지름을 입력하세요:");
	scanf("%f", &diameter);
	radius = diameter/2.0f;
	circumference = 2.0f*PI*radius;
	area = PI*radius*radius;
	printf("\n둘레는 %.2f입니다.", circumference);
	printf("\n면적은 %.2f입니다.", area);
} 
