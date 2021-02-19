/* 프로그램 11.4 꼬리에 꼬리를 무는 말 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void main()
{ 
	struct horse 												/* 구조체 선언	*/ 
	{ 
		int age; 
		int height;
		char name[20];
		char father[20];
		char mother[20];
		struct horse *next; 									/* 다음 구조체를 가리키는 포인터*/
	}; 

	struct horse *first = NULL; 								/* 첫번째 말을 가리키는 포인터	*/
	struct horse *current = NULL; 								/* 현재 말을 가리키는 포인터 	*/
	struct horse *previous = NULL; 								/* 이전 말을 가리키는 포인터 	*/

	char test = '\0'; 											/* 입력의 끝을 검사하는 값 		*/ 

	for( ; ; ) 
	{ 
		printf("\n%s말의 상세정보를 입력하시겠습니까(Y/N)? ", 
						first != NULL?"다른 " : "" ); 
		scanf(" %c", &test ); 

		if(tolower(test) == 'n') 
			break; 

		/* 구조체에 메모리 할당 */
		current = (struct horse*) malloc(sizeof(struct horse)); 

		if(first == NULL) 
			first = current; 									/* 첫번째 말의 포인터 설정	*/ 

		if(previous != NULL) 
			previous -> next = current; 						/* 이전 말의 포인터 설정	*/ 

		printf("\n말의 이름을 입력하세요: ");
		scanf("%s", current -> name); 							/* 말의 이름을 입력 		*/

		printf("\n%s의 나이는? ", current -> name);
		scanf("%d", &current -> age); 							/* 말의 나이를 입력 		*/

		printf("\n%s의 키는(cm)? ", current -> name );
		scanf("%d", &current -> height); 						/* 말의 키를 입력 			*/

		printf("\n%s의 아빠는? ", current -> name);
		scanf("%s", current -> father); 						/* 아빠의 이름을 입력 		*/

		printf("\n%s의 엄마는? ", current -> name);
		scanf("%s", current -> mother); 						/* 엄마의 이름 입력 		*/

 
		current->next = NULL; 									/* 마지막인 경우 			*/ 
		previous = current; 									/* 마지막 말의 주소를 저장 	*/ 
	} 		

	/* 입력받은 내용을 확인 */ 		
	current = first; 											/* 처음부터 시작 			*/ 

	while (current != NULL) 									/* 포인터가 NULL이 아니면	*/
	{ 															/* 데이터를 출력			*/
		printf("\n\n%s의 나이는 %d살이고 키는 %dcm이며,",
						current->name, current->age, current->height);
		printf(" 아빠는 %s이고 엄마는 %s입니다.", current->father,
						current->mother); 
		previous = current; 									/* 포인터를 저장해 메모리를 해제할 수 있도록 함 */
		current = current->next; 								/* 다음 말의 포인터를 얻음 	*/ 
		free(previous); 										/* 이전 말의 메모리를 해제	*/ 
	} 
} 
