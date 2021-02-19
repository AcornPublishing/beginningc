/* 프로그램 8.6 함수를 통해 구현하는 문자열 정렬 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int str_in(char **); 																/* str_in의 함수원형 	*/
void str_sort(char *[], int); 														/* str_sort의 함수원형	*/
void str_out(char *[], int); 														/* str_out의 함수원형 	*/

#define BUFFER_LEN 240
#define NUM_P 50

/* main 함수 - 여기에서 실행이 시작 */
void main()
{
	char *pS[NUM_P]; 																/* 문자열 포인터의 배열 	*/ 
	int count = 0; 																	/* 읽어들인 문자열의 개수	*/ 

	printf("\n문자열 한 줄에 하나씩 입력하세요. 줄바꿈을 하려면 Enter를 누르세요.\n" 
					"문자열을 모두 입력했으면 빈 줄에서 Enter를 누르면 됩니다.\n\n"); 

	for(count = 0; count < NUM_P ; count++) 										/* 최대 NUM_P개까지 문자열 입력	*/
		if(!str_in(&pS[count]) ) 													/* 문자열을 읽어들임 			*/
			break; 																	/* 0을 반환하면 입력 중지 		*/

	str_sort( pS, count ); 															/* 문자열 정렬	*/ 
	str_out( pS, count ); 															/* 문자열 출력	*/ 
} 

/****************************************************************
 * 					문자열 입력 루틴 							* 
 * 이 함수의 인자는 문자열 포인터를 가리키는 포인터로 			* 
 * char** 형임 													* 
 * 빈 문자열이거나 메모리를 할당하지 못했으면 FALSE를 반환하고	*
 * 그렇지 않으면 TRUE를 반환									*
 ****************************************************************/ 
int str_in(char **pString) 
{ 
	char buffer[BUFFER_LEN]; 														/* 입력문자열을 저장할 공간 	*/ 

	if(gets(buffer) == NULL ) 														/* gets()가 NULL을 반환했는가?	*/ 
	{
		printf("\n문자열을 읽을 때 오류가 발생했습니다.\n");
		return FALSE; 																/* 읽기에 오류 발생 			*/
	} 

	if(buffer[0] == '\0') 															/* 빈 문자열을 읽었는가? 		*/
		return FALSE;

	*pString = (char*)malloc(strlen(buffer) + 1); 

	if(*pString == NULL) 															/* 메모리가 할당됐는지 검사 	*/ 
	{
		printf("\n메모리가 부족합니다.");
		return FALSE; 																/* 메모리가 할당되지 않았음 	*/
	} 

	strcpy(*pString, buffer); 														/* 읽어들인 문자열을 인자에 복사 	*/ 
	return TRUE; 
} 

/********************************************************************
 * 					문자열 정렬 루틴 								*
 * 첫번째 인자는 문자열을 가리키는 포인터의 배열로 char**형임 		*
 * 두번째 인자는 포인터 배열에 있는 요소의 개수, 즉 문자열의 개수임 *
 ********************************************************************/ 
void str_sort(char *p[], int n) 
{ 
	char *pTemp = NULL; 															/* 임시 포인터					*/ 
	int i = 0; 																		/* 루프 카운터 					*/ 
	int sorted = FALSE; 															/* 문자열 정렬여부 표시기 		*/ 
	while(!sorted) 																	/* 바꿀 것이 없을 때까지 반복	*/ 
	{ 
		sorted = TRUE; 																/* 바꿀 것이 없음을 나타내도록 표시기 초기화	*/ 
		for( i = 0 ; i<n-1 ; i++ ) 
			if(strcmp(p[i], p[i + 1]) > 0) 
			{ 
				sorted = FALSE; 													/* 정렬되지 않았음을 표시 		*/ 
				pTemp= p[i]; 														/* 포인터	p[i] 				*/ 
				p[i] = p[i + 1]; 													/* 			와 					*/ 
				p[i + 1] 	= pTemp; 												/* 			p[i + 1]를 맞바꿈 	*/ 
			} 	
	} 	
} 	

/********************************************************
 * 				문자열 출력 루틴 						*
 * 첫번째 인자는 문자열을 가리키는 포인터의 배열이며	*
 * char**형과 같은 형임 								*
 * 두번째 인자는 배열에 있는 포인터의 개수,				*
 * 즉 문자열의 개수임 									*
*********************************************************/ 	
void str_out(char *p[] , int n) 	
{ 	
	int i = 0; 																		/* 루프 카운터			*/

	printf("\n입력하신 문자열을 정렬합니다:\n\n"); 	
	for (i = 0 ; i<n ; i++) 	
	{ 	
		printf("%s\n", p[i]); 														/* 문자열 출력 			*/ 	
		free(p[i]); 																/* 문자열의 메모리 해제	*/ 	
		p[i] = NULL; 	
	}
	return; 	
} 	
