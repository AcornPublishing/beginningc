/* ���α׷� 11.3 ����ü�� ����Ű�� ������ */ 
 
#include <stdio.h> 	
#include <ctype.h> 	
#include <stdlib.h> 													/* malloc() �Լ��� ����� ���� ���� */ 

void main() 	
{ 	
	struct horse 														/* ����ü ���� 	*/ 
	{ 	
		int age; 	
		int height; 	
		char name[20]; 	
		char father[20]; 	
		char mother[20]; 	
	}; 	

	struct horse *phorse[50]; 											/* ����ü �������� �迭 ���� 	*/ 
	int hcount = 0; 													/* ���� ������ 					*/ 
	int i = 0; 															/* ���� ī���� 					*/ 
	char test = '\0'; 													/* �Է��� �������� �˻��ϴ� ��	*/ 
	for(hcount = 0; hcount < 50 ; hcount++ )
	{
		printf("\n%s���� �������� �Է��Ͻðڽ��ϱ�(Y/N)? ",
						hcount?"nother " : "" );
		scanf(" %c", &test );
		if(tolower(test) == 'n') 
			break; 

		/* ����ü�� ������ �޸� �Ҵ� */
		phorse[hcount] = (struct horse*) malloc(sizeof(struct horse));

		printf("\n���� �̸��� �Է��ϼ���: " );
		scanf("%s", phorse[hcount]->name ); 							/* ���� �̸��� �Է�	*/

		printf("\n%s�� ���̴�? ", phorse[hcount]->name );
		scanf("%d", &phorse[hcount]->age ); 							/* ���� ���̸� �Է�	*/

		printf("\n%s�� Ű��(cm)? ", phorse[hcount]->name ); 
		scanf("%d", &phorse[hcount]->height ); 							/* ���� Ű �Է� 	*/ 

		printf("\n%s�� �ƺ���? ", phorse[hcount]->name );
		scanf("%s", phorse[hcount]->father ); 							/* �ƺ��� �̸� �Է�	*/ 

		printf("\n%s�� ������? ", phorse[hcount]->name );
		scanf("%s", phorse[hcount]->mother ); 							/* ������ �̸� �Է�	*/
	}

	/* �Է¹��� ���� Ȯ�� */
	for (i = 0 ; i < hcount ; i++ )
	{
		printf("\n\n%s�� ���̴� %d���̰� Ű�� %dcm�̸�,", 
						phorse[i]->name, phorse[i]->age, phorse[i]->height); 
		printf(" �ƺ��� %s�̰� ������ %s�Դϴ�.", 
						phorse[i]->father, phorse[i]->mother); 
		free(phorse[i]); 
	} 
} 
