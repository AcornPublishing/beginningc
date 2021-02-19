/* 프로그램 7.14 문자열 입력의 일반화 */
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_LEN 100 												/* 입력버퍼의 길이 		*/
 
#define NUM_P 100 													/* 문자열의 최대 개수 	*/ 

void main() 
{ 
	char buffer[BUFFER_LEN]; 										/* 입력버퍼 			*/ 
	char *pS[NUM_P] = { NULL }; 									/* 문자열 포인터의 배열 */ 
	char *pbuffer = buffer; 										/* buffer의 포인터 		*/ 
	int i = 0; 														/* 루프 카운터 			*/ 
	int j = 0; 														/* 루프 카운터 			*/ 

	for (i = 0; i < NUM_P; i++) 
	{ 
		pbuffer = buffer ; 											/* 포인터를 buffer의 시작위치로 설정 */ 
		printf("\n%s메시지를 입력하세요. 입력을 마치려면 Enter를 누르세요.\n", 
						i>0 ? "다른 " : ""); 

		/* 문자열을 BUFFER_LEN 문자까지 읽어들임 */ 
		while ((pbuffer -buffer < BUFFER_LEN-1) && 
						((*pbuffer++ = getchar()) != '\n')); 

		/* 입력의 끝을 알리는 빈 줄이 있는지 검사 */ 
		if((pbuffer -buffer) < 2) 
			break; 

		/* 문자열이 너무 길지 않은지 검사 */
		if((pbuffer -buffer) == BUFFER_LEN && *(pbuffer-1)!= '\n')
		{
			printf("문자열이 너무 깁니다. 입력범위는 최대 %d글자입니다.", 
							BUFFER_LEN); 
			i--; 
			continue; 
		} 
		*(pbuffer - 1) = '\0';  								/* 널 문자 추가 							*/ 

		pS[i] = (char*)malloc(pbuffer-buffer); 					/* 문자열을 저장할 메모리 할당 				*/ 
		if (pS[i] == NULL) 										/* 메모리가 할당됐는지 검사 				*/ 
		{ 
			printf("\n메모리가 부족합니다. 프로그램을 종료합니다."); 
			return; 											/* 메모리 할당에 실패했으면 프로그램 종료	*/ 
		} 

		/* 문자열을 buffer에서 새 메모리로 복사 */ 
		for(j = 0 ; (*(pS[i] + j) = buffer[j]) != '\0' ; j++); 
	} 

	/* 문자열을 모두 출력 */
	printf("\n입력하신 문자열을 역순으로 출력합니다.\n");
	while (--i >= 0 )
	{
		printf("\n%s", *(pS + i) ); 							/* 마지막 문자열부터 출력 					*/ 
		free(*(pS + i)); 										/* 할당한 메모리 해제 						*/ 
		*(pS + i) = NULL; 										/* 안전을 위해 포인터를 다시 NULL로 설정	*/ 
	} 		
} 			
