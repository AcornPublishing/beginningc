/*�������� 4.1 ����ǥ ����� */
#include <stdio.h>

void main()
{
  int table_size = 0;                       /* ǥ�� ũ��      */
  int row = 0;                              /* �� ���� �ε��� */
  int col = 0;                              /* �� ���� �ε��� */
  printf("����ǥ�� ũ�⸦ �Է��ϼ��� (2~12): ");
  scanf("%d", &table_size);
  if(table_size>12)
  {
    printf("\nǥ�� ũ�Ⱑ 12�� ���� �� �����ϴ�. 12�� �����մϴ�.");
    table_size = 12;
  }
  else if(table_size<2)
  {
    printf("\nǥ�� ũ�Ⱑ 2���� ������ �ȵ˴ϴ�. 2�� �����մϴ�.");
    table_size = 2;
  }

  for(row = 0 ; row<=table_size ; row++)
  {
    printf("\n");                      /* ���ο� �� ���� */
    for(col = 0 ; col<=table_size ; col++)
    {
      if(row == 0)                     /* ù��° ���ΰ�?               */
      {                                /* �� - �� ���� ���            */
        if(col == 0)                   /* ù��° ���ΰ�?               */
          printf("    ");              /* �� - ���� ������� ����      */
        else
          printf("|%4d", col);         /* �ƴϿ� - ���� ���           */
      }
      else
      {                               /* ù��° ���� �ƴϸ� ���� ���  */
        if(col == 0)                  /* ù��° ���ΰ�?                */
          printf("%4d", row);         /* �� - �� ���� ���             */
        else
          printf("|%4d", row*col);    /* �ƴϿ� - �� ���              */
      }
    }
    if(row == 0 )                     /* ù��° ���� ����ϰ� ����     */
    {                                 /* ǥ ���м��� ���              */
      printf("\n");
      for(col=0 ; col<=table_size ; col++)
        printf("_____");
    }
  }
  printf("\n");
}

