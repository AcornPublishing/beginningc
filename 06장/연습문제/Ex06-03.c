/* �������� 6.3 ���Ƿ� ��µǴ� ������ ��� */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
  char thoughts[][50] = {"������ ���� ��� �㸻�� �㰡 ��´�",
                         "�� �Ϳ� �� �б�",
                         "�����嵵 �µ�� ����",
                         "����� ������ �谡 ������ �ö󰣴�",
                         "������ ������ �̳��� ���� �ʴ´�",
                         "���� �þ�� ���̰� ���� �ؾ� ���̴�"};
 
  srand((unsigned int)time(NULL));

  printf("������ ���\n\n%s\n", thoughts[rand()%(sizeof thoughts/sizeof thoughts[0])]);
}

