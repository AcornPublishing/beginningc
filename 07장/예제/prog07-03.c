/* ���α׷� 7.3 scanf�� ���� ������ ���� */ 
#include <stdio.h> 

void main() 
{ 
	int value = 0; 
	int *pvalue = NULL; 

	pvalue = &value; 									/* �����Ͱ� value�� �����ϵ��� ����	*/ 

	printf ("������ �Է��ϼ���: "); 
	scanf(" %d", pvalue); 								/* �����͸� ���� ���� �о����		*/ 

	printf("\n%d�� �Է��ϼ̽��ϴ�.\n", value); 			/* �Է¹��� ���� ��� 				*/ 
} 
