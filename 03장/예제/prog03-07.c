/* ���α׷� 3.7 ������ ���Ի�� ���� ���� */
#include <stdio.h>

void main() 
{ 
	int age = 0; 											/* �������� ����		*/ 
	int college = 0; 										/* ������ �б��� �ڵ�	*/ 
	int subject = 0; 										/* ���������� �ڵ�		*/ 
	int interview = 0; 										/* �հ��� 1, ���հ��� 0 */ 

	/* �������� �����͸� �Է¹��� */
	printf("\n��� ������? 1.�Ϲ���, 2.����, 3.��Ÿ: ");
	scanf("%d",&college);
	printf("\n���� ������? 1.ȭ��, 2.������, 3.��Ÿ: ");
	scanf("%d", &subject);
	printf("\n�������� ���̴�? ");
	scanf("%d",&age);

	/* ������ ���� */ 
	if((age>25 && subject==1) && (college==3 || college==1)) 
		interview = 1; 
	if(college==2 &&subject ==1) 
		interview = 1; 
	if(college==1 && subject==2 && !(age>28)) 
		interview = 1; 
	if(college==2 && (subject==2 || subject==3) && age>25) 
		interview = 1; 

	/* ������� ���߿��� ��� */
	if(interview)
 
		printf("\n\n�����ɻ� �հ� - ���� �����");
	else
		printf("\n\n�����ɻ� ���հ�");
}
