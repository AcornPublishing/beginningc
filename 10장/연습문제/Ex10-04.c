/* 연습문제 10.5 임의의 문자로 끝나는 문자열 읽어들이기 */
#include <stdio.h>
#include <string.h>

#define MAX_SIZE     100
#define STRING_COUNT   5

char* getString(char *buffer, char end_char);

void main()
{
  char buffer[MAX_SIZE] = {0};
  int i = 0;
  for(i = 0 ; i<STRING_COUNT ; i++)
  {
    printf("콜론으로 끝나는 문자열을 입력하세요.\n");
    getString(buffer, ':');
    printf("입력한 문자열은 다음과 같습니다.\n%s\n", buffer);
  }
}

char* getString(char *buffer, char end_char)
{
  size_t i = 0;
  /* end_char를 입력할 때까지 문자열 읽기 */
  while((buffer[i++] = getchar()) != end_char)
    ;
  buffer[i-1] = '\0';  /* end_char를 종료문자로 대체 */
  return buffer;
}
