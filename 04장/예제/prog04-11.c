/* ���α׷� 4.11 ���� ������ */ 
#include <stdio.h> 
void main() 
{ 
	int number = 0; 									/* ������ ������ ���� ����	*/ 
	int rebmun = 0; 									/* ������ ������ ��� 		*/ 
	int temp = 0; 										/* �ӽ������ 				*/ 

	/* ���ڸ� ������ ���� ���� �Է� */
	printf("\n���� ������ �ϳ� �Է��ϼ���: ");
	scanf("%d", &number);

	temp = number; 										/* �ӽ�����ҿ� ���� 		*/ 

	/* temp�� ����� ���� ������ */
	do
	{
		rebmun = 10*rebmun + temp % 10; 				/* �� ������ ���ڸ� �߰� 	*/ 
		temp = temp/10; 								/* �� ������ ���ڸ� ���� 	*/ 
	} while (temp); 									/* temp>0�̸� ������ ���	*/ 

	printf ("\n\'���� ���� %d\'(��)�� �������� \'%d ���� �Ǿ�\'.\n", number, rebmun ); 
} 
