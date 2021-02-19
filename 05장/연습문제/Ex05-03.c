/*연습문제 5.3 통화 값을 정수로 처리하기 */
#include <stdio.h>

void main()
{
  float amounts[5];                     /* 데이터 저장 */
  long dollars[5];
  long cents[5];
  int i = 0;                            /* 루프 인덱스 */
  printf("5개의 금액을 스페이스로 구분해 입력하세요:\n");
  for(i = 0 ; i<5 ; i++)
    scanf("%f", &amounts[i]);

  for(i = 0 ; i<5 ; i++)
  {
    dollars[i] = (long)amounts[i];
    cents[i] = (long)(100.0*(amounts[i]-dollars[i]));
  }

  printf("\n");
  for(i = 0 ; i<5 ; i++)
  {
    printf("  $%d.%02d", dollars[i], cents[i]);
  }
  printf("\n");
}

