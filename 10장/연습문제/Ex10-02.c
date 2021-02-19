/* 연습문제 10.2 돈 계산 */
/*
  입력 형식 문자열에서 '$', 스페이스, 쉼표만 무시하면 됨
*/
#include <stdio.h>

void main()
{
  double amounts[4] = {0.0};
  double total = 0.0;
  int i = 0;

   printf("4개의 값을 입력하세요:\n");
   for(i = 0 ; i<4 ; i++)
   {
     scanf("%*[ ,$]%lf", &amounts[i]);
     total += amounts[i];
   }
     
   printf("입력하신 값의 합계는 $%.2lf입니다.\n", total);
}

