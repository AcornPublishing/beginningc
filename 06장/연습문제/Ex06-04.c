/* 연습문제 6.4 회문 검사 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
  char sentence[500];             /* 검사할 문장                 */
  char sentence_chars[500];       /* 구두점과 쉼표를 제거한 문장 */
  size_t i = 0;                   /* 문자 위치의 인덱스          */
  size_t j = 0;                   /* 문자 위치의 인덱스          */
  size_t length = 0;              /* 문자열의 길이               */

  printf("검사할 문장을 입력하세요:\n");
  gets(sentence);

  /* 알파벳만을 소문자로 복사 */
  for (i = 0 ; i< strlen(sentence) ; i++)
    if(isalpha(sentence[i]))
      sentence_chars[j++] = tolower(sentence[i]);
  sentence_chars[j] = '\0';        /* 문자열 종료문자 연결 */

  length = strlen(sentence_chars); /* 문자열 길이 저장     */ 

  /* 문자열에서 대칭 위치에 있는 두 문자를 골라 비교 */
  /* 하나라도 다른 게 있으면 회문이 아님             */
  for(i = 0 ; i<length/2 ; i++)
    if(sentence_chars[i] != sentence_chars[length-1-i])
    {
      printf("\n입력하신 문장은 회문이 아닙니다.\n");
      exit(0);
    }
    /* 여기까지 오면 모든 문자가 모두 일치함 */
    printf("\n입력하신 문장은 회문입니다.\n");
}

