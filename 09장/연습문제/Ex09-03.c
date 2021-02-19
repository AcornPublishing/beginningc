/* �������� 9.3 ���ڿ��� �迭�� �ϳ��� ���ڿ��� ���� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 100                         /* �ִ� ���ڿ� ����                     */
#define BUFFER_SIZE 50                          /* �ʱ� �Է¹��� ũ��                   */

char* join_strings(char *strings[], int count); /* ���ڿ��� �迭�� �ϳ��� ���ڿ��� �����ϴ� �Լ� */
char* read_string();                            /* Ű���忡�� ���ڿ��� �д� �Լ�                 */

void main()
{
  char *pStrings[MAX_STRINGS];       /* ���ڿ��� ����Ű�� �������� �迭 */
  char *joined_strings = NULL;       /* ������ ���ڿ��� ����Ű�� ������ */
  int count = 0;                     /* �Է��� ���ڿ��� ����            */
  char answer = 'y';                 /* �� �Է��� �������� ����         */
  char terminator = '*';             /* ���ڿ� �Է� ���ῡ ���         */
  int i = 0;

  /* ���ڿ� �б� */
  while(count<MAX_STRINGS && tolower(answer)=='y')
  {
    printf("���ڿ��� �Է��ϼ���:\n");
    pStrings[count++] = read_string(terminator);

    printf("�� �Է��Ͻðڽ��ϱ�?(y/n) ");
    scanf(" %c", &answer);
    fflush(stdin);                     /* �б� ���� ��� */
  }

  joined_strings = join_strings(pStrings, count); 
  printf("\n�Է��Ͻ� ���ڿ��� �ϳ��� �����մϴ�:\n%s\n", joined_strings);

  free(joined_strings);                /* ������ ���ڿ��� �޸� ����   */
  for(i = 0 ; i<count ; i++)           /* �Է¹��� ���ڿ��� �޸� ���� */
    free(pStrings[i]);
}

/************************************************************************
 * ���ڿ��� �迭�� �����ϴ� �Լ�                                        *
 * �� �Լ��� �޸𸮸� �Ҵ��ϸ�, ȣ���ϴ� �ʿ��� �� �޸𸮸� �����ؾ� �� *
 ************************************************************************/
char* join_strings(char *strings[], int count)
{
  char* str = NULL;             /* ������ ���ڿ��� ������    */
  size_t total_length = 0;      /* ������ ���ڿ��� ��ü ���� */
  size_t length = 0;            /* ���ڿ��� ����             */
  int i = 0;                    /* ���� ī����               */

  /* ������ ���ڿ��� ��ü ���� ��� */
  for(i = 0 ; i<count ; i++)
  {
    total_length += strlen(strings[i]);
    if(strings[i][strlen(strings[i])-1] != '\n')
      ++total_length; /* �ٹٲ� ���ڵ� ���� */
  }
  ++total_length;     /* ���ڿ� ���Ṯ�ڵ� ���� */

  str = (char*)malloc(total_length);  /* ������ ���ڿ��� �޸� �Ҵ� */
  str[0] = '\0';                      /* ���ڿ��� ���               */

  /* ���ڿ� ���� */
  for(i = 0 ; i<count ; i++)
  {
    strcat(str, strings[i]);
    length = strlen(str);

    /* �ٹٲ޹��ڸ� �����ؾ� �ϴ��� �˻� */
    if(str[length-1] != '\n')
    {
      str[length] = '\n';             /* �ٹٲ� ���� ���� */
      str[length+1] = '\0';           /* ���ڿ� ���Ṯ�� ���� */
    }
  }
  return str;
}

/***************************************************************************
 * � ������ ���ڿ��� �о���̴� �Լ�.                                   *
 * ���ڿ��� ���ڷ� �Ѱ��� ���ڷ� ������.                                   *
 * �޸𸮸� �Ҵ��� ���ڿ��� �����ϸ�, ȣ���� ������ �ݵ�� �����ؾ� �Ѵ�.  *
 ***************************************************************************/
char* read_string(char terminator)
{
  char *buffer = NULL;            /* �Է¹��۸� ����Ű�� ������  */
  int buffersize = BUFFER_SIZE;   /* ���� ���� �뷮              */
  int length = 0;                 /* ���ڿ� ����                 */
  char *temp = NULL;              /* �ӽ� ���� ������            */
  int i = 0;                      /* ���� ī����                 */

  buffer = (char*)malloc(BUFFER_SIZE);  /* �ʱ� ���� */
  /* ���ڿ��� �� ���ھ� �о���� */
  for(;;)
  {
    /* ���ڿ� ���Ṯ�� �˻� */ 
    if((buffer[length] = getchar()) == terminator)
      break;
    else
      ++length;

    /* ���۰� ���� á���� �˻� */
    if(length == buffersize)
    {
      buffersize += BUFFER_SIZE;          /* ���� ũ�⸦ ���� */
      temp = (char*)malloc(buffersize);   /* �� ���� �Ҵ�     */

      /* ���� ���ۿ��� �� ���۷� ���� */
      for(i = 0 ; i<length ; i++)
        temp[i] = buffer[i];

      free(buffer);                       /* ���� ������ �޸� ���� */
      buffer = temp;                      /* �� ������ �ּ� ����     */
      temp = NULL;                        /* �ӽ� ������ �ʱ�ȭ      */
    }
  }
  buffer[length] = '\0';                  /* ���ڿ� ���Ṯ�� ����                    */
  temp = (char*)malloc(length+1);         /* ���ڿ� ���忡 �ʿ��� ��Ȯ�� �޸� �Ҵ� */
  strcpy(temp, buffer);                   /* ���ڿ� ����      */
  free(buffer);                           /* ���� �޸� ���� */
  return temp;
}
