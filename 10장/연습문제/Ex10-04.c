/* �������� 10.5 ������ ���ڷ� ������ ���ڿ� �о���̱� */
#include <stdio.h>
#include <string.h>

#define MAX_SIZE     100
#define STRING_COUNT   5

char* getString(char *buffer, char end_char);

void main()
{
  char buffer[MAX_SIZE] = {0};
  int i = 0;
  for(i = 0 ; i<STRING_COUNT ; i++)
  {
    printf("�ݷ����� ������ ���ڿ��� �Է��ϼ���.\n");
    getString(buffer, ':');
    printf("�Է��� ���ڿ��� ������ �����ϴ�.\n%s\n", buffer);
  }
}

char* getString(char *buffer, char end_char)
{
  size_t i = 0;
  /* end_char�� �Է��� ������ ���ڿ� �б� */
  while((buffer[i++] = getchar()) != end_char)
    ;
  buffer[i-1] = '\0';  /* end_char�� ���Ṯ�ڷ� ��ü */
  return buffer;
}
