/* �������� 8.4 �ؽ�Ʈ�� �ܾ� ���� */
/* �� ���α׷��� isalpha() �Լ��� ��������Ƿ� �ѱ� ���ڿ����� */
/* ����� �������� �ʴ´�.                                     */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LENGTH_INCREMENT  20
#define MAX_WORD_LENGTH   30

int countwords(char str[]);                                    /* ���ڿ��� �ܾ� ������ ���� �Լ� */
int segment_string(char str[], char *words[]);                 /* ���ڿ��� ������ �Լ�           */
int count_letters(char str[]);                                 /* �ܾ��� ���� ������ ���� �Լ�   */


void main()
{
   char* pStr = NULL;             /* ���ڿ��� ������ �޸𸮸� ����Ű�� ������ */
   char* pTemp = NULL;            /* �ӽ� ������                              */
   char** words = NULL;           /* �ܾ� �迭�� ����Ű�� ������              */
   int length = 0;                /* ���� ���ڿ� ����                         */
   int max_length = 0;            /* ���� �ִ� ���ڿ� ����                    */
   int wordcount = 0;             /* ���ڿ��� �ִ� �ܾ��� ����                */
   int i = 0;
   int j = 0;

   /* ���ڿ� �б� */
   printf("���ڿ��� �Է��ϼ���:\n");
   do
   { /* �޸𸮰� �����ϸ� �� �Ҵ��� */
     if(length >= max_length)
     {
       max_length += LENGTH_INCREMENT;
       pTemp = (char*)malloc(max_length);
       if(pStr != NULL)  /* �̹� ���ڸ� �о���� ���¶�� */
       {                 /* �̸� �� �޸𸮿� ����         */
         for(i = 0 ; i<length ; i++)
           *(pTemp+i)= *(pStr+i);
         free(pStr);
       }
       pStr = pTemp;
       pTemp = NULL;
     }
   }while((*(pStr+length++) = getchar()) != '\n');
   *(pStr+(--length)) = '\0';     /* ���ڿ� ���Ṯ�� ���� */

   wordcount = countwords(pStr);  /* ���ڰ��� ����        */

   /* �ܾ ������ �޸� �Ҵ� */
   words = (char**)malloc(wordcount*sizeof(char*));
   for(i = 0 ; i<wordcount ; i++)
     *(words+i) = (char*)malloc(MAX_WORD_LENGTH);

   segment_string(pStr, words);   /* ���ڿ��� �ܾ�� ���� */

   /* �ܾ ���� ������ ���� */
   for(i = 0 ; i<wordcount-1 ; i++)
     for(j = i ; j<wordcount ; j++)
       if(count_letters(*(words+i))>count_letters(*(words+j)))
       {
         pTemp = *(words+i);
         *(words+i) = *(words+j);
         *(words+j) = pTemp;
       }
   /* �ܾ ����ϰ� �޸� ���� */
   printf("���ڿ��� �ִ� �ܾ ���� ������ ����մϴ�:\n");
   for(i = 0 ; i<wordcount ; i++)
   {
     printf("%s\n",*(words+i));
     free(*(words+i));
   }
   free(words);      /* �������� �޸� ���� */

}

/* ���ڿ��� �ִ� �ܾ� ������ ���� �Լ� */
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

/* ���ڿ��� �ܾ�� ������ �� ������ ��ȯ�ϴ� �Լ�  */
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

/* �ܾ �ִ� ���� ������ ���� �Լ� */
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