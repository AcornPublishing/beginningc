/* �������� 9.4 �ϳ� �̻��� �Ǽ��� �ϳ��� ���ڿ��� ��ȯ */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char* to_string(int count, double first, ...);  /* �Ǽ��� ��ǥ�� ���е� ���ڿ��� ��ȯ�ϴ� �Լ� */
char* fp_to_str(double x);                      /* x�� ���ڿ��� ��ȯ�ϴ� �Լ�                  */
char* int_to_str(int n);                        /* n�� ���ڿ��� ��ȯ�ϴ� �Լ�                  */ 

void main()
{
  char *str = NULL;                  /* �Ǽ� ���ڿ��� ����Ű�� ������ */
  double values[] = { 1.245, -3.5, 6.758, 33.399, -1.02 };

  str = to_string(sizeof values/sizeof(double), values[0], values[1], values[2], values[3], values[4]);

  printf("��ȯ�� ���ڿ��� ������ �����ϴ�.\n%s\n", str);
 
  free(str);                         /* ���ڿ��� �޸� ���� */
}

/****************************************************************
 * �ϳ� �̻��� �Ǽ��� �޾Ƶ鿩 ��ǥ�� ���е� ���ڿ��� ��ȯ�ϴ�  *
 * �Լ�. �� �Լ��� �޸𸮸� �Ҵ��ϸ�, ȣ���ϴ� �ʿ��� �����ؾ�  *
 * �Ѵ�.                                                        *
 ****************************************************************/
char* to_string(int count, double first, ...)
{
  va_list parg = NULL;          /* �������� ���� ���ڸ� ����Ű�� ������ */
  char* str = NULL;             /* ���յ� ���ڿ��� ����Ű�� ������      */
  char *temp = NULL;            /* �ӽ� ���ڿ� ������                   */
  char *value_str = 0;          /* �� ���ڿ��� ����Ű�� ������          */
  const char *separator = ",";  /* �� ���ڿ��� ������                   */
  size_t separator_length = 0;  /* ������ ���ڿ��� ����                 */
  size_t length = 0;            /* ���ڿ��� ����                        */
  int i = 0;                    /* ���� ī����                          */

  separator_length = strlen(separator);

  va_start(parg,first);         /* ���� ������ �ʱ�ȭ */

  str = fp_to_str(first);       /* ù��° �� ��ȯ     */

  /* ������ ���ڸ� �޾Ƶ鿩 ���ڿ��� ��ȯ�ϰ� ���� */
  while(--count>0)
  {
    value_str = fp_to_str(va_arg(parg, double));    /* ���� ���ڸ� ���� */
    length = strlen(str) + strlen(value_str) + separator_length +1;
    temp = (char*)malloc(length); /* ���ڿ��� ������ �޸� �Ҵ� */
    strcpy(temp, str);            /* ���� ���ڿ� ����            */
    free(str);                    /* ���� �޸� ����            */
    str = temp;                   /* �� �޸� �ּ� ����         */
    temp = NULL;                  /* ������ �ʱ�ȭ               */
    strcat(str,separator);        /* ������ ����                 */
    strcat(str,value_str);        /* �� ���ڿ� ����              */
    free(value_str);              /* �� ���ڿ��� �޸� ����     */
  }
  va_end(parg);                   /* parg ������ ����            */
  return str;
}

/***************************************************************************
 * �Ǽ� ���ڸ� ���ڿ��� ��ȯ�ϴ� �Լ�                                      *
 * ������� �Ҽ��� ���� 2�ڸ�������                                        *
 * �޸𸮸� �Ҵ��� ���ڿ��� �����ϸ�, ȣ���ϴ� �ʿ��� �����ؾ� ��          *
 ***************************************************************************/
char* fp_to_str(double x)
{
  char *str = NULL;                 /* ���ڿ��� ����Ű�� ������        */
  char *integral = NULL;            /* �Ǽ��� ���ڿ��� ����Ű�� ������ */
  char *fraction = NULL;            /* �Ҽ��� ���ڿ��� ����Ű�� ������ */
  size_t length = 0;                /* �ʿ��� ��ü ���ڿ� ����         */

  integral = int_to_str((int)x);    /* ��ȣ�� ������ �����θ� ���ڿ��� ��ȯ */

  /* x�� ����� �ٲ� */
  if(x<0)
    x = -x;
  /* �Ҽ��θ� ���ڿ��� ��ȯ */
  fraction = int_to_str((int)(100.0*(x+0.005-(int)x)));

  length = strlen(integral)+strlen(fraction)+2;  /* �Ҽ����� ���Ṯ�ڸ� ������ ��ü ���� */

  /* �Ҽ��δ� 2���� ���ڷ� �̷����� �� */
  if(strlen(fraction)<2)
    ++length;

  str = (char*)malloc(length);        /* ��ü �Ǽ��� �޸� �Ҵ� */
  strcpy(str, integral);              /* ������ ����             */
  strcat(str, ".");                   /* �Ҽ��� ����             */

  if(strlen(fraction)<2)              /* �Ҽ��� ���ڰ� 2�� �̸��� ��� */
    strcat(str,"0");                  /* 0�� ����                      */

  strcat(str, fraction);              /* �Ҽ��� ���� */

  /* �޸� ���� */
  free(integral);
  free(fraction);

  return str;
}

/***************************************************************************
 * ���� ���ڸ� ���ڿ��� ��ȯ�ϴ� �Լ�.                                     *
 * �޸𸮸� �Ҵ��� ���ڿ��� �����ϸ�, ȣ���ϴ� �ʿ��� �����ؾ� ��          *
 ***************************************************************************/
char* int_to_str(int n)
{
  char *str = NULL;                    /* ���ڿ��� ����Ű�� ������ */
  int length = 1;                      /* ���ڿ��� �ִ� ���� ����(�ּ� 1��) */
  int temp = 0;
  int sign = 1;                        /* n�� ��ȣ�� ǥ�� */

  /* �������� Ȯ�� */
  if(n<0)
  {
    sign = -1;
    n = -n;
    ++length;                          /* ���̳ʽ� ��ȣ�� �� ���� */
  }

  /* length�� n�� ���� ������ŭ ������Ŵ */
  temp = n;
  do
  {
    ++length;
  }
  while((temp /= 10)>0);

  str = (char*)malloc(length);        /* �ʿ��� ���� �Ҵ�   */

  if(sign<0)                          /* �����̸�           */
    str[0] = '-';                     /* ���̳ʽ� ��ȣ ���� */

  str[--length] = '\0';               /* ���Ṯ�� ����      */

  /* ���ڸ� ���ʴ�� �߰� */
  do
  {
    str[--length] = '0'+n%10;
  }while((n /= 10) > 0);

  return str;
}
