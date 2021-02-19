/* 프로그램 11.3 구조체를 가리키는 포인터 */ 
 
#include <stdio.h> 	
#include <ctype.h> 	
#include <stdlib.h> 													/* malloc() 함수의 사용을 위해 포함 */ 

void main() 	
{ 	
	struct horse 														/* 구조체 선언 	*/ 
	{ 	
		int age; 	
		int height; 	
		char name[20]; 	
		char father[20]; 	
		char mother[20]; 	
	}; 	

	struct horse *phorse[50]; 											/* 구조체 포인터의 배열 선언 	*/ 
	int hcount = 0; 													/* 말의 마리수 					*/ 
	int i = 0; 															/* 루프 카운터 					*/ 
	char test = '\0'; 													/* 입력이 끝났음을 검사하는 값	*/ 
	for(hcount = 0; hcount < 50 ; hcount++ )
	{
		printf("\n%s말의 상세정보를 입력하시겠습니까(Y/N)? ",
						hcount?"nother " : "" );
		scanf(" %c", &test );
		if(tolower(test) == 'n') 
			break; 

		/* 구조체를 저장할 메모리 할당 */
		phorse[hcount] = (struct horse*) malloc(sizeof(struct horse));

		printf("\n말의 이름을 입력하세요: " );
		scanf("%s", phorse[hcount]->name ); 							/* 말의 이름을 입력	*/

		printf("\n%s의 나이는? ", phorse[hcount]->name );
		scanf("%d", &phorse[hcount]->age ); 							/* 말의 나이를 입력	*/

		printf("\n%s의 키는(cm)? ", phorse[hcount]->name ); 
		scanf("%d", &phorse[hcount]->height ); 							/* 말의 키 입력 	*/ 

		printf("\n%s의 아빠는? ", phorse[hcount]->name );
		scanf("%s", phorse[hcount]->father ); 							/* 아빠의 이름 입력	*/ 

		printf("\n%s의 엄마는? ", phorse[hcount]->name );
		scanf("%s", phorse[hcount]->mother ); 							/* 엄마의 이름 입력	*/
	}

	/* 입력받은 정보 확인 */
	for (i = 0 ; i < hcount ; i++ )
	{
		printf("\n\n%s의 나이는 %d살이고 키는 %dcm이며,", 
						phorse[i]->name, phorse[i]->age, phorse[i]->height); 
		printf(" 아빠는 %s이고 엄마는 %s입니다.", 
						phorse[i]->father, phorse[i]->mother); 
		free(phorse[i]); 
	} 
} 
