/* 연습문제 2.3  제품 단가 출력 */

#include <stdio.h>

void main()
{
  int total_price = 0;                     /* 전체 가격   */
  int type = 0;                            /* 제품 유형   */
  int quantity = 0;                        /* 주문한 수량 */
  const int type1_price = 5000;
  const int type2_price = 8000;

   /* 제품 유형 입력 */
   printf("제품의 종류를 입력하세요 (일반형-1, 고급형-2): ");
   scanf("%d", &type);

   /* 제품 수량 입력 */
   printf("제품의 수량을 입력하세요: ");
   scanf("%d", &quantity);

   /* 전체 가격 계산 */
   total_price = quantity*(type1_price + (type-1)*(type2_price-type1_price));

   /* 가격 출력 */
   printf("%d형 제품  %d개의 가격은 %d원입니다.\n",
     type, quantity, total_price);
}
