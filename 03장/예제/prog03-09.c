/* 프로그램 3.9 switch문 실습 */ 
#include <stdio.h> 

void main() 
{ 
	char answer = 0; 						/* 입력문자를 저장할 변수 */

	printf("Y나 N을 입력하세요: "); 
	scanf(" %c", &answer); 

	switch (answer) 
	{ 
		case 'y': case 'Y': 
			printf("\n긍정적인 사고방식으로 답변하셨군요."); 
			break; 

		case 'n': case 'N': 
			printf("\n부정적인 사고방식으로 답변하셨군요."); 
			break; 

		default: 
			printf("\n무슨 사고방식으로 답변하셨나요?"); 
			break; 
	}
}
