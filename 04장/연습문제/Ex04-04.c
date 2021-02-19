/* 연습문제 4.4 상자 그리기 */
#include <stdio.h>

void main()
{
  int width = 0;                       /* 상자의 폭       */
  int height = 0;                      /* 상자의 높이     */
  int row = 0;                         /* 행 루프 인덱스  */
  int col = 0;                         /* 열 루프 인덱스  */
  printf("상자의 폭과 높이를 스페이스로 구분해 입력하세요: ");
  scanf("%d", &width);
  scanf("%d", &height);

  for(row = 0 ; row<height ; row++)
  {
    printf("\n");                      /* 새 행 시작      */
    for(col = 0 ; col<width ; col++)
    {
      if(row == 0||row==height-1)      /* 첫번째나 마지막 행인가? */
      {
          printf("*");                 /* 그렇다면 모두 별표 출력 */
          continue;
      }
      /* 첫번째와 마지막 열에는 별표, 그 외에는 스페이스 출력 */
      printf("%c", ((col==0 || col==width-1) ? '*' :' '));   
    }
  }
  printf("\n");
}

