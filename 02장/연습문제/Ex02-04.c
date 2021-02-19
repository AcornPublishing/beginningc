/* 연습문제 2.4  시간당 평균임금 계산 */
#include <stdio.h>

void main()
{
  int pay = 0;                     /* 월급            */
  int hours = 0;                   /* 월 근무 시간	  */
  double payperhour = 0.0;         /* 시간당 평균임금 */

   /* 월급 입력 */
   printf("월급을 입력하세요: ");
   scanf("%d", &pay);

  /* 근무시간 입력 */
   printf("월 근무시간을 입력하세요: ");
   scanf("%d", &hours);

   /* 평균임금 계산 */
   payperhour = (double)pay/(double)hours;

   /* 시간당 평균임금 출력 */
   printf("당신의 시간당 평균임금은 %.2f원입니다.\n", payperhour);
}
