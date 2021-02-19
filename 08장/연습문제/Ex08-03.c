/* �������� 8.3 ������ �־��� ���� ���� ���ڿ��� ��ȯ�ϴ� �Լ� */
#include <stdio.h>

/* ������ ������ ���� ���ڿ��� ��ȯ�ϴ� �Լ� */
/* ���� �ʹ� ������ �ּ� ���� �����Ѵ�.      */
char* itoa(int n, char str[], int width)
{
  int i = 0;               /* ���� ī����        */
  int j = 0;               /* ���� ī����        */
  int negative = 0;        /* ���� �������� Ȯ�� */
  int length = 0;          /* ���ڿ��� ����      */
  int temp = 0;            /* �ӽ� �����        */
 
  if(negative = (n<0))     /* ���� �����ΰ�?   */
    n = -n;                /* ���� ������ �ٲ� */

  /* �������� ���ڸ� ����� �� */
  do
  {
    str[i++] = '0'+n%10;    /* �� ������ ���� �����   */
    n /= 10;                /* ���� ����               */              
  }while(n>0);              /* ���ڰ� ���� ������ �ݺ� */

  if(negative)              /* ���� �����̸�        */
    str[i++] = '-';         /* ���̳ʽ� ��ȣ�� ���� */
  str[i] = '\0';            /* ���ڿ� ���Ṯ�� ���� */
  length = i;               /* ���̸� ����          */

  /* ���ڿ��� �ݴ�� ������                 */
  /* ������ ���ڰ� �� ������, �ι�° ���ڰ� */
  /* �ڿ��� �ι�° ���ڷ� �̵��ϴ� ��       */
  for(i = 0 ; i<length/2 ;i++)
  {
    temp = str[i];
    str[i] = str[length-i-1];
    str[length-i-1] = temp;
  }

  /* ���ڿ��� ���������� �ű�� �� ĭ�� ���� */
  if(width>length)
  {
    for(i=length, j = width ; i>= 0 ; i--, j--)
      str[j] = str[i];
    for(i = 0 ; i<width-length ; i++)
      str[i] = ' ';
  }
  return str;                /* ���ڿ� ��ȯ */
}


void main()
{
   char str[15];              /* ������ ��ȯ�� ���ڿ��� ���� */
   long testdata[] = { 30L, -98L, 0L, -1L, 999L, -12345L};  
   int i = 0;                /* ���� ���� ���� */

   for (i = 0 ; i< sizeof testdata/sizeof(long) ; i++)
     printf("�Է��� ������ %10d�̰�, ��ȯ�� ���ڿ��� %s�Դϴ�.\n", testdata[i], itoa(testdata[i],str, 14));
}

