/* �������� 11.4 ����ü�� ����� �ܾ� ���� ȸ���� ����ϴ� ���α׷� */
/*
  �� ���α׷������� �ܾ�� ����ȸ���� �����ϴ� ����ü�� �����Ѵ�.
  �� ����ü�� ���� ����Ʈ�� �����Ǿ� ����ȴ�. ���ĺ� ������ ����ϰ� �ʹٸ�
  ����Ʈ�� ���ĵ� �� �ֵ��� ����ü�� ����Ʈ�� ������ �� �ִ�.
  �ƴϸ� ����Ʈ�� �����ص� �ȴ�.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH    31
#define MAX_TEXT_LENGTH 10000
#define TRUE                1
#define FALSE               0

/* �ܾ��� ����ȸ���� �����ϴ� ����ü */
struct WordCounter
{
  char *word;
  int word_count;
  struct WordCounter *pNext;                        /* ����� ���� ����ü�� ����Ű�� ������ */
};

/* �Լ����� */
void addWord(char *pWord);                          /* ����Ʈ�� �ܾ �߰��ϰų� ���� �ܾ ������Ʈ�ϴ� �Լ� */
int is_separator(char ch);                          /* ���й��ڸ� �˻��ϴ� �Լ� */
void show(struct WordCounter *pWordcounter);        /* �ܾ�� ����ȸ���� ����ϴ� �Լ� */
struct WordCounter* createWordCounter(char *word);  /* �� WordCounter ����ü�� ����� �Լ� */

/* �������� */
struct WordCounter *pStart = NULL;                  /* ����Ʈ�� ù��° ����ü�� ����Ű�� ������ */


void main()
{
  char text[MAX_TEXT_LENGTH];           /* �Է� �ؽ�Ʈ ����     */
  char buffer[MAX_WORD_LENGTH];         /* �ܾ �����ϴ� ���� */
  size_t i = 0;                         /* �ؽ�Ʈ�� �ε���      */
  int len = 0 ;                         /* �ܾ��� ����          */
  struct WordCounter *pCounter = NULL;  /* WordCounter�� ������ */      

  /* Ű���忡�� �ؽ�Ʈ�� ���� */
  printf("�ؽ�Ʈ�� �Է��ϼ���:\n");
  gets(text);

  /* �ؽ�Ʈ���� �ܾ ����  */  
  while(text[i] != '\0')
  {
    /* �����ڴ� �׳� �Ѿ */
    while(is_separator(text[i]))
      ++i;

    /* ���� ���ڿ��� ���̰ų� �ܾ��� ������ġ��. */
    /* ���ڿ� ���Ṯ�ڰ� �ƴϸ� ���ڸ� �����Ѵ�. */
    len = 0;              /* ���� ������ �ʱ�ȭ */
    while((!is_separator(text[i])) && (text[i] != '\0'))
      buffer[len++] = text[i++];
    if(len>0)               /* �ܾ ���ڰ� �ִ��� �˻� */
    {
      buffer[len] = '\0';   /* �ܾ��� ���� �ٴٶ����Ƿ� ���Ṯ�ڸ� ���� */
      addWord(buffer);      /* �ܾ ����Ʈ�� �߰� */
    }
  }

  /* �ܾ�� ����ȸ���� ��� */
  pCounter = pStart;
  while(pCounter != NULL)
  {
    show(pCounter);
    pCounter = pCounter->pNext;
  }
  printf("\n");

  /* �Ҵ��� �޸� ���� */
  pCounter = pStart;
  while(pCounter != NULL)
  {
    free(pCounter->word);        /* �ܾ� ���� �޸� ���� */
    pStart = pCounter;           /* ���� �ּ� ����        */
    pCounter = pCounter->pNext;  /* ���� ī���͸� �̵�    */
    free(pStart);                /* ���� �޸� ����      */     
  }
}

/* ���ڰ� ���й����̸� TRUE��, �ƴϸ� FALSE�� ��ȯ�ϴ� �Լ� */
int is_separator(char ch)
{
  /* ���й��ڴ� �����̽�, ��ǥ, �ݷ�, �����ݷ�, ����ǥ, ����ǥ, ����ǥ, ��ħǥ�� */
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
  /* �ܾ ������ �ʵ����� �������ķ� ����ϰ� �� ���� ����ȸ���� ��� */
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

  /* �ܾ ����Ʈ�� ������ ����ȸ���� 1 ������Ŵ */
  pCounter = pStart;
  while(pCounter != NULL)
  {
    if(strcmp(word, pCounter->word) == 0)
    {
      ++pCounter->word_count;
      return;
    }
    pLast = pCounter;            /* �ʿ��� ��� �������� �ּҸ� ����     */
    pCounter = pCounter->pNext;  /* �����͸� ����Ʈ�� ���� �����ͷ� �̵� */
  }
 
  /* ������� �Դٸ� ����Ʈ�� ���� �ܾ��̹Ƿ� �߰��� */
  pLast->pNext = createWordCounter(word);
}

/* ���� ������ �� WordCounter �ν��Ͻ��� ����� ��ȯ�� */
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
