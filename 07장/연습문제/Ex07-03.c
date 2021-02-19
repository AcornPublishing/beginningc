/* 연습문제 7.3 문자열에서 스페이스와 구두점 지우기 */
#include <stdio.h>
#include <ctype.h>

#define BUFFER_LEN 500             /* 입력버퍼의 길이 */

void main()
{
   char buffer[BUFFER_LEN];        /* 입력버퍼                   */
   char *pbuffer1 = buffer;        /* 버퍼위치를 가리키는 포인터 */
   char *pbuffer2 = buffer;        /* 버퍼위치를 가리키는 포인터 */

   /* 문자열 읽기 */
   printf("문자열을 %d문자 이하로 입력하세요:\n", BUFFER_LEN);
   while((*pbuffer1++ = getchar()) != '\n');
   *pbuffer1 = '\0';               /* 문자열 종료문자 연결       */
   pbuffer1 = buffer;              /* 포인터를 시작위치로 초기화 */
   while(*pbuffer1 != '\0')        /* 문자열 끝까지 반복         */
   {
     if(ispunct(*pbuffer1) || isspace(*pbuffer1))
     {                             /* 스페이스나 구두점일 경우 */
       ++pbuffer1;                 /* 다음 문자로 넘어감       */
       continue;
     }
     else
       *pbuffer2++ = *pbuffer1++;  /* 그렇지 않으면 문자 복사  */
   }
   *pbuffer2 = '\0';               /* 문자열 종료문자 연결     */
   printf("\n스페이스와 구두점을 제거한 문장은 다음과 같습니다:\n%s\n", buffer);
}

