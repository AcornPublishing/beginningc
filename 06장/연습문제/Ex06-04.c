/* �������� 6.4 ȸ�� �˻� */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
  char sentence[500];             /* �˻��� ����                 */
  char sentence_chars[500];       /* �������� ��ǥ�� ������ ���� */
  size_t i = 0;                   /* ���� ��ġ�� �ε���          */
  size_t j = 0;                   /* ���� ��ġ�� �ε���          */
  size_t length = 0;              /* ���ڿ��� ����               */

  printf("�˻��� ������ �Է��ϼ���:\n");
  gets(sentence);

  /* ���ĺ����� �ҹ��ڷ� ���� */
  for (i = 0 ; i< strlen(sentence) ; i++)
    if(isalpha(sentence[i]))
      sentence_chars[j++] = tolower(sentence[i]);
  sentence_chars[j] = '\0';        /* ���ڿ� ���Ṯ�� ���� */

  length = strlen(sentence_chars); /* ���ڿ� ���� ����     */ 

  /* ���ڿ����� ��Ī ��ġ�� �ִ� �� ���ڸ� ��� �� */
  /* �ϳ��� �ٸ� �� ������ ȸ���� �ƴ�             */
  for(i = 0 ; i<length/2 ; i++)
    if(sentence_chars[i] != sentence_chars[length-1-i])
    {
      printf("\n�Է��Ͻ� ������ ȸ���� �ƴմϴ�.\n");
      exit(0);
    }
    /* ������� ���� ��� ���ڰ� ��� ��ġ�� */
    printf("\n�Է��Ͻ� ������ ȸ���Դϴ�.\n");
}

