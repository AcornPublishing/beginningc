/*�������� 4.2 ��°����� ���� ��� */
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
    printf("  %4d    %c",ch,(isgraph(ch) ? ch : ' '));
  }
  printf("\n");
}

