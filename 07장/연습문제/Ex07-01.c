/* 연습문제 7.1 포인터를 이용한 실수 평균 계산 */
/**********************************************************************
 * 이 프로그램에서는 메모리를 조금 할당한 다음, 이 메모리가 가득 차면 *
 * 이보다 좀 더 큰 메모리를 새로 할당해 이전 메모리의 내용을 새 메모  *
 * 리로 복사하고 이전 메모리는 해제한다. 이 과정은 필요할 때마다 반복 *
 * 된다.                                                              *
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
  double *values = NULL;     /* 데이터 값을 저장하는 메모리의 포인터 */
  double *temp = NULL;       /* 새로 할당된 메모리의 포인터          */
  double sum = 0.0;          /* 값들의 합                            */
  int capacity = 0;          /* 저장할 수 있는 값의 최대 개수        */
  int increment = 5;         /* 동적 할당된 메모리 용량의 증가값     */
  int count = 0;             /* 읽은 값의 개수                       */
  int i = 0;                 /* 배열 인덱스                          */
  char answer = 'n';

  do
  {
    if(count == capacity)    /* 메모리에 공간이 있는지 검사 */
    {
      capacity += increment; /* 메모리의 용량을 increment만큼 증가시키고 */
      temp = (double*)malloc((capacity)*sizeof(double)); /* 새로 할당함  */
      if(temp == NULL)       /* 메모리를 할당하지 못했으면      */
      {                      /* 메시지를 출력하고 프로그램 종료 */
        printf("메모리 할당에 실패했습니다. 프로그램을 종료합니다.");
        exit(1);
      }
      if(values == NULL)     /* 값이 있는가?    */
        values = temp;       /* 아니오 - 새 메모리의 주소를 복사             */
      else                   /* 예 - 이전 메모리의 데이터를 새 메모리에 복사 */
      {
        for(i = 0 ; i<count ; i++)
          *(temp+i) = *(values+i);
        free(values);        /* 이전 메모리 해제        */
        values = temp;       /* 새 메모리의 주소를 복사 */
      } 
      temp = NULL;           /* 포인터 초기화           */
    }

    printf("값을 입력하세요: ");
    scanf("%lf", values+count++);

    printf("더 입력하시겠습니까(y/n)? ");
    scanf(" %c", &answer);
  }while(tolower(answer) == 'y');

  /* 입력받은 값의 합계를 구함 */
  for(i = 0 ; i<count ; i++)
    sum += *(values+i);

  /* 평균 출력 */
  printf("\n입력하신 값의 평균은 %.2lf입니다.\n", sum/count);
  free(values);     /* 모두 끝났으므로 메모리 해제 */
}

