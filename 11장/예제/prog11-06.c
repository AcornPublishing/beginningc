/* 프로그램 11.6 기본적인 가족 계층도 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Family *get_person(void); 						/* 입력함수의 원형		*/ 

struct Date 
{
	int day;
	int month;
	int year;
}; 

struct Family 											/* Family 구조체 선언	*/ 
{ 
	struct Date dob; 
	char name[20]; 
	char father[20]; 
	char mother[20]; 
	struct Family *next; 								/* 다음 구조체를 가리키는 포인터 	*/ 
	struct Family *previous; 							/* 이전 구조체를 가리키는 포인터	*/ 
}; 

void main() 
{ 
	struct Family *first = NULL; 						/* 첫번째 사람을 가리키는 포인터	*/ 
	struct Family *current = NULL; 						/* 현재 사람을 가리키는 포인터 		*/ 
	struct Family *last = NULL; 						/* 이전 사람을 가리키는 포인터		*/ 
	char more = '\0'; 									/* 입력의 끝을 검사하는 값 			*/ 

	for( ; ; ) 
	{ 
		printf("\n%s가족 구성원의 상세정보를 입력하시겠습니까(Y/N)? ", 
						first != NULL?"다른 " : "" ); 
		scanf(" %c", &more); 
		if(tolower(more) == 'n') 
			break; 

		current = get_person(); 

		if(first == NULL) 
		{
			first = current; 							/* 첫번째 Family 구조체의 포인터를 설정	*/
			last = current; 							/* 다음 반복을 위해 저장해 둠 			*/
		}
		else
		{
			last->next = current; 						/* 이전 Family 구조체의 멤버 next의 주소를 설정	*/ 
			current->previous = last; 					/* current의 멤버 previous의 주소를 설정 		*/
			last = current; 							/* 다음 반복을 위해 저장해 둠 					*/ 
		}
	}

	/* 입력받은 내용을 확인 */ 
	
	/* Family의 데이터를 입력받은 순서의 반대로 출력 */
	while (current != NULL) 
	{
		printf("\n%s은(는) %d년 %d월 %d일 출생했으며, 부모는 %s와(과) %s입니다.",
						current->name, current->dob.year, current->dob.month,
						current->dob.day, current->father, current->mother );

		last = current; 								/* 메모리를 해제할 수 있도록 포인터를 저장	*/
		current = current->previous; 					/* current는 목록의 이전 구조체를 가리킴	*/
		free(last); 									/* 출력한 Family에 할당한 메모리를 해제		*/
	} 
} 

/* Family 구조체 멤버의 데이터를 입력받는 함수 */
struct Family *get_person(void)
{
	struct Family *temp; 								/* 임시 구조체 포인터를 정의*/ 

	/* 구조체 메모리 할당 */
	temp = (struct Family*) malloc(sizeof(struct Family));

	printf("\n이름을 입력하세요: ");
	scanf("%s", temp -> name ); 						/* 이름을 읽음 				*/

	printf("\n%s의 생년월일을 입력하세요(년 월 일): ", temp->name);
	scanf("%d %d %d", &temp->dob.year, &temp->dob.month, &temp->dob.day);

	printf("\n%s의 아버지 이름은? ", temp->name );
	scanf("%s", temp->father ); 						/* 아버지의 이름을 읽음 	*/
	printf("\n%s의 어머니 이름은? ", temp->name ); 
	scanf("%s", temp -> mother ); 						/* 어머니의 이름을 읽음		*/ 
	
	temp->next = temp->previous = NULL; 				/* 포인터를 NULL로 설정		*/ 

	return temp; 										/* Family 구조체의 주소 반환*/ 
} 
