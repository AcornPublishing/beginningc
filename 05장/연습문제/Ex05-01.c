/*연습문제 5.1 5개 값의 역수의 합 */
#include <stdio.h>

void main()
{
  double data[5];                      /* 데이터 저장             */
  double sum = 0.0;                    /* 역수의 합을 저장할 변수 */
  int i = 0;                           /* 루프 인덱스             */
  printf("5개의 값을 쉼표로 구분해 입력하세요:\n");
  for(i = 0 ; i<5 ; i++)
    scanf("%lf", &data[i]);

  printf("\n다음 값을 입력하셨습니다:\n");
  for(i = 0 ; i<5 ; i++)
    printf("%10.2lf", data[i]);

  printf("\n");
  for(i = 0 ; i<5 ; i++)
  {
    sum += 1.0/data[i];                 /* 역수를 더해나감        */
    if(i>0)
      printf(" + ");
    printf("1/%.2lf", data[i]);
  }
  printf(" = %lf\n", sum);
}

