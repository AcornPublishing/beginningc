/* �������� 6.1 ������ �ܾ�� */
#include <stdio.h>
#include <string.h>

void main()
{
  char *unit_words[] = {"��", "��","��","��","��","��","��","ĥ","��","��"};
  char hundred[] = "��";
  char ten[] = "��";
  char value_str[50] = "";
  int value = 0;                       /* ��ȯ�� ����        */
  int digits[] = {0,0,0};              /* �Է¹��� ���� ���� */
  int i = 0;

  printf("1000���� ���� ������ �Է��ϼ���: ");
  scanf("%d",&value);
  if(value>=1000)
    value =999;
  else if(value<1)
    value = 1;

  while(value>0)
  {
    digits[i++] = value%10;
    value /= 10;
  }

  if(digits[2]>0)
  {
    if(digits[2]==1)
	  strcat(value_str, hundred);
	else
	  strcat(strcat(value_str,unit_words[digits[2]]), hundred);
  }

  if(digits[1]>0)
  {
	strcat(value_str, " ");
	if(digits[1]==1)
	  strcat(value_str, ten);
	else
	  strcat(strcat(value_str, unit_words[digits[1]]),ten);
  }

  if(digits[0]>0)
	strcat(strcat(value_str, " "), unit_words[digits[0]]);

  printf("�Է��Ͻ� ���� %s�Դϴ�.", value_str);
}

