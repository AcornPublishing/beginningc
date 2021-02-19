/* 연습문제 6.2 쉼표로 구분된 단어목록 분석 */
#include <stdio.h>
#include <string.h>

void main()
{
  char list[5000];         /* 쉼표로 구문된 단어 목록 저장   */
  char words[500][20];     /* 20문자 이하의 단어를 500개까지 저장할 수 있는 배열 */
  const char comma = ',';
  const char space = ' ';
  int word_count = 0;      /* 단어의 개수      */
  int word_length = 0;     /* 현재 단어의 길이 */
  int index = 0;           /* 문자 위치        */

  printf("단어를 쉼표로 구분해 입력하세요:\n");
  gets(list);              /* 단어 목록 읽음 */

  /* 목록에서 단어 찾기 */
  while(list[index] != '\0')
  {
    /* 스페이스와 쉼표는 무시 */
    while(list[index] == space || list[index] == comma)
      ++index;

    /* 스페이스, 쉼표, \0이 아닌 문자를 복사 */
    while(list[index] != space && list[index] != comma && list[index] != '\0')
     words[word_count][word_length++] = list[index++];

    words[word_count++][word_length] = '\0';    /* 종료문자 연결 */
    word_length = 0;                            /* 다음 단어를 위한 초기화 */
  }

  /* 찾은 단어를 모두 출력 */
  printf("\n입력하신 단어는 다음과 같습니다:\n");
  for(index = 0 ; index<word_count ; index++)
    printf("%s\n",words[index]);
}

