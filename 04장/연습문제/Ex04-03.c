/*�������� 4.3 ��°����� ���ڿ� ���鹮���� �̸� ��� */
#include <stdio.h>
#include <ctype.h>

void main()
{
  int i = 0;                         /* ���� ī���� */
  char ch = 0;                       /* ���� �ڵ尪 */
  for(i = 0 ; i<128 ; i++)
  {
    ch = (char)i;
    if(ch%2==0)
      printf("\n");
    printf("  %4d",ch);
    if(isgraph(ch))
      printf("               %c",ch);
    else
      switch(ch)
    {
        case '\n':
           printf("      �ٹٲ޹���",ch);
           break;
        case ' ':
           printf("        �����̽�",ch);
           break;
        case '\t':
           printf("        ���� ��",ch);
           break;
        case '\v':
           printf("        ���� ��",ch);
           break;
         case '\f':
           printf("         ���ǵ�",ch);
           break;
        default:
           printf("                ");
           break;

    }

  }
  printf("\n");
}

