/* ���α׷� 3.9 switch�� �ǽ� */ 
#include <stdio.h> 

void main() 
{ 
	char answer = 0; 						/* �Է¹��ڸ� ������ ���� */

	printf("Y�� N�� �Է��ϼ���: "); 
	scanf(" %c", &answer); 

	switch (answer) 
	{ 
		case 'y': case 'Y': 
			printf("\n�������� ��������� �亯�ϼ̱���."); 
			break; 

		case 'n': case 'N': 
			printf("\n�������� ��������� �亯�ϼ̱���."); 
			break; 

		default: 
			printf("\n���� ��������� �亯�ϼ̳���?"); 
			break; 
	}
}
