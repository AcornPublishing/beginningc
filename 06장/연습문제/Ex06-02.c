/* �������� 6.2 ��ǥ�� ���е� �ܾ��� �м� */
#include <stdio.h>
#include <string.h>

void main()
{
  char list[5000];         /* ��ǥ�� ������ �ܾ� ��� ����   */
  char words[500][20];     /* 20���� ������ �ܾ 500������ ������ �� �ִ� �迭 */
  const char comma = ',';
  const char space = ' ';
  int word_count = 0;      /* �ܾ��� ����      */
  int word_length = 0;     /* ���� �ܾ��� ���� */
  int index = 0;           /* ���� ��ġ        */

  printf("�ܾ ��ǥ�� ������ �Է��ϼ���:\n");
  gets(list);              /* �ܾ� ��� ���� */

  /* ��Ͽ��� �ܾ� ã�� */
  while(list[index] != '\0')
  {
    /* �����̽��� ��ǥ�� ���� */
    while(list[index] == space || list[index] == comma)
      ++index;

    /* �����̽�, ��ǥ, \0�� �ƴ� ���ڸ� ���� */
    while(list[index] != space && list[index] != comma && list[index] != '\0')
     words[word_count][word_length++] = list[index++];

    words[word_count++][word_length] = '\0';    /* ���Ṯ�� ���� */
    word_length = 0;                            /* ���� �ܾ ���� �ʱ�ȭ */
  }

  /* ã�� �ܾ ��� ��� */
  printf("\n�Է��Ͻ� �ܾ�� ������ �����ϴ�:\n");
  for(index = 0 ; index<word_count ; index++)
    printf("%s\n",words[index]);
}

