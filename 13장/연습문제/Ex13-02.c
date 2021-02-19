/* �������� 13.2 �ð��� ���ڿ��� */
#include <stdio.h>
#include <time.h>
#include <string.h>
#define TIME_24   1
#define TIME_12   0

char *get_time_string(int mode24);     /* �ð��� 12/24�ð� ������ ���ڿ��� ��ȯ�ϴ� �Լ� */
char *int_to_str(unsigned int n);      /* 1�� �Ǵ� 2���� ���ڷ� �̷��� ������ ���ڿ��� ��ȯ�ϴ� �Լ� */
void main()
{
  printf("\n24�ð����� ��Ÿ�� �ð� : %12s", get_time_string(TIME_24));
  printf("\n12�ð����� ��Ÿ�� �ð� : %12s\n", get_time_string(TIME_12));
}

/* �ð��� 12/24�ð����� ��Ÿ�� ���ڿ��� ��ȯ�ϴ� �Լ� */
/* 
   �ð��� 12/24�ð����� ǥ���� ���� ���ڿ��� �ּҸ� ��ȯ�Ѵ�.
   �Լ��� ȣ���� ������ ���� ���ڿ��� ������ ����� �ȴ�.
   24�ð����� ǥ���� ���� ���ڷ� 1��, 12�ð����� 0�� �ž� �Ѵ�.
*/
char* get_time_string(int mode24) 
{
  static char time_str[12] = {0};   /* �ð��� ������ ���ڿ� */
  struct tm *now = NULL;
  int hour = 0;
  time_t time_value = 0;

  time_value = time(NULL);          /* �ð��� ���                */
  now = localtime(&time_value);     /* �ð�/��¥ ����ü ���      */
  hour = now->tm_hour;              /* �� �� ����                 */
  if(!mode24 && hour>12)            /* 12�ð����� ��� �� �� ���� */
    hour -= 12;

  strcpy(time_str, int_to_str(hour));
  strcat(time_str, ":");
  strcat(time_str, int_to_str(now->tm_min));
  strcat(time_str, ":");
  strcat(time_str, int_to_str(now->tm_sec));
  if(!mode24)
    strcat(time_str, now->tm_hour>24 ? " am" : " pm");
  return time_str;
}

/* 1�� �Ǵ� 2���� ��ȣ���� ������ ���̰� 2�� ���ڿ��� ��ȯ�ϴ� �Լ� */
/* 
   �� �Լ��� ��ȯ�� ������ ���ڷ� �Ѱܹ���.
   ���� ���ڿ��� �ּҸ� ��ȯ��.
   �ռ� ȣ���� ���� ���ڿ��� ���� ȣ�⶧ ����� ��.
*/
char *int_to_str(unsigned int n)
{
  static char str[3];      /* ���� ���ڿ� ���·� ������ ���� */
  str[1] = '0'+n%10;       /* �ι�° ���ڸ� �˾Ƴ�           */
  n /= 10;
  str[0] = '0'+n%10;       /* ù��° ���ڸ� �˾Ƴ�           */
  str[2] = '\0';           /* ���Ṯ�� ����                  */

  return str;
}
