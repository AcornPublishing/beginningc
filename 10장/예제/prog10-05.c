/* ���α׷� 10.5 scanf()�� ���� �б� */ 
#include <stdio.h> 

void main() 
{ 
	char initial = ' '; 
	char name[80] = { 0 }; 
	char age[4] = { 0 }; 
	printf("�̸��� �̴ϼ��� �Է��ϼ���: "); 
	scanf("%c", &initial ); 
	printf("�̸��� �Է��ϼ���: "); 
	scanf("%s", name ); 

	if(initial != name[0])
		printf("\n%s��, �̴ϼ��� �߸� �Է��ϼ̳׿�.", name);
	else
		printf("\n�ȳ��ϼ��� %s��. �̴ϼ��� �ùٸ��� �Է��ϼ̳׿�!", name );
	printf("\n�̸��� ���̸� ��ǥ�� �����ؼ� �Է����ּ���:\n" );
	scanf("%[^,] , %[0123456789]", name, age );
	printf("\n����� �̸��� %s�̰� ���̴� %s���Դϴ�.\n", name, age );
} 
