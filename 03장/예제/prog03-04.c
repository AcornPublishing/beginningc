/* 프로그램 3.4 대문자를 소문자로 바꾸기 */ 
#include <stdio.h> 

void main() 
{ 
	char letter = 0; 								/* 문자를 저장 				   */ 

	printf("대문자를 하나 입력하세요: "); 			/* 입력 지시문 				   */ 
	scanf("%c", &letter); 							/* 문자를 읽어들임 			   */ 

	/* 입력한 문자가 대문자인지 검사 */ 	
	if(letter >= 'A') 								/* A보다 크거나 같은가? 	   */ 
		if (letter <= 'Z') 							/* 그리고 Z보다 작거나 같은가? */ 
		{ 											/* 그렇다면 대문자임 		   */ 
			letter = letter - 'A'+ 'a'; 			/* 대문자를 소문자로 변환 	   */ 
			printf("대문자 %c을(를) 입력하셨군요.\n", letter); 
		} 
		else 										/* 대문자가 아닌 경우 		   */ 
			printf("Shift키를 누른 채로 입력해보세요. 대문자가 필요하답니다.\n"); 
} 
