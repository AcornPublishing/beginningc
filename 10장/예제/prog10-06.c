/* ���α׷� 10.6 gets()�� �̿��� ���ڿ� �б� */ 
#include <stdio.h> 

void main() 
{ 
	char initial[2] = {0}; 
	char name[80] = {0}; 

	printf("�̴ϼ��� �Է��ϼ���: ");
	gets(initial);
	printf("�̸��� �Է��ϼ���: " );
	gets(name);
	if(initial[0] != name[0])
		printf("\n%s��, �̴ϼ��� �߸� �Է��ϼ̳׿�.\n", name); 
	else 
		printf("\n�ȳ��ϼ��� %s��. �̴ϼ��� �ùٸ��� �Է��ϼ̳׿�!\n", name); 
} 
