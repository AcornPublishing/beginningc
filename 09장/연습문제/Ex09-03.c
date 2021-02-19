/* 연습문제 9.3 문자열의 배열을 하나의 문자열로 결합 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 100                         /* 최대 문자열 개수                     */
#define BUFFER_SIZE 50                          /* 초기 입력버퍼 크기                   */

char* join_strings(char *strings[], int count); /* 문자열의 배열을 하나의 문자열로 결합하는 함수 */
char* read_string();                            /* 키보드에서 문자열을 읽는 함수                 */

void main()
{
  char *pStrings[MAX_STRINGS];       /* 문자열을 가리키는 포인터의 배열 */
  char *joined_strings = NULL;       /* 결합한 문자열을 가리키는 포인터 */
  int count = 0;                     /* 입력한 문자열의 개수            */
  char answer = 'y';                 /* 더 입력할 것인지의 여부         */
  char terminator = '*';             /* 문자열 입력 종료에 사용         */
  int i = 0;

  /* 문자열 읽기 */
  while(count<MAX_STRINGS && tolower(answer)=='y')
  {
    printf("문자열을 입력하세요:\n");
    pStrings[count++] = read_string(terminator);

    printf("더 입력하시겠습니까?(y/n) ");
    scanf(" %c", &answer);
    fflush(stdin);                     /* 읽기 버퍼 비움 */
  }

  joined_strings = join_strings(pStrings, count); 
  printf("\n입력하신 문자열을 하나로 결합합니다:\n%s\n", joined_strings);

  free(joined_strings);                /* 결합한 문자열의 메모리 해제   */
  for(i = 0 ; i<count ; i++)           /* 입력받은 문자열의 메모리 해제 */
    free(pStrings[i]);
}

/************************************************************************
 * 문자열의 배열을 결합하는 함수                                        *
 * 이 함수는 메모리를 할당하며, 호출하는 쪽에서 이 메모리를 해제해야 함 *
 ************************************************************************/
char* join_strings(char *strings[], int count)
{
  char* str = NULL;             /* 결합한 문자열의 포인터    */
  size_t total_length = 0;      /* 결합한 문자열의 전체 길이 */
  size_t length = 0;            /* 문자열의 길이             */
  int i = 0;                    /* 루프 카운터               */

  /* 결합한 문자열의 전체 길이 계산 */
  for(i = 0 ; i<count ; i++)
  {
    total_length += strlen(strings[i]);
    if(strings[i][strlen(strings[i])-1] != '\n')
      ++total_length; /* 줄바꿈 문자도 포함 */
  }
  ++total_length;     /* 문자열 종료문자도 포함 */

  str = (char*)malloc(total_length);  /* 결합한 문자열의 메모리 할당 */
  str[0] = '\0';                      /* 문자열을 비움               */

  /* 문자열 연결 */
  for(i = 0 ; i<count ; i++)
  {
    strcat(str, strings[i]);
    length = strlen(str);

    /* 줄바꿈문자를 삽입해야 하는지 검사 */
    if(str[length-1] != '\n')
    {
      str[length] = '\n';             /* 줄바꿈 문자 연결 */
      str[length+1] = '\0';           /* 문자열 종료문자 연결 */
    }
  }
  return str;
}

/***************************************************************************
 * 어떤 길이의 문자열도 읽어들이는 함수.                                   *
 * 문자열은 인자로 넘겨진 문자로 끝난다.                                   *
 * 메모리를 할당해 문자열을 저장하며, 호출한 곳에서 반드시 해제해야 한다.  *
 ***************************************************************************/
char* read_string(char terminator)
{
  char *buffer = NULL;            /* 입력버퍼를 가리키는 포인터  */
  int buffersize = BUFFER_SIZE;   /* 현재 버퍼 용량              */
  int length = 0;                 /* 문자열 길이                 */
  char *temp = NULL;              /* 임시 버퍼 포인터            */
  int i = 0;                      /* 루프 카운터                 */

  buffer = (char*)malloc(BUFFER_SIZE);  /* 초기 버퍼 */
  /* 문자열을 한 문자씩 읽어들임 */
  for(;;)
  {
    /* 문자열 종료문자 검사 */ 
    if((buffer[length] = getchar()) == terminator)
      break;
    else
      ++length;

    /* 버퍼가 가득 찼는지 검사 */
    if(length == buffersize)
    {
      buffersize += BUFFER_SIZE;          /* 버퍼 크기를 증가 */
      temp = (char*)malloc(buffersize);   /* 새 버퍼 할당     */

      /* 이전 버퍼에서 새 버퍼로 복사 */
      for(i = 0 ; i<length ; i++)
        temp[i] = buffer[i];

      free(buffer);                       /* 이전 버퍼의 메모리 해제 */
      buffer = temp;                      /* 새 버퍼의 주소 저장     */
      temp = NULL;                        /* 임시 포인터 초기화      */
    }
  }
  buffer[length] = '\0';                  /* 문자열 종료문자 연결                    */
  temp = (char*)malloc(length+1);         /* 문자열 저장에 필요한 정확한 메모리 할당 */
  strcpy(temp, buffer);                   /* 문자열 복사      */
  free(buffer);                           /* 버퍼 메모리 해제 */
  return temp;
}
