/*�������� 5.3 ��ȭ ���� ������ ó���ϱ� */
#include <stdio.h>

void main()
{
  float amounts[5];                     /* ������ ���� */
  long dollars[5];
  long cents[5];
  int i = 0;                            /* ���� �ε��� */
  printf("5���� �ݾ��� �����̽��� ������ �Է��ϼ���:\n");
  for(i = 0 ; i<5 ; i++)
    scanf("%f", &amounts[i]);

  for(i = 0 ; i<5 ; i++)
  {
    dollars[i] = (long)amounts[i];
    cents[i] = (long)(100.0*(amounts[i]-dollars[i]));
  }

  printf("\n");
  for(i = 0 ; i<5 ; i++)
  {
    printf("  $%d.%02d", dollars[i], cents[i]);
  }
  printf("\n");
}

