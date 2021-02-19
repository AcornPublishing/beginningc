/* 연습문제 7.4 매일의 기온 입력과 처리 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DAYS             2        /* 입력가능한 최대 일수의 초기값 */
#define READINGS_PER_DAY 6        /* 1일 온도 측정 회수            */

void main()
{
   double **data = NULL;     /* 온도 배열을 가리키는 포인터의 배열을 가리키는 포인터 */
   double **newdata = NULL;  /* 온도 배열을 가리키는 포인터의 배열을 가리키는 포인터 */
   double *averages = NULL;  /* 평균 배열을 가리키는 포인터 */
   int i = 0;
   int j = 0;
   int day = 0;
   int max_days = 0;
   char answer = 'n';

   do
   {
     if(day == max_days)
     {
       max_days += DAYS;
       /* 새 포인터 배열을 만듦 */
       newdata = (double**)malloc(max_days*sizeof(double*));
       /* 새로운 날의 기록을 저장할 double형 배열을 만들고 주소를 저장 */
       for(i = day ; i<max_days ; i++)
         *(newdata+i) = (double*)malloc(READINGS_PER_DAY*sizeof(double));
       if(data != NULL)
       {
         /* 기존 온도 배열의 주소를 복사 */
         for(i = 0 ; i<day ; i++)
           *(newdata +i) = *(data+i);
         free(data);          /* 이전 포인터 배열의 메모리를 해제 */
       }
       data = newdata;        /* 새 포인터 배열의 주소를 복사 */
       newdata = NULL;        /* 포인터 초기화                */
     }

     printf("하루의 온도 기록 %d개를 입력하세요:\n", READINGS_PER_DAY);
     for(i = 0 ; i<READINGS_PER_DAY ; i++)
       scanf(" %lf", *(data+day)+i); 
     ++day;
     printf("다른 날의 기록도 입력하시겠습니까(y/n)? ");
     scanf(" %c", &answer);
   } while(tolower(answer) != 'n');

   /* 온도 값을 저장하지 않은 메모리는 해제 */
   for(i = day ; i<max_days ; i++)
     free(*(data+i));

   /* 평균을 저장할 메모리 할당 */
   averages = (double*)malloc(day*sizeof(double));

   /* 평균 계산 */
   for(i = 0 ; i<day ; i++)
   {
     *(averages+i) = 0.0;
     for(j = 0 ; j<READINGS_PER_DAY ; j++)
       *(averages+i) += *(*(data+i)+j);
     *(averages+i) /= READINGS_PER_DAY;
   }
   printf("\n입력하신 날의 기온과 평균기온은 다음과 같습니다.\n");
   for(i = 0 ; i<day ; i++)
   {
     for(j = 0 ; j<READINGS_PER_DAY ; j++)
       printf("%10.1lf", *(*(data+i)+j));
     printf("%10.1lf\n", *(averages+i));
   }
   /* 모든 메모리 해제 */
   free(averages);
   for(i = 0 ; i<day ; i++)
     free(*(data+i));
   free(data);
}

