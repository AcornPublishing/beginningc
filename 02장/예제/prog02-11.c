/* 프로그램 2.11 용도에 맞는 데이터형 고르기 1 */ 
#include <stdio.h> 

void main() 
{ 
	const float Revenue_per_150 = 4.5f; 
	short JanSold = 23500; 											/* 1월에 판매한 상품 	  */ 
	short FebSold = 19300; 											/* 2월에 판매한 상품 	  */ 
	short MarSold = 21600; 											/* 3월에 판매한 상품 	  */ 
	float RevQuarter = 0.0f; 										/* 1분기 매출액 		  */ 

	short QuarterSold = JanSold + FebSold + MarSold;				/* 1분기 전체 판매량 계산 */ 

	/* 월별 상품 판매량과 분기 전체 판매량을 출력 */
	printf("\n월별 상품 판매량\n 1월: %d\n 2월: %d\n 3월: %d",
					JanSold, FebSold, MarSold);
	printf("\n1분기 총 상품 판매량: %d",QuarterSold);

	/* 1분기 총 매출액을 계산하고 출력함 */ 
	RevQuarter = QuarterSold/150*Revenue_per_150; 
	printf("\n1분기 전체 매출액: %.2f만원\n",RevQuarter); 
} 
