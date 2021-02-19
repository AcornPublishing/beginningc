/* ���α׷� 11.4 ������ ������ ���� �� */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void main()
{ 
	struct horse 												/* ����ü ����	*/ 
	{ 
		int age; 
		int height;
		char name[20];
		char father[20];
		char mother[20];
		struct horse *next; 									/* ���� ����ü�� ����Ű�� ������*/
	}; 

	struct horse *first = NULL; 								/* ù��° ���� ����Ű�� ������	*/
	struct horse *current = NULL; 								/* ���� ���� ����Ű�� ������ 	*/
	struct horse *previous = NULL; 								/* ���� ���� ����Ű�� ������ 	*/

	char test = '\0'; 											/* �Է��� ���� �˻��ϴ� �� 		*/ 

	for( ; ; ) 
	{ 
		printf("\n%s���� �������� �Է��Ͻðڽ��ϱ�(Y/N)? ", 
						first != NULL?"�ٸ� " : "" ); 
		scanf(" %c", &test ); 

		if(tolower(test) == 'n') 
			break; 

		/* ����ü�� �޸� �Ҵ� */
		current = (struct horse*) malloc(sizeof(struct horse)); 

		if(first == NULL) 
			first = current; 									/* ù��° ���� ������ ����	*/ 

		if(previous != NULL) 
			previous -> next = current; 						/* ���� ���� ������ ����	*/ 

		printf("\n���� �̸��� �Է��ϼ���: ");
		scanf("%s", current -> name); 							/* ���� �̸��� �Է� 		*/

		printf("\n%s�� ���̴�? ", current -> name);
		scanf("%d", &current -> age); 							/* ���� ���̸� �Է� 		*/

		printf("\n%s�� Ű��(cm)? ", current -> name );
		scanf("%d", &current -> height); 						/* ���� Ű�� �Է� 			*/

		printf("\n%s�� �ƺ���? ", current -> name);
		scanf("%s", current -> father); 						/* �ƺ��� �̸��� �Է� 		*/

		printf("\n%s�� ������? ", current -> name);
		scanf("%s", current -> mother); 						/* ������ �̸� �Է� 		*/

 
		current->next = NULL; 									/* �������� ��� 			*/ 
		previous = current; 									/* ������ ���� �ּҸ� ���� 	*/ 
	} 		

	/* �Է¹��� ������ Ȯ�� */ 		
	current = first; 											/* ó������ ���� 			*/ 

	while (current != NULL) 									/* �����Ͱ� NULL�� �ƴϸ�	*/
	{ 															/* �����͸� ���			*/
		printf("\n\n%s�� ���̴� %d���̰� Ű�� %dcm�̸�,",
						current->name, current->age, current->height);
		printf(" �ƺ��� %s�̰� ������ %s�Դϴ�.", current->father,
						current->mother); 
		previous = current; 									/* �����͸� ������ �޸𸮸� ������ �� �ֵ��� �� */
		current = current->next; 								/* ���� ���� �����͸� ���� 	*/ 
		free(previous); 										/* ���� ���� �޸𸮸� ����	*/ 
	} 
} 
