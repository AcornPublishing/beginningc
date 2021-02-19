/* 연습문제 8.1 평균을 계산하는 함수 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double average(double data[], int count)
{
  int i = 0;
  double sum = 0.0;
  for( i = 0 ; i<count ; sum += data[i++])
    ;
  return sum/count;
}

#define CAPACITY_INCREMENT 6  /* 데이터 값을 저장할 용량의 증가분 */

void main()
{
   double *data = NULL;       /* 데이터의 배열을 가리키는 포인터  */
   double *newdata = NULL;    /* 새 데이터 배열을 가리키는 포인터 */
   double *averages = NULL;   /* 평균의 배열을 가리키는 포인터    */
   int count = 0;             /* 데이터의 개수                    */
   int capacity = 0;          /* 저장할 수 있는 데이터의 개수     */
   int i = 0;                 /* 루프 제어 변수                   */
   char answer = 'n';

   do
   {
     if(count == capacity)
     {
       capacity += CAPACITY_INCREMENT;
       /* 새 포인터 배열을 만듦 */
       newdata = (double*)malloc(capacity*sizeof(double));
  
       if(data != NULL)
       {
         /* 새 배열에 기존의 값 복사 */
         for(i = 0 ; i<count ; i++)
           *(newdata +i) = *(data+i);
         free(data);          /* 이전 포인터 배열의 메모리를 해제 */
       }
       data = newdata;        /* 새 포인터 배열의 주소를 복사     */
       newdata = NULL;        /* 포인터 초기화                    */
     }

     printf("데이터를 하나 입력하세요: ");
     scanf(" %lf", data+count++); 
     printf("더 입력하시겠습니까(y/n)? ");
     scanf(" %c", &answer);
   } while(tolower(answer) != 'n');

   printf("\n입력하신 데이터의 평균은 %10.2lf입니다.\n", average(data, count));
   free(data);
}

