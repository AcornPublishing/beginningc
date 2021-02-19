/* ���α׷� 12.5 ���� ���� ���α׷�*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
 
#include <string.h> 

char myfile[] = "C:\\myfile.bin"; 									/* ������ �����̸� 		*/ 
FILE *pfile = NULL; 												/* ���� ������ 			*/ 

struct Date 														/* ��¥�� ������ ����ü	*/ 
{
	int day;
	int month;
	int year;
}; 

typedef struct family 												/* Family ����ü ����	*/ 
{
	struct Date dob;
	char name[20];
	char pa_name[20];
	char ma_name[20];
}Family; 

/* �Լ����� */
int get_person(Family *pfamily); 									/* �Է� �Լ� 		*/ 
void show_person_data(void); 										/* ��� �Լ� 		*/ 
void get_parent_dob(Family *pfamily); 								/* �θ� ã�� �Լ� */ 

void main() 
{ 
	Family member; 													/* Family ����ü�� ������ ���� 		*/ 
	Family *pmember = &member; 										/* Family ����ü�� ����Ű�� ������	*/ 

	if((pfile = fopen(myfile, "wb")) == NULL) 
	{ 
		printf("\n%s�� �� �� �����ϴ�.\n", myfile); 
		abort(); 
	} 

	while(get_person(pmember)) 										/* �о���� �Է°��� ������ 			*/ 
		fwrite(pmember, sizeof member, 1, pfile); 					/* ���Ͽ� ����� 						*/ 

	fclose(pfile); 													/* ����� ������ ������ ���� 			*/ 

	show_person_data(); 											/* ���Ͽ� �ִ� ���� ������ �����͸� ���*/ 

	if(remove(myfile))
		printf("\n%s�� ������ �� �����ϴ�.\n", myfile);
	else
		printf("\n%s�� �����߽��ϴ�.\n", myfile);
}

/* Family ����� �����͸� �Է¹޴� �Լ� */
int get_person( Family *temp)
{
	static char more = '\0'; 										/* �Է��� ���� �˻��ϴ� ��	*/ 

	printf("\n%s���� �������� �������� �Է��Ͻðڽ��ϱ� (Y/N)? ",
					more != '\0'?"�ٸ� " : "" );
	scanf(" %c", &more);

	if(tolower(more) == 'n') 
		return 0;

	printf("\n������ �̸��� �Է��ϼ���: ");
	scanf("%s", temp->name); 										/* ������ �̸��� �Է¹���	*/

	printf("\n%s�� ��������� �Է��ϼ���(�� �� ��); ", temp->name);
	scanf("%d %d %d", &temp->dob.year, &temp->dob.month, &temp->dob.day);

	printf("\n%s�� �ƹ�����? ", temp->name); 
	scanf("%s", temp->pa_name); 									/* �ƹ����� �̸��� �Է¹���	*/ 

	printf("\n%s�� ��Ӵϴ�? ", temp->name); 		
	scanf("%s", temp->ma_name); 									/* ��Ӵ��� �̸��� �Է¹���	*/ 

	return 1; 		
} 

/* ���Ͽ� ��ϵ� ������ �����͸� ����ϴ� �Լ� */
void show_person_data(void)
{
	Family member; 													/* ���Ͽ� ��ϵ� �����͸� ������ ����ü	*/ 
	Family *pmember = &member; 										/* Family ����ü�� ����Ű�� ������ 		*/ 
	fpos_t current = 0; 											/* ���� ��ġ 							*/ 

	pfile = fopen(myfile, "rb"); 									/* ���� �б������ ������ ���� 			*/ 

	/* �������� �����͸� ���� */ 
	while(fread(pmember, sizeof member, 1, pfile))   
	{ 
		fgetpos(pfile, &current); 									/* ������ġ�� ���� 								*/ 
		printf("\n\n%s�� �ƹ����� %s�̰� ��Ӵϴ� %s�Դϴ�.", 
						pmember->name, pmember->pa_name, pmember->ma_name); 
		get_parent_dob(pmember); 									/* �θ��� �����͸� ���� 						*/ 
		fsetpos(pfile, &current); 									/* ���� ����ü�� ���� �� �ֵ��� ���� ��ġ ����	*/ 
	} 
	fclose(pfile); 													/* ���� �ݱ� 									*/ 
} 

/* �θ��� ��������� ã�� �Լ� */
void get_parent_dob(Family *pmember)
{
	Family testmem; 												/* �θ� ����ü�� ������ ���� 			*/ 
	Family *ptestmem = &testmem; 									/* �θ� ����ü�� ����Ű�� ������ 		*/ 
	int num_found = 0; 												/* ã�� �θ��� �� 						*/ 

	rewind(pfile); 													/* ������ ������ġ�� ������ġ�� ����	*/ 
	
	/* �θ��� ������ ������ */ 
	while(fread(ptestmem, sizeof(Family), 1, pfile)) 
	{ 
		if(strcmp(pmember->pa_name, ptestmem->name) == 0) 			/*�ƹ����� �´°�?	*/ 
		{ 			/* �ƹ����� ã���� */ 
			printf("\n �ƹ����� %�� %d�� %�Ͽ� �¾���ϴ�.", 
							ptestmem->dob.year, ptestmem->dob.month, ptestmem->dob.day); 

			if(++num_found == 2) 									/* �θ��� ���� 1 ������Ŵ 					*/ 
				return; 											/* �θ� ��� ã�����Ƿ� �Լ��� ��������	*/ 
		} 
		else 
			if(strcmp(pmember->ma_name, ptestmem->name) == 0) 		/*��Ӵϰ� �´°�? 	*/ 
			{ 			/* ��Ӵϸ� ã���� */ 
				printf("\n ��Ӵϴ� %�� %d�� %�Ͽ� �¾���ϴ�.", 
								ptestmem->dob.year, ptestmem->dob.month, ptestmem->dob.day); 

				if(++num_found == 2) 								/* �θ��� ���� 1 ������Ŵ 					*/
					return; 										/* �θ� ��� ã�����Ƿ� �Լ��� ��������	*/
			} 
	} 
} 

