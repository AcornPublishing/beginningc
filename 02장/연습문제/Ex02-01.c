/* 연습문제 2.1 인치를 야드, 피트, 인치로 변환 */
#include <stdio.h>

void main()
{
  int inches = 0;
  int yards = 0;
  int feet = 0;
  const int inches_per_foot = 12;
  const int feet_per_yard = 3;
  printf("거리를 인치 단위로 입력하세요: ");
  scanf("%d", &inches);

  feet = inches/inches_per_foot;  /* 피트 계산			*/
  yards = feet/feet_per_yard;     /* 야드 계산			*/
  feet %= feet_per_yard;          /* 나머지 피트 계산   */
  inches %= inches_per_foot;      /* 나머지 인치 계산   */

  printf("\n입력하신 거리는 %d야드 %d피트 %d인치입니다.\n",
          yards, feet, inches);
}
