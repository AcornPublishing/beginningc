/* �������� 3.1 �µ���ȯ */
#include <stdio.h>

void main()
{
  int choice = 0;
  double temperature = 0.0;
  printf("�� ���α׷��� ������ ���� ���� �մϴ�:\n"
         "1. ������ ȭ���� ��ȯ\n"
         "2. ȭ���� ������ ��ȯ\n"
         "��ȣ�� �����ϼ���(1 �Ǵ� 2): ");
  scanf("%d", &choice);
 
  printf("�µ��� %s ������ �Է��ϼ���: ",
                          (choice == 1 ?  "����" : "ȭ��"));
  scanf("%lf", &temperature);

  if(choice == 1)
    printf("��ȯ�� ���� ȭ�� %.2lf���Դϴ�.\n", temperature*9.0/5.0+32.0);
  else
    printf("��ȯ�� ���� ���� %.2lf���Դϴ�.\n", (temperature-32.0)*5.0/9.0);
}
