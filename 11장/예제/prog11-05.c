/* 프로그램 11.5 두 방향으로 이동할 수 있는 연결리스트 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void main()
{ 
	struct horse 												/* 구조체 선언 */ 
	{ 
		int age;
		int height;
		char name[20];
		char father[20];
		char mother[20];
		struct horse *next; 									/* 다음 구조체를 가리키는 포인터*/
		struct horse *previous; 								/* 이전 구조체를 가리키는 포인터*/
	}; 

	struct horse *first = NULL; 								/* 첫번째 말을 가리키는 포인터 	*/
	struct horse *current = NULL; 								/* 현재 말을 가리키는 포인터 	*/
	struct horse *last = NULL; 									/* 이전 말을 가리키는 포인터 	*/

	char test = '\0'; 											/* 입력의 끝을 검사하는 값 		*/ 

	for( ; ; )
	{
		printf("\n말의 상세정보를 입력하시겠습니까(Y/N)? ", 
						first == NULL?"다른 " : "");
		scanf(" %c", &test );
		if(tolower(test) == 'n') 
			break; 

		/* 새로 입력된 모든 horse 구조체에 메모리 할당 */
		current = (struct horse*)malloc(sizeof(struct horse));

		if( first == NULL ) 
		{ 
			first = current; 									/* 첫번째 말을 가리키는 포인터 설정	*/ 
			current->previous = NULL;
		}
		else
		{
			last->next = current; 								/* 이전 말의 다음 말 주소 설정 		*/ 
			current->previous = last; 							/* 현재 말의 이전 말 주소 			*/ 
		} 

		printf("\n말의 이름을 입력하세요: ");
		scanf("%s", current -> name ); 							/* 말의 이름을 입력		*/

		printf("\n%s의 나이는? ", current -> name);
		scanf("%d", &current -> age); 							/* 말의 나이를 입력		*/

		printf("\n%s의 키는(cm)?", current -> name);
		scanf("%d", &current -> height); 						/*말의 키를 입력 		*/

		printf("\n%s의 아빠는? ", current -> name);
		scanf("%s", current -> father); 						/* 아빠의 이름을 입력	*/

		printf("\n%s의 엄마는? ", current -> name);
		scanf("%s", current -> mother); 						/* 엄마의 이름을 입력	*/

		current -> next = NULL; 								/* 마지막 말인 경우 		*/ 
		last = current; 										/* 마지막 말의 주소를 저장	*/ 
	} 

	/* 입력한 내용을 확인 */
	while(current != NULL) 										/* 말의 데이터를 역순으로 출력 */
	{
		printf("\n\n%s의 나이는 %d살이고 키는 %dcm이며,", 
						current->name, current->age, current->height); 
		printf(" 아빠는 %s이고 엄마는 %s입니다.", current->father, 
						current->mother); 
		last = current; 										/* 포인터를 저장해 메모리를 해제할 수 있도록 함	*/ 
		current = current->previous; 							/* current는 목록의 이전 구조체를 가리킴 		*/ 
		free(last); 											/* 출력한 horse 구조체의 메모리는 해제			*/ 
	}
}
