/* �������� 4.4 ���� �׸��� */
#include <stdio.h>

void main()
{
  int width = 0;                       /* ������ ��       */
  int height = 0;                      /* ������ ����     */
  int row = 0;                         /* �� ���� �ε���  */
  int col = 0;                         /* �� ���� �ε���  */
  printf("������ ���� ���̸� �����̽��� ������ �Է��ϼ���: ");
  scanf("%d", &width);
  scanf("%d", &height);

  for(row = 0 ; row<height ; row++)
  {
    printf("\n");                      /* �� �� ����      */
    for(col = 0 ; col<width ; col++)
    {
      if(row == 0||row==height-1)      /* ù��°�� ������ ���ΰ�? */
      {
          printf("*");                 /* �׷��ٸ� ��� ��ǥ ��� */
          continue;
      }
      /* ù��°�� ������ ������ ��ǥ, �� �ܿ��� �����̽� ��� */
      printf("%c", ((col==0 || col==width-1) ? '*' :' '));   
    }
  }
  printf("\n");
}

