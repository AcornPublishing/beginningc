/* 프로그램 7.13 문자열을 가리키는 포인터의 배열 */ 
#include <stdio.h>
#define BUFFER_LEN 500
void main()
{
	char buffer[BUFFER_LEN]; 											/* 문자열을 저장 			*/
	char *pS[3] = { NULL }; 											/* 문자열 포인터의 배열 	*/
	char *pbuffer = buffer; 											/* buffer를 가리키는 포인터	*/
	int i = 0; 															/* 루프 카운터 				*/

	/* 키보드로 문자열을 입력받음 */ 
	for (i=0; i<3 ; i++) 
	{ 
		printf("\n%s메시지를 입력하세요.\n", i>0 ? "다른 " : "" ); 
		*(pS + i) = pbuffer; 											/* 문자열의 시작위치를 저장 			*/ 

		while ((*pbuffer++ = getchar()) != '\n'); 						/* 엔터키를 누를 때까지 입력을 받아들임	*/
		*(pbuffer - 1) = '\0'; 											/* 종료문자 추가 						*/ 
		} 

	printf("\n입력하신 문자열은 다음과 같습니다.\n\n"); 
	for(i = 0 ; i<3 ; i++) 
		printf("%s\n", *(pS+i)); 

	printf("사용하지 않은 버퍼의 크기는 %d문자입니다.\n", 
					&buffer[BUFFER_LEN - 1] - pbuffer + 1); 
} 
