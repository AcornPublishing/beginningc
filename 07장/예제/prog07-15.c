/* 프로그램 7.15 문자열 정렬 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define BUFFER_LEN 100 											/* 입력버퍼의 길이 						*/
#define NUM_P 100 												/* 문자열 개수의 최대값 				*/
#define TRUE 1 
#define FALSE 0 

void main() 
{ 
	char buffer[BUFFER_LEN]; 									/* 입력 문자열을 저장할 공간 			*/
	char *pS[NUM_P] = { NULL }; 								/* 문자열 포인터의 배열 				*/
	char *pTemp = NULL; 										/* 임시 포인터 							*/
	int i = 0; 													/* 루프 카운터 							*/ 
	int sorted = FALSE; 										/* 문자열이 정렬된 상태인지 표시 		*/ 
	int last_string = 0; 										/* 마지막으로 입력한 문자열의 인덱스	*/ 

	printf("\n문자열 한 줄에 하나씩 입력하세요. 줄바꿈을 하려면 Enter를 누르세요.\n" 
					"문자열을 모두 입력했으면 빈 줄에서 Enter를 누르면 됩니다.\n\n"); 
	while((*gets(buffer) != '\0') && (i < NUM_P)) 
	{ 
		pS[i] = (char*)malloc(strlen(buffer) + 1);
		if(pS[i]==NULL) 										/* 메모리가 할당되지 않았는지 검사		*/
		{
			printf(" 메모리를 할당할 수 없습니다. 프로그램을 종료합니다.\n"); 
			return;
		}
		strcpy(pS[i++], buffer);
	}
	last_string = i; 											/* 마지막 문자열의 인덱스 저장 			*/

	/* 문자열을 오름차순으로 정렬 */
	while(!sorted)
	{
		sorted = TRUE;
		for (i = 0 ; i < last_string - 1 ; i++)
			if(strcmp(pS[i], pS[i + 1]) > 0)
			{
				sorted = FALSE; 								/* 아직 정렬되지 않은 상태 				*/ 
				pTemp= pS[i]; 									/* 포인터 pS[i]와						*/ 
				pS[i] = pS[i + 1]; 								/* pS[i + 1]을 							*/ 
				pS[i + 1] 	= pTemp; 							/* 서로 맞바꿈 							*/ 
			}
		}

	/* 정렬한 문자열을 출력 */
	printf("\n입력하신 문자열을 정렬한 결과입니다.\n\n");
	for (i = 0 ; i < last_string ; i++)
	{
		printf("%s\n", pS[i] );
		free( pS[i] );
		pS[i] = NULL;
	} 
} 
