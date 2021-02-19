/* ���α׷� 11.6 �⺻���� ���� ������ */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Family *get_person(void); 						/* �Է��Լ��� ����		*/ 

struct Date 
{
	int day;
	int month;
	int year;
}; 

struct Family 											/* Family ����ü ����	*/ 
{ 
	struct Date dob; 
	char name[20]; 
	char father[20]; 
	char mother[20]; 
	struct Family *next; 								/* ���� ����ü�� ����Ű�� ������ 	*/ 
	struct Family *previous; 							/* ���� ����ü�� ����Ű�� ������	*/ 
}; 

void main() 
{ 
	struct Family *first = NULL; 						/* ù��° ����� ����Ű�� ������	*/ 
	struct Family *current = NULL; 						/* ���� ����� ����Ű�� ������ 		*/ 
	struct Family *last = NULL; 						/* ���� ����� ����Ű�� ������		*/ 
	char more = '\0'; 									/* �Է��� ���� �˻��ϴ� �� 			*/ 

	for( ; ; ) 
	{ 
		printf("\n%s���� �������� �������� �Է��Ͻðڽ��ϱ�(Y/N)? ", 
						first != NULL?"�ٸ� " : "" ); 
		scanf(" %c", &more); 
		if(tolower(more) == 'n') 
			break; 

		current = get_person(); 

		if(first == NULL) 
		{
			first = current; 							/* ù��° Family ����ü�� �����͸� ����	*/
			last = current; 							/* ���� �ݺ��� ���� ������ �� 			*/
		}
		else
		{
			last->next = current; 						/* ���� Family ����ü�� ��� next�� �ּҸ� ����	*/ 
			current->previous = last; 					/* current�� ��� previous�� �ּҸ� ���� 		*/
			last = current; 							/* ���� �ݺ��� ���� ������ �� 					*/ 
		}
	}

	/* �Է¹��� ������ Ȯ�� */ 
	
	/* Family�� �����͸� �Է¹��� ������ �ݴ�� ��� */
	while (current != NULL) 
	{
		printf("\n%s��(��) %d�� %d�� %d�� ���������, �θ�� %s��(��) %s�Դϴ�.",
						current->name, current->dob.year, current->dob.month,
						current->dob.day, current->father, current->mother );

		last = current; 								/* �޸𸮸� ������ �� �ֵ��� �����͸� ����	*/
		current = current->previous; 					/* current�� ����� ���� ����ü�� ����Ŵ	*/
		free(last); 									/* ����� Family�� �Ҵ��� �޸𸮸� ����		*/
	} 
} 

/* Family ����ü ����� �����͸� �Է¹޴� �Լ� */
struct Family *get_person(void)
{
	struct Family *temp; 								/* �ӽ� ����ü �����͸� ����*/ 

	/* ����ü �޸� �Ҵ� */
	temp = (struct Family*) malloc(sizeof(struct Family));

	printf("\n�̸��� �Է��ϼ���: ");
	scanf("%s", temp -> name ); 						/* �̸��� ���� 				*/

	printf("\n%s�� ��������� �Է��ϼ���(�� �� ��): ", temp->name);
	scanf("%d %d %d", &temp->dob.year, &temp->dob.month, &temp->dob.day);

	printf("\n%s�� �ƹ��� �̸���? ", temp->name );
	scanf("%s", temp->father ); 						/* �ƹ����� �̸��� ���� 	*/
	printf("\n%s�� ��Ӵ� �̸���? ", temp->name ); 
	scanf("%s", temp -> mother ); 						/* ��Ӵ��� �̸��� ����		*/ 
	
	temp->next = temp->previous = NULL; 				/* �����͸� NULL�� ����		*/ 

	return temp; 										/* Family ����ü�� �ּ� ��ȯ*/ 
} 
