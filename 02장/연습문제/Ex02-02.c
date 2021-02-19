/* 연습문제 2.2  방의 면적 구하기 */
#include <stdio.h>

void main()
{
  double length = 0.0;                     /* 방의 세로길이 */
  double width = 0.0;                      /* 방의 가로길이 */
 
  /* 방의 세로길이를 입력 */
   printf("방의 세로길이를 cm 단위로 입력하세요: ");
   scanf("%lf", &length);

  /* 방의 가로길이를 입력 */
   printf("방의 가로길이를 cm 단위로 입력하세요: ");
   scanf("%lf", &width);

   /* 면적 출력 */
   printf("방의 면적은 %.2f 제곱미터입니다.\n", length*width/10000);
}
