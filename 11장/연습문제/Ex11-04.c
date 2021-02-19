/* 연습문제 11.4 구조체를 사용해 단어 출현 회수를 기록하는 프로그램 */
/*
  이 프로그램에서는 단어와 출현회수를 저장하는 구조체를 정의한다.
  이 구조체는 연결 리스트에 생성되어 저장된다. 알파벳 순으로 출력하고 싶다면
  리스트가 정렬될 수 있도록 구조체를 리스트에 삽입할 수 있다.
  아니면 리스트를 정렬해도 된다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH    31
#define MAX_TEXT_LENGTH 10000
#define TRUE                1
#define FALSE               0

/* 단어의 출현회수를 정의하는 구조체 */
struct WordCounter
{
  char *word;
  int word_count;
  struct WordCounter *pNext;                        /* 목록의 다음 구조체를 가리키는 포인터 */
};

/* 함수원형 */
void addWord(char *pWord);                          /* 리스트에 단어를 추가하거나 기존 단어를 업데이트하는 함수 */
int is_separator(char ch);                          /* 구분문자를 검사하는 함수 */
void show(struct WordCounter *pWordcounter);        /* 단어와 출현회수를 출력하는 함수 */
struct WordCounter* createWordCounter(char *word);  /* 새 WordCounter 구조체를 만드는 함수 */

/* 전역변수 */
struct WordCounter *pStart = NULL;                  /* 리스트의 첫번째 구조체를 가리키는 포인터 */


void main()
{
  char text[MAX_TEXT_LENGTH];           /* 입력 텍스트 저장     */
  char buffer[MAX_WORD_LENGTH];         /* 단어를 저장하는 버퍼 */
  size_t i = 0;                         /* 텍스트의 인덱스      */
  int len = 0 ;                         /* 단어의 길이          */
  struct WordCounter *pCounter = NULL;  /* WordCounter의 포인터 */      

  /* 키보드에서 텍스트를 읽음 */
  printf("텍스트를 입력하세요:\n");
  gets(text);

  /* 텍스트에서 단어를 추출  */  
  while(text[i] != '\0')
  {
    /* 구분자는 그냥 넘어감 */
    while(is_separator(text[i]))
      ++i;

    /* 이제 문자열의 끝이거나 단어의 시작위치다. */
    /* 문자열 종료문자가 아니면 문자를 복사한다. */
    len = 0;              /* 문자 개수를 초기화 */
    while((!is_separator(text[i])) && (text[i] != '\0'))
      buffer[len++] = text[i++];
    if(len>0)               /* 단어에 문자가 있는지 검사 */
    {
      buffer[len] = '\0';   /* 단어의 끝에 다다랐으므로 종료문자를 연결 */
      addWord(buffer);      /* 단어를 리스트에 추가 */
    }
  }

  /* 단어와 출현회수를 출력 */
  pCounter = pStart;
  while(pCounter != NULL)
  {
    show(pCounter);
    pCounter = pCounter->pNext;
  }
  printf("\n");

  /* 할당한 메모리 해제 */
  pCounter = pStart;
  while(pCounter != NULL)
  {
    free(pCounter->word);        /* 단어 저장 메모리 해제 */
    pStart = pCounter;           /* 현재 주소 저장        */
    pCounter = pCounter->pNext;  /* 다음 카운터를 이동    */
    free(pStart);                /* 현재 메모리 해제      */     
  }
}

/* 인자가 구분문자이면 TRUE를, 아니면 FALSE를 반환하는 함수 */
int is_separator(char ch)
{
  /* 구분문자는 스페이스, 쉼표, 콜론, 세미콜론, 따옴표, 물음표, 느낌표, 마침표임 */
  static char separators[] = { ' ' , ',',':' , '\"', '?' , '!' , '.'};
  int i = 0;

  for(i = 0 ; i<sizeof separators ; i++)
  {
    if(ch == separators[i])
      return TRUE;
  }

  return FALSE;
}

void show(struct WordCounter *pWordcounter)
{
  /* 단어를 고정된 필드폭에 왼쪽정렬로 출력하고 그 옆에 출현회수를 출력 */
  printf("\n%-30s   %5d", pWordcounter->word,pWordcounter->word_count);
}

void addWord(char *word)
{
  struct WordCounter *pCounter = NULL;
  struct WordCounter *pLast = NULL;

  if(pStart == NULL)
  {
    pStart = createWordCounter(word);
    return;
  }

  /* 단어가 리스트에 있으면 출현회수를 1 증가시킴 */
  pCounter = pStart;
  while(pCounter != NULL)
  {
    if(strcmp(word, pCounter->word) == 0)
    {
      ++pCounter->word_count;
      return;
    }
    pLast = pCounter;            /* 필요할 경우 마지막의 주소를 저장     */
    pCounter = pCounter->pNext;  /* 포인터를 리스트의 다음 포인터로 이동 */
  }
 
  /* 여기까지 왔다면 리스트에 없는 단어이므로 추가함 */
  pLast->pNext = createWordCounter(word);
}

/* 인자 값으로 새 WordCounter 인스턴스를 만들어 반환함 */
struct WordCounter* createWordCounter(char *word)
{
  struct WordCounter *pCounter = NULL;
  pCounter = (struct WordCounter*)malloc(sizeof(struct WordCounter));
  pCounter->word = (char*)malloc(strlen(word)+1);
  strcpy(pCounter->word, word);
  pCounter->word_count = 1;
  pCounter->pNext = NULL;
  return pCounter;
}
