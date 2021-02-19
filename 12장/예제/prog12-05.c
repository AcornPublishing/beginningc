/* 프로그램 12.5 가족 관리 프로그램*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
 
#include <string.h> 

char myfile[] = "C:\\myfile.bin"; 									/* 물리적 파일이름 		*/ 
FILE *pfile = NULL; 												/* 파일 포인터 			*/ 

struct Date 														/* 날짜를 저장할 구조체	*/ 
{
	int day;
	int month;
	int year;
}; 

typedef struct family 												/* Family 구조체 선언	*/ 
{
	struct Date dob;
	char name[20];
	char pa_name[20];
	char ma_name[20];
}Family; 

/* 함수원형 */
int get_person(Family *pfamily); 									/* 입력 함수 		*/ 
void show_person_data(void); 										/* 출력 함수 		*/ 
void get_parent_dob(Family *pfamily); 								/* 부모를 찾는 함수 */ 

void main() 
{ 
	Family member; 													/* Family 구조체를 저장할 변수 		*/ 
	Family *pmember = &member; 										/* Family 구조체를 가리키는 포인터	*/ 

	if((pfile = fopen(myfile, "wb")) == NULL) 
	{ 
		printf("\n%s을 열 수 없습니다.\n", myfile); 
		abort(); 
	} 

	while(get_person(pmember)) 										/* 읽어들인 입력값이 있으면 			*/ 
		fwrite(pmember, sizeof member, 1, pfile); 					/* 파일에 기록함 						*/ 

	fclose(pfile); 													/* 기록이 끝나면 파일을 닫음 			*/ 

	show_person_data(); 											/* 파일에 있는 가족 구성원 데이터를 출력*/ 

	if(remove(myfile))
		printf("\n%s을 제거할 수 없습니다.\n", myfile);
	else
		printf("\n%s을 제거했습니다.\n", myfile);
}

/* Family 멤버의 데이터를 입력받는 함수 */
int get_person( Family *temp)
{
	static char more = '\0'; 										/* 입력의 끝을 검사하는 값	*/ 

	printf("\n%s가족 구성원의 상세정보를 입력하시겠습니까 (Y/N)? ",
					more != '\0'?"다른 " : "" );
	scanf(" %c", &more);

	if(tolower(more) == 'n') 
		return 0;

	printf("\n가족의 이름을 입력하세요: ");
	scanf("%s", temp->name); 										/* 가족의 이름을 입력받음	*/

	printf("\n%s의 생년월일을 입력하세요(년 월 일); ", temp->name);
	scanf("%d %d %d", &temp->dob.year, &temp->dob.month, &temp->dob.day);

	printf("\n%s의 아버지는? ", temp->name); 
	scanf("%s", temp->pa_name); 									/* 아버지의 이름을 입력받음	*/ 

	printf("\n%s의 어머니는? ", temp->name); 		
	scanf("%s", temp->ma_name); 									/* 어머니의 이름을 입력받음	*/ 

	return 1; 		
} 

/* 파일에 기록된 가족의 데이터를 출력하는 함수 */
void show_person_data(void)
{
	Family member; 													/* 파일에 기록된 데이터를 저장할 구조체	*/ 
	Family *pmember = &member; 										/* Family 구조체를 가리키는 포인터 		*/ 
	fpos_t current = 0; 											/* 파일 위치 							*/ 

	pfile = fopen(myfile, "rb"); 									/* 이진 읽기용으로 파일을 열기 			*/ 

	/* 구성원의 데이터를 읽음 */ 
	while(fread(pmember, sizeof member, 1, pfile))   
	{ 
		fgetpos(pfile, &current); 									/* 현재위치를 저장 								*/ 
		printf("\n\n%s의 아버지는 %s이고 어머니는 %s입니다.", 
						pmember->name, pmember->pa_name, pmember->ma_name); 
		get_parent_dob(pmember); 									/* 부모의 데이터를 얻음 						*/ 
		fsetpos(pfile, &current); 									/* 다음 구조체를 읽을 수 있도록 파일 위치 조정	*/ 
	} 
	fclose(pfile); 													/* 파일 닫기 									*/ 
} 

/* 부모의 생년월일을 찾는 함수 */
void get_parent_dob(Family *pmember)
{
	Family testmem; 												/* 부모 구조체를 저장할 변수 			*/ 
	Family *ptestmem = &testmem; 									/* 부모 구조체를 가리키는 포인터 		*/ 
	int num_found = 0; 												/* 찾은 부모의 수 						*/ 

	rewind(pfile); 													/* 파일의 현재위치를 시작위치로 설정	*/ 
	
	/* 부모의 정보를 가져옴 */ 
	while(fread(ptestmem, sizeof(Family), 1, pfile)) 
	{ 
		if(strcmp(pmember->pa_name, ptestmem->name) == 0) 			/*아버지가 맞는가?	*/ 
		{ 			/* 아버지를 찾았음 */ 
			printf("\n 아버지는 %년 %d월 %일에 태어났습니다.", 
							ptestmem->dob.year, ptestmem->dob.month, ptestmem->dob.day); 

			if(++num_found == 2) 									/* 부모의 수를 1 증가시킴 					*/ 
				return; 											/* 부모를 모두 찾았으므로 함수를 빠져나옴	*/ 
		} 
		else 
			if(strcmp(pmember->ma_name, ptestmem->name) == 0) 		/*어머니가 맞는가? 	*/ 
			{ 			/* 어머니를 찾았음 */ 
				printf("\n 어머니는 %년 %d월 %일에 태어났습니다.", 
								ptestmem->dob.year, ptestmem->dob.month, ptestmem->dob.day); 

				if(++num_found == 2) 								/* 부모의 수를 1 증가시킴 					*/
					return; 										/* 부모를 모두 찾았으므로 함수를 빠져나옴	*/
			} 
	} 
} 

