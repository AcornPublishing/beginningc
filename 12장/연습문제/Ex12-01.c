/* 연습문제 12.1 파일에 문자열 쓰기 */
/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define BUFFER_SIZE 50

/* 함수원형 */
void read_string();

/* 전역변수 */
FILE *pFile = NULL;                   /* 파일 포인터        */
char *filename = "C:\\myfile.txt";    /* 기록할 파일의 이름 */
char *buffer = NULL;
int buffer_size = BUFFER_SIZE;


void main()
{
  char answer = 'n';
  size_t str_length = 0;

  buffer = (char*)malloc(buffer_size);    /* 초기 버퍼를 만듦   */

  pFile = fopen(filename, "w");           /* 기록할 파일을 만듦 */
  if(pFile == NULL)
  {
    printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
    abort();
  }

  do
  {
    /* 키보드에서 문자열을 읽음 */
    printf("문자열을 입력하세요:\n");
    read_string();                                  /* 버퍼에 문자열 읽음        */
    str_length = strlen(buffer);                    /* 문자열 길이를 알아냄      */
    fwrite(&str_length, sizeof(size_t), 1, pFile);  /* 파일에 문자열 길이를 기록 */
    fwrite(buffer, str_length, 1, pFile);           /* 문자열을 파일에 기록      */

    printf("더 입력하시겠습니까(y/n)? ");
    scanf(" %c", &answer);
    fflush(stdin);                                   /* 입력버퍼를 비워 줄바꿈문자를 없앰 */
  }while(tolower(answer) == 'y');

  fclose(pFile);                                    /* 파일 닫기 */ 
  printf("\n파일 기록이 끝났습니다.\n");
  if(buffer != NULL)
    free(buffer);
 }

/* 임의 길이의 문자열을 키보드에서 읽는 함수              */
/* 문자열이 버퍼 용량을 초과하면 자동으로 버퍼를 증가시킴 */
void read_string()
{
  char *temp = NULL;                      /* 새 버퍼 주소를 저장할 때 사용하는 변수 */
  int position = 0;                       /* 버퍼의 현재 빈 위치 */

  while((buffer[position++] = getchar()) != '\n')
    if(position >= buffer_size-1)         /* 버퍼가 가득 찼는가? */
    { /* 버퍼의 크기를 증가시킴 */
      buffer_size += BUFFER_SIZE;         /* 새 버퍼 크기   */
      temp = (char*)malloc(buffer_size);  /* 새 버퍼를 만듦 */
      buffer[position] = '\0';            
      strcpy(temp, buffer);               /* 이전 버퍼를 새 버퍼에 복사 */
      free(buffer);                       /* 이전 버퍼 해제             */
      buffer = temp;                      /* 새 버퍼의 주소 저장        */
      temp = NULL;
    }
  buffer[position-1] = '\0';              /* 줄바꿈 문자를 종료문자로 바꿈 */
}