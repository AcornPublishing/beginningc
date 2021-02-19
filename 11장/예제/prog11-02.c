/* 프로그램 11.2 구조체 연습 */ 
#include <stdio.h>
#include <ctype.h>
void main() 		
{
	struct horse 																					/* 구조체 선언 			*/	
	{
		int age;
		int height;
		char name[20];
		char father[20];
		char mother[20];
	};	

	struct horse My_horses[50]; 											/* 구조체 배열 선언	*/
	int hcount = 0; 														/* 말의 마리 수 	*/
	int i = 0; 																/* 루프 카운터 		*/
	char test = '\0'; 														/* 끝을 나타내는 값	*/

	for(hcount = 0; hcount < 50 ; hcount++ )
	{ 
		printf("\n%s말의 상세정보를 입력하시겠습니까(Y/N)? ", hcount?"다른 " : "" );
		scanf("%c", &test );
		if(tolower(test) == 'n')
			break;

		printf("\n말의 이름을 입력하세요: " );
		scanf("%s", My_horses[hcount].name ); 								/* 말의 이름 입력 	*/

		printf("\n%s의 나이는? ", My_horses[hcount].name );
		scanf("%d", &My_horses[hcount].age ); 								/* 말의 나이 입력 	*/

		printf("\n%s의 키는(cm)? ", My_horses[hcount].name );
		/* 말의 키 입력 */
		scanf("%d", &My_horses[hcount].height );

		printf("\n%s의 아빠는? ", My_horses[hcount].name );
		/* 아빠의 이름 입력 */
		scanf("%s", My_horses[hcount].father ); 

		printf("\n%s의 엄마는? ", My_horses[hcount].name );
		/* 엄마의 이름 입력 */
		scanf("%s", My_horses[hcount].mother ); 
	}

	/* 입력한 내용 확인 */
	for (i = 0 ; i < hcount ; i++ )
	{ 
		printf("\n\n%s의 나이는 %d살이고 키는 %dcm이며,", 
						My_horses[i].name, My_horses[i].age, My_horses[i].height); 
		printf(" 아빠는 %s이고 엄마는 %s입니다.", My_horses[i].father, 
						My_horses[i].mother ); 
	} 
} 
