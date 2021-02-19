/*연습문제 4.1 곱셈표 만들기 */
#include <stdio.h>

void main()
{
  int table_size = 0;                       /* 표의 크기      */
  int row = 0;                              /* 행 루프 인덱스 */
  int col = 0;                              /* 열 루프 인덱스 */
  printf("곱셈표의 크기를 입력하세요 (2~12): ");
  scanf("%d", &table_size);
  if(table_size>12)
  {
    printf("\n표의 크기가 12를 넘을 수 없습니다. 12로 설정합니다.");
    table_size = 12;
  }
  else if(table_size<2)
  {
    printf("\n표의 크기가 2보다 작으면 안됩니다. 2로 설정합니다.");
    table_size = 2;
  }

  for(row = 0 ; row<=table_size ; row++)
  {
    printf("\n");                      /* 새로운 행 시작 */
    for(col = 0 ; col<=table_size ; col++)
    {
      if(row == 0)                     /* 첫번째 행인가?               */
      {                                /* 예 - 열 제목 출력            */
        if(col == 0)                   /* 첫번째 열인가?               */
          printf("    ");              /* 예 - 제목 출력하지 않음      */
        else
          printf("|%4d", col);         /* 아니오 - 제목 출력           */
      }
      else
      {                               /* 첫번째 행이 아니면 행을 출력  */
        if(col == 0)                  /* 첫번째 열인가?                */
          printf("%4d", row);         /* 예 - 행 제목 출력             */
        else
          printf("|%4d", row*col);    /* 아니오 - 값 출력              */
      }
    }
    if(row == 0 )                     /* 첫번째 행을 출력하고 나면     */
    {                                 /* 표 구분선을 출력              */
      printf("\n");
      for(col=0 ; col<=table_size ; col++)
        printf("_____");
    }
  }
  printf("\n");
}

