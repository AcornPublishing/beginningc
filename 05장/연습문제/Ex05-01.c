/*�������� 5.1 5�� ���� ������ �� */
#include <stdio.h>

void main()
{
  double data[5];                      /* ������ ����             */
  double sum = 0.0;                    /* ������ ���� ������ ���� */
  int i = 0;                           /* ���� �ε���             */
  printf("5���� ���� ��ǥ�� ������ �Է��ϼ���:\n");
  for(i = 0 ; i<5 ; i++)
    scanf("%lf", &data[i]);

  printf("\n���� ���� �Է��ϼ̽��ϴ�:\n");
  for(i = 0 ; i<5 ; i++)
    printf("%10.2lf", data[i]);

  printf("\n");
  for(i = 0 ; i<5 ; i++)
  {
    sum += 1.0/data[i];                 /* ������ ���س���        */
    if(i>0)
      printf(" + ");
    printf("1/%.2lf", data[i]);
  }
  printf(" = %lf\n", sum);
}

