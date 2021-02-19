/* Program 7.12 메모리 관리와 문자열 저장 */
#include <stdio.h>
#define BUFFER_LEN 500

void main()
{
	char buffer[BUFFER_LEN]; 												/* 문자열을 저장 			*/
	char *pS1 = NULL; 														/* 첫번째 문자열의 포인터 	*/
	char *pS2 = NULL; 														/* 두번째 문자열의 포인터 	*/
	char *pS3 = NULL; 														/* 세번째 문자열의 포인터 	*/
	char *pbuffer = buffer; 												/* buffer의 포인터 			*/

	printf("\n메시지를 입력하세요.\n"); 
	pS1 = pbuffer; 															/* 첫번째 메시지의 주소를 저장 			*/ 
	while ((*pbuffer++ = getchar()) != '\n'); 								/* 엔터키를 누를 때까지 입력을 받아들임	*/
	*(pbuffer - 1) = '\0'; 													/* 널문자 추가 							*/ 
	printf("\n다른 메시지를 입력하세요.\n");
	pS2 = pbuffer; 															/* 첫번째 메시지의 주소를 저장 			*/
	while ((*pbuffer++ = getchar()) != '\n');								/* 엔터키를 누를 때까지 입력을 받아들임	*/
	*(pbuffer - 1) = '\0'; 													/* 널문자 추가 							*/
	printf("\n다른 메시지를 입력하세요.\n");
	pS3 = pbuffer; 															/* 첫번째 메시지의 주소를 저장 			*/
	while((*pbuffer++ = getchar()) != '\n'); 								/* 엔터키를 누를 때까지 입력을 받아들임	*/
	*(pbuffer - 1) = '\0'; 													/* 널문자 추가 							*/
	printf("\n입력하신 문자열은 다음과 같습니다.\n\n%s\n%s\n%s", pS1, pS2, pS3);
	printf("\n사용하지 않은 버퍼의 크기는 %d문자입니다.\n", 
					&buffer[BUFFER_LEN - 1] - pbuffer + 1); 
} 
