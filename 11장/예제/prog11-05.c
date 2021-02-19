/* ���α׷� 11.5 �� �������� �̵��� �� �ִ� ���Ḯ��Ʈ */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void main()
{ 
	struct horse 												/* ����ü ���� */ 
	{ 
		int age;
		int height;
		char name[20];
		char father[20];
		char mother[20];
		struct horse *next; 									/* ���� ����ü�� ����Ű�� ������*/
		struct horse *previous; 								/* ���� ����ü�� ����Ű�� ������*/
	}; 

	struct horse *first = NULL; 								/* ù��° ���� ����Ű�� ������ 	*/
	struct horse *current = NULL; 								/* ���� ���� ����Ű�� ������ 	*/
	struct horse *last = NULL; 									/* ���� ���� ����Ű�� ������ 	*/

	char test = '\0'; 											/* �Է��� ���� �˻��ϴ� �� 		*/ 

	for( ; ; )
	{
		printf("\n���� �������� �Է��Ͻðڽ��ϱ�(Y/N)? ", 
						first == NULL?"�ٸ� " : "");
		scanf(" %c", &test );
		if(tolower(test) == 'n') 
			break; 

		/* ���� �Էµ� ��� horse ����ü�� �޸� �Ҵ� */
		current = (struct horse*)malloc(sizeof(struct horse));

		if( first == NULL ) 
		{ 
			first = current; 									/* ù��° ���� ����Ű�� ������ ����	*/ 
			current->previous = NULL;
		}
		else
		{
			last->next = current; 								/* ���� ���� ���� �� �ּ� ���� 		*/ 
			current->previous = last; 							/* ���� ���� ���� �� �ּ� 			*/ 
		} 

		printf("\n���� �̸��� �Է��ϼ���: ");
		scanf("%s", current -> name ); 							/* ���� �̸��� �Է�		*/

		printf("\n%s�� ���̴�? ", current -> name);
		scanf("%d", &current -> age); 							/* ���� ���̸� �Է�		*/

		printf("\n%s�� Ű��(cm)?", current -> name);
		scanf("%d", &current -> height); 						/*���� Ű�� �Է� 		*/

		printf("\n%s�� �ƺ���? ", current -> name);
		scanf("%s", current -> father); 						/* �ƺ��� �̸��� �Է�	*/

		printf("\n%s�� ������? ", current -> name);
		scanf("%s", current -> mother); 						/* ������ �̸��� �Է�	*/

		current -> next = NULL; 								/* ������ ���� ��� 		*/ 
		last = current; 										/* ������ ���� �ּҸ� ����	*/ 
	} 

	/* �Է��� ������ Ȯ�� */
	while(current != NULL) 										/* ���� �����͸� �������� ��� */
	{
		printf("\n\n%s�� ���̴� %d���̰� Ű�� %dcm�̸�,", 
						current->name, current->age, current->height); 
		printf(" �ƺ��� %s�̰� ������ %s�Դϴ�.", current->father, 
						current->mother); 
		last = current; 										/* �����͸� ������ �޸𸮸� ������ �� �ֵ��� ��	*/ 
		current = current->previous; 							/* current�� ����� ���� ����ü�� ����Ŵ 		*/ 
		free(last); 											/* ����� horse ����ü�� �޸𸮴� ����			*/ 
	}
}
