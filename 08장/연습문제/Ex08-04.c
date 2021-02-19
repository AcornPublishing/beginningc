/* 연습문제 8.4 텍스트의 단어 정렬 */
/* 이 프로그램은 isalpha() 함수를 사용했으므로 한글 문자열에는 */
/* 제대로 동작하지 않는다.                                     */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LENGTH_INCREMENT  20
#define MAX_WORD_LENGTH   30

int countwords(char str[]);                                    /* 문자열의 단어 개수를 세는 함수 */
int segment_string(char str[], char *words[]);                 /* 문자열을 나누는 함수           */
int count_letters(char str[]);                                 /* 단어의 문자 개수를 세는 함수   */


void main()
{
   char* pStr = NULL;             /* 문자열을 저장할 메모리를 가리키는 포인터 */
   char* pTemp = NULL;            /* 임시 포인터                              */
   char** words = NULL;           /* 단어 배열을 가리키는 포인터              */
   int length = 0;                /* 현재 문자열 길이                         */
   int max_length = 0;            /* 현재 최대 문자열 길이                    */
   int wordcount = 0;             /* 문자열에 있는 단어의 개수                */
   int i = 0;
   int j = 0;

   /* 문자열 읽기 */
   printf("문자열을 입력하세요:\n");
   do
   { /* 메모리가 부족하면 더 할당함 */
     if(length >= max_length)
     {
       max_length += LENGTH_INCREMENT;
       pTemp = (char*)malloc(max_length);
       if(pStr != NULL)  /* 이미 문자를 읽어놓은 상태라면 */
       {                 /* 이를 새 메모리에 저장         */
         for(i = 0 ; i<length ; i++)
           *(pTemp+i)= *(pStr+i);
         free(pStr);
       }
       pStr = pTemp;
       pTemp = NULL;
     }
   }while((*(pStr+length++) = getchar()) != '\n');
   *(pStr+(--length)) = '\0';     /* 문자열 종료문자 연결 */

   wordcount = countwords(pStr);  /* 문자개수 세기        */

   /* 단어를 저장할 메모리 할당 */
   words = (char**)malloc(wordcount*sizeof(char*));
   for(i = 0 ; i<wordcount ; i++)
     *(words+i) = (char*)malloc(MAX_WORD_LENGTH);

   segment_string(pStr, words);   /* 문자열을 단어로 분할 */

   /* 단어를 길이 순으로 정렬 */
   for(i = 0 ; i<wordcount-1 ; i++)
     for(j = i ; j<wordcount ; j++)
       if(count_letters(*(words+i))>count_letters(*(words+j)))
       {
         pTemp = *(words+i);
         *(words+i) = *(words+j);
         *(words+j) = pTemp;
       }
   /* 단어를 출력하고 메모리 해제 */
   printf("문자열에 있는 단어를 길이 순으로 출력합니다:\n");
   for(i = 0 ; i<wordcount ; i++)
   {
     printf("%s\n",*(words+i));
     free(*(words+i));
   }
   free(words);      /* 포인터의 메모리 해제 */

}

/* 문자열에 있는 단어 개수를 세는 함수 */
int countwords(char str[])
{
  int count = 0;
  int i = 0;
  while(str[i] != '\0')
  {
    if(!isalpha(str[i]))
    {
      i++;
      continue;
    }
    ++count;
    while(isalpha(str[++i]))
      ;
  }
  return count;
}

/* 문자열을 단어로 나누고 그 개수를 반환하는 함수  */
int segment_string(char str[], char *words[])
{
  int count = 0;
  int i = 0;
  int j = 0;
  while(str[i] != '\0')
  {
    if(!isalpha(str[i]))
    {
      i++;
      continue;
    }
    j = 0;
    while(isalpha(str[i]))
    {
      words[count][j++] = str[i++];
    }
    words[count++][j] = '\0';
  }
 return count;
}

/* 단어에 있는 문자 개수를 세는 함수 */
int count_letters(char str[])
{
  int count = 0;
  int i = 0;
  while(str[i] != '\0')
  {
    if(isalpha(str[i++]))
      ++count;
  }
  return count;
}