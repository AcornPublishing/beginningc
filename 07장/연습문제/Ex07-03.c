/* �������� 7.3 ���ڿ����� �����̽��� ������ ����� */
#include <stdio.h>
#include <ctype.h>

#define BUFFER_LEN 500             /* �Է¹����� ���� */

void main()
{
   char buffer[BUFFER_LEN];        /* �Է¹���                   */
   char *pbuffer1 = buffer;        /* ������ġ�� ����Ű�� ������ */
   char *pbuffer2 = buffer;        /* ������ġ�� ����Ű�� ������ */

   /* ���ڿ� �б� */
   printf("���ڿ��� %d���� ���Ϸ� �Է��ϼ���:\n", BUFFER_LEN);
   while((*pbuffer1++ = getchar()) != '\n');
   *pbuffer1 = '\0';               /* ���ڿ� ���Ṯ�� ����       */
   pbuffer1 = buffer;              /* �����͸� ������ġ�� �ʱ�ȭ */
   while(*pbuffer1 != '\0')        /* ���ڿ� ������ �ݺ�         */
   {
     if(ispunct(*pbuffer1) || isspace(*pbuffer1))
     {                             /* �����̽��� �������� ��� */
       ++pbuffer1;                 /* ���� ���ڷ� �Ѿ       */
       continue;
     }
     else
       *pbuffer2++ = *pbuffer1++;  /* �׷��� ������ ���� ����  */
   }
   *pbuffer2 = '\0';               /* ���ڿ� ���Ṯ�� ����     */
   printf("\n�����̽��� �������� ������ ������ ������ �����ϴ�:\n%s\n", buffer);
}

