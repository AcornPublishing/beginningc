/* 프로그램 11.1 구조체 연습 */
#include <stdio.h>

void main() 
{
	/* 구조체 선언 */
	struct horse
	{
		int age;
		int height;
		char name[20];
		char father[20];
		char mother[20];
	}; 

	struct horse My_first_horse; 								/* 구조체 변수 선언 	*/ 

	/* 입력 데이터로 구조체 변수를 초기화 */ 	
	printf("말의 이름을 입력하세요: " ); 	
	scanf("%s", My_first_horse.name ); 							/* 말의 이름을 입력 	*/ 

	printf("%s의 나이는? ", My_first_horse.name ); 	
	scanf("%d", &My_first_horse.age ); 							/* 말의 나이를 입력 	*/ 

	printf("%s의 키는(cm)? ", My_first_horse.name ); 	
	scanf("%d", &My_first_horse.height ); 						/* 말의 키를 입력 		*/ 

	printf("%s의 아빠는? ", My_first_horse.name );
	scanf("%s", My_first_horse.father ); 						/* 아빠의 이름을 입력	*/

	printf("%s의 엄마는? ", My_first_horse.name );
	scanf("%s", My_first_horse.mother ); 						/* 엄마의 이름을 입력	*/

	/* 입력받은 내용을 확인 */ 
	printf("\n%s의 나이는 %d살이고 키는 %dcm이며,", 
					My_first_horse.name, My_first_horse.age, My_first_horse.height); 
	printf(" 아빠는 %s이고 엄마는 %s입니다.\n", My_first_horse.father,
					My_first_horse.mother ); 
} 
