/* ���α׷� 11.1 ����ü ���� */
#include <stdio.h>

void main() 
{
	/* ����ü ���� */
	struct horse
	{
		int age;
		int height;
		char name[20];
		char father[20];
		char mother[20];
	}; 

	struct horse My_first_horse; 								/* ����ü ���� ���� 	*/ 

	/* �Է� �����ͷ� ����ü ������ �ʱ�ȭ */ 	
	printf("���� �̸��� �Է��ϼ���: " ); 	
	scanf("%s", My_first_horse.name ); 							/* ���� �̸��� �Է� 	*/ 

	printf("%s�� ���̴�? ", My_first_horse.name ); 	
	scanf("%d", &My_first_horse.age ); 							/* ���� ���̸� �Է� 	*/ 

	printf("%s�� Ű��(cm)? ", My_first_horse.name ); 	
	scanf("%d", &My_first_horse.height ); 						/* ���� Ű�� �Է� 		*/ 

	printf("%s�� �ƺ���? ", My_first_horse.name );
	scanf("%s", My_first_horse.father ); 						/* �ƺ��� �̸��� �Է�	*/

	printf("%s�� ������? ", My_first_horse.name );
	scanf("%s", My_first_horse.mother ); 						/* ������ �̸��� �Է�	*/

	/* �Է¹��� ������ Ȯ�� */ 
	printf("\n%s�� ���̴� %d���̰� Ű�� %dcm�̸�,", 
					My_first_horse.name, My_first_horse.age, My_first_horse.height); 
	printf(" �ƺ��� %s�̰� ������ %s�Դϴ�.\n", My_first_horse.father,
					My_first_horse.mother ); 
} 
