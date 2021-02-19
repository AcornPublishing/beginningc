/* 프로그램 3.5 더 쉬운 방법으로 문자 검사 */
#include <stdio.h>

void main()
{
	char letter =0; 										/* 입력문자를 저장 	   */ 

	printf("대문자를 하나 입력하세요: "); 					/* 입력을 지시 		   */
	scanf("%c", &letter); 									/* 입력문자를 읽어들임 */

	if ((letter >= 'A') && (letter <= 'Z'))					/* 대문자임을 검사 	   */ 
	{ 	
		letter += 'a'-'A'; 									/* 소문자로 변환 	   */ 
		printf("대문자 %c을(를)입력하셨군요.\n", letter); 	
	} 	
	else 	
		printf("대문자를 입력하지 않으셨네요.\n"); 	
}
