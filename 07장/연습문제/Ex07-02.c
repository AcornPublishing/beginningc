/* 연습문제 7.2 격언을 입력받아 길이순으로 출력하는 코드 */
/****************************************************************************
 * 이 프로그램은 어떠한 길이의 격언을 몇개라도 읽어들인다.                  *
 * 입력버퍼의 길이는 초기값이 있지만 부족할 경우 자동으로 증가한다.         *
 * 이전 버퍼의 현재 내용은 새 버퍼에 복사되고, 이전 버퍼는 입력을 계속하기  *
 * 앞서 해제된다.                                                           *
 * 같은 원리가 격언에도 적용된다.격언을 가리키는 포인터의 초기용량을 초과   *
 * 하면 더 큰 공간이 할당되고 기존 포인터가 새 메모리에 복사된 뒤 이전      * 
 * 메모리가 해제된다.                                                       *
 * 새 메모리가 할당될 때 printf()문을 이용해 이를 기록할 수도 있을 것이다.  *
 * BUFFER_LEN, BUFFER_LEN_INCR, CAPACITY_INCR값은 작게 설정돼 있으므로      *
 * 자주 메모리가 재할당되어 여러분의 입력을 받아들일 수 있게 한다.          *
 * 실제 프로그램에서는 이보다 훨씬 큰 값으로 설정돼 너무 빈번한 메모리 할당 *
 * 과 해제가 일어나지 못하게 할 것이다.                                     *
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LEN 5          /* 입력 버퍼의 초기 길이 */
#define BUFFER_LEN_INCR 2     /* 버퍼 길이의 증가분    */
#define CAPACITY_INCR 2       /* 격언 용량의 증가분    */

void main()
{
   char **pProverbs = NULL;        /* 문자열 포인터의 포인터      */
   char **temp = NULL;             /* 문자열 포인터의 임시 포인터 */
   int capacity = 0;               /* 저장할 수 있는 격언의 개수  */
   int count = 0;                  /* 읽은 격언의 개수            */
   char *pbuffer = NULL;           /* 버퍼의 포인터               */
   char *pstart = NULL;            /* 버퍼 시작위치의 포인터      */
   char *pstr = NULL;              /* 문자열 포인터               */
   int buffer_length = BUFFER_LEN; /* 버퍼 길이                   */
   int i = 0;                      /* 루프 카운터                 */
   int j = 0;                      /* 루프 카운터                 */

   pbuffer = (char*)malloc(BUFFER_LEN);  /* 초기 버퍼 크기     */
   pstart = pbuffer;                     /* 버퍼 시작위치 저장 */

   for(;;)
   {
     if(count==capacity)
     {
       capacity += CAPACITY_INCR;
       temp = (char**)malloc(capacity*sizeof(char*));
       if(temp == NULL)       /* 메모리가 할당되지 않았으면 */
       {                      /* 메시지를 출력하고 종료     */
         printf("Memory allocation failed. Terminating program.");
         exit(1);
       }
     
       if(pProverbs == NULL)  /* 격언이 하나도 없는가?                        */
         pProverbs = temp;    /* 아니오 - 새 메모리의 주소만을 출력           */
       else                   /* 예 - 이전 메모리의 데이터를 새 메모리로 복사 */
       {
         for(i = 0 ; i<count ; i++)
           *(temp+i) = *(pProverbs+i);
         free(pProverbs);     /* 이전 메모리 해제      */
         pProverbs = temp;    /* 새 메모리의 주소 복사 */
       } 
       temp = NULL;           /* 포인터 초기화         */
     }
      printf("격언을 입력하세요. 끝내려면 그냥 엔터를 누르세요:\n");

     /* 격언 입력 */
     while((*pbuffer++ = getchar()) != '\n')
     {
       if(pbuffer-pstart == buffer_length)     /* 버퍼가 가득 찼는지 검사 */
       {
         buffer_length += BUFFER_LEN_INCR;     /* 버퍼 길이 증가          */
         pstr = (char*)malloc(buffer_length);  /* 새 버퍼 할당            */

         /* 이전 버퍼의 내용을 새 버퍼로 복사 */
         for(i = 0; i<pbuffer-pstart ; i++)
           *(pstr+i) = *(pstart+i);

         pbuffer = pstr+(pbuffer-pstart);      /* 새 버퍼의 다음 주소 저장 */
         free(pstart);                         /* 이전 버퍼 메모리 해제    */
         pstart = pstr;                        /* 새 버퍼의 시작위치 설정  */
         pstr = NULL;                          /* 포인터 초기화            */
       }
     }

     /* 입력의 끝을 알리는 빈 행 검사 */
     if((pbuffer-pstart)<2)
       break;

     /* 문자열이 너무 길지 않은지 검사 */
     if((pbuffer - pstart) == BUFFER_LEN && *(pbuffer-1)!= '\n')
     {
       printf("문자열이 너무 깁니다. 최대 %d문자까지 입력할 수 있습니다.", BUFFER_LEN);
       pbuffer = pstart;
       continue;
     }
     *(pbuffer-1) = '\0';                  /* 종료문자 연결 */
     pbuffer = pstart;

     *(pProverbs+count) = (char*)malloc(strlen(pstart)+1);
     strcpy(*(pProverbs+count++),pstart);
   }

   /* 격언을 길이 역순으로 정렬 */
  for(i = 0 ; i<count-1 ; i++)
    for(j = i+1 ; j<count ; j++)
      if(strlen(*(pProverbs+i))>strlen(*(pProverbs+j)))
      {
        pstr = *(pProverbs+i);
        *(pProverbs+i) = *(pProverbs+j);
        *(pProverbs+j) = pstr;
      }

   /* 문자열 출력 */
   printf("\n입력하신 문자열을 길이가 짧은 것부터 출력합니다:\n");
   for (i = 0 ; i<count ; i++ )
   {
      printf("\n%s", *(pProverbs + i));
      free(*(pProverbs + i));   /* 격언이 저장된 메모리 해제 */
      *(pProverbs + i) = NULL;  /* 포인터를 다시 NULL로 설정 */
   }
   free(pProverbs);             /* 포인터가 저장된 메모리 해제 */
   free(pstart);                /* 버퍼가 저장된 메모리 해제   */
}

