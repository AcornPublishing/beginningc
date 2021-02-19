/* �������� 12.1 ���Ͽ� ���ڿ� ���� */
/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define BUFFER_SIZE 50

/* �Լ����� */
void read_string();

/* �������� */
FILE *pFile = NULL;                   /* ���� ������        */
char *filename = "C:\\myfile.txt";    /* ����� ������ �̸� */
char *buffer = NULL;
int buffer_size = BUFFER_SIZE;


void main()
{
  char answer = 'n';
  size_t str_length = 0;

  buffer = (char*)malloc(buffer_size);    /* �ʱ� ���۸� ����   */

  pFile = fopen(filename, "w");           /* ����� ������ ���� */
  if(pFile == NULL)
  {
    printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
    abort();
  }

  do
  {
    /* Ű���忡�� ���ڿ��� ���� */
    printf("���ڿ��� �Է��ϼ���:\n");
    read_string();                                  /* ���ۿ� ���ڿ� ����        */
    str_length = strlen(buffer);                    /* ���ڿ� ���̸� �˾Ƴ�      */
    fwrite(&str_length, sizeof(size_t), 1, pFile);  /* ���Ͽ� ���ڿ� ���̸� ��� */
    fwrite(buffer, str_length, 1, pFile);           /* ���ڿ��� ���Ͽ� ���      */

    printf("�� �Է��Ͻðڽ��ϱ�(y/n)? ");
    scanf(" %c", &answer);
    fflush(stdin);                                   /* �Է¹��۸� ��� �ٹٲ޹��ڸ� ���� */
  }while(tolower(answer) == 'y');

  fclose(pFile);                                    /* ���� �ݱ� */ 
  printf("\n���� ����� �������ϴ�.\n");
  if(buffer != NULL)
    free(buffer);
 }

/* ���� ������ ���ڿ��� Ű���忡�� �д� �Լ�              */
/* ���ڿ��� ���� �뷮�� �ʰ��ϸ� �ڵ����� ���۸� ������Ŵ */
void read_string()
{
  char *temp = NULL;                      /* �� ���� �ּҸ� ������ �� ����ϴ� ���� */
  int position = 0;                       /* ������ ���� �� ��ġ */

  while((buffer[position++] = getchar()) != '\n')
    if(position >= buffer_size-1)         /* ���۰� ���� á�°�? */
    { /* ������ ũ�⸦ ������Ŵ */
      buffer_size += BUFFER_SIZE;         /* �� ���� ũ��   */
      temp = (char*)malloc(buffer_size);  /* �� ���۸� ���� */
      buffer[position] = '\0';            
      strcpy(temp, buffer);               /* ���� ���۸� �� ���ۿ� ���� */
      free(buffer);                       /* ���� ���� ����             */
      buffer = temp;                      /* �� ������ �ּ� ����        */
      temp = NULL;
    }
  buffer[position-1] = '\0';              /* �ٹٲ� ���ڸ� ���Ṯ�ڷ� �ٲ� */
}