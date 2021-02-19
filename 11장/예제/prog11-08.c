/* 프로그램 11.8 막대그래프 그리기 */
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define PAGE_HEIGHT 20 
#define PAGE_WIDTH 40 
#define TRUE 1
#define FALSE 0

typedef struct barTAG 
{ 
	double value; 
	struct barTAG *pnextbar; 
}bar; 

typedef unsigned int uint; 												/* 데이터형 정의	*/ 

/* 함수원형 */
int bar_chart(bar *pfirstbar, uint page_width, uint page_height, char *title);

int main() 
{ 	
	bar firstbar; 														/* 첫번째 bar 구조체 			*/ 
	bar *plastbar = NULL; 												/* 마지막 bar를 가리키는 포인터	*/ 
	char value[80]; 													/* 입력 버퍼 					*/ 
	char title[80]; 													/* 그래프 제목 					*/ 

	printf("\n그래프의 제목을 입력하세요: ");
	gets(title); 														/* 그래프 제목을 읽어들임 		*/
	for( ;; ) 															/* 막대 입력 루프 				*/ 
	{ 
		printf("막대의 값을 입력하세요(끝내려면 quit을 입력): "); 
		gets(value); 

		if(strcmp(value, "quit") == 0) 									/* quit을 입력했는가?	*/ 
			break; 														/* 그렇다면 입력을 끝냄	*/ 

		/* 다음 막대를 저장 */
		if(plastbar == NULL) 											/* 첫번째 입력인가? 	*/ 
		{ 		
			firstbar.pnextbar = NULL; 									/* 다음 포인터를 초기화	*/ 
			plastbar = &firstbar; 										/* 첫번째 구조체를 사용	*/ 
		} 		
		else 		
		{ 		
			/* 메모리 확보 */ 		
			if((plastbar->pnextbar = malloc(sizeof(bar))) == NULL) 
			{
				printf("메모리를 할당할 수 없습니다.\n");
				return -1;
			}
			plastbar = plastbar->pnextbar; 								/* 이전 구조체의 다음 구조체가 새 구조체	*/
			plastbar->pnextbar = NULL; 									/* 새 구조체의 다음 구조체는 NULL로 		*/
		}
		plastbar->value = atof(value); 									/* 값을 저장 */
	}

	/* 막대그래프를 그림 */
	bar_chart(&firstbar, PAGE_WIDTH, PAGE_HEIGHT, title); 
	/* 그래프를 모두 그렸으므로 할당한 메모리를 모두 해제 */
	while(firstbar.pnextbar != NULL)
	{
		plastbar = firstbar.pnextbar; 									/* 다음 구조체를 가리키는 포인터를 저장	*/
		firstbar.pnextbar = plastbar->pnextbar;							/* 다음 구조체의 다음 구조체를 얻음		*/
		free(plastbar); 												/* 다음 메모리를 해제 					*/
	} 
	return 0; 
}


int bar_chart(bar *pfirstbar, uint page_width, uint page_height, char *title) 
{ 		
	bar *plastbar = pfirstbar; 											/* 이전 막대를 가리키는 포인터 		*/ 
	double max = 0.0; 													/* 막대의 최대값 					*/ 
	double min = 0.0; 													/* 막대의 최소값					*/ 
	double vert_scale = 0.0; 											/* 수직 방향의 단위 길이 			*/
	double position = 0.0;												/* 그래프에서 현재의 수직방향 위치	*/
	uint bar_count = 1; 												/* 막대의 개수 - 최소한 1개여야 함	*/ 
	uint barwidth = 0; 													/* 막대의 폭 						*/ 
	uint space = 2; 													/* 막대 사이의 공간 				*/ 
	uint i = 0; 														/* 루프 카운터 						*/ 
	uint bars = 0;														/* 막대의 루프 카운터				*/
	char *column = NULL; 												/* 막대를 그리는 문자열 			*/ 
	char *blank = NULL; 												/* 막대 이외의 여백을 그리는 문자열	*/ 
	int axis = FALSE;													/* 축을 그렸는지 표시				*/
	
	/* 막대의 최대값과 최소값을 검색 */ 

	/* max와 min을 모두 첫번째 막대의 값으로 설정 */
	max = min = plastbar->value; 
	while((plastbar = plastbar->pnextbar) != NULL)
	{
		bar_count++; 													/* bar_count를 1 증가시킴		*/
		max = (max < plastbar->value)? plastbar->value : max;
		min = (min > plastbar->value)? plastbar->value : min;
	} 
	vert_scale = (max - min)/page_height; 								/* 수직 방향 단위 길이를 계산	*/ 

	/* Check bar width */
	if((barwidth = page_width/bar_count - space) < 1) 
	{
		printf("\n그래프 영역의 폭이 너무 좁습니다.\n");
		return -1;
	}

	/* 막대를 그릴 때 필요한 문자열을 설정 */ 

	/* 메모리 확보 */
	if((column = malloc(barwidth + space + 1)) == NULL) 
	{
		printf("\nbarchart()에서 메모리 할당에 실패했습니다. 프로그램을 종료합니다.\n"); 
		abort();
	}

	for(i = 0 ; i < space ; i++)
		*(column+i)=' '; 												/* 막대 사이의 공백을 그림 		*/ 
	for( ; i < space+barwidth ; i++) 
		*(column+i)='#'; 												/* 문자를 출력해 막대를 그림	*/ 
	*(column+i) = '\0'; 												/* 문자열 종료문자 추가 		*/  

	/* 빈 칸으로 사용할 문자열을 설정 */ 

	/* 메모리 확보 */
	if((blank = malloc(barwidth + space + 1)) == NULL) 
	{
		printf("\nbarchart()에서 메모리 할당에 실패했습니다. 프로그램을 종료합니다.\n"); 
		abort(); 
	} 

	for(i = 0 ; i < space+barwidth ; i++) 
		*(blank+i) = ' '; 												/* bar+space의 폭만큼 여백을 줌	*/ 
	*(blank+i) = '\0'; 													/* 문자열 종료문자 추가 		*/ 
	printf("^ %s\n", title); 											/* 그래프 제목 출력				*/ 
 
	/* 막대그래프 그리기 */
	position = max;
	for(i = 0 ; i <= page_height ; i++)
	{
		/* 수평축을 그려야 하는지 검사 */
		if(position <= 0.0 && !axis)
		{
			printf("+"); 												/* 수평축 시작 			*/ 
			for(bars = 0; bars < bar_count*(barwidth+space); bars++) 
				printf("-"); 											/* 수평축 출력 			*/ 
			printf(">\n"); 
			axis = TRUE; 												/* 축을 그렸음을 표시	*/ 
			position -= vert_scale;										/* position을 감소		*/ 
			continue; 
		}
		printf("|"); 													/* 수직출 출력 			*/
		plastbar = pfirstbar; 											/* 첫번째 막대 시작		*/ 

		/* 루프에서 모든 막대에 차례대로 접근 */
		for(bars = 1; bars <= bar_count; bars++) 
		{
			/* position이 axis와 value 사이에 있으면 column을 출력하고	*/ 
			/* 그렇지 않으면 blank를 출력 								*/ 
			printf("%s", position <= plastbar->value && 
							plastbar->value >= 0.0 && position > 0.0 ||
							position >= plastbar->value && 
							plastbar->value <= 0.0 && 
							position <= 0.0 ? column: blank);
			plastbar = plastbar->pnextbar; 
		} 
		printf("\n"); 													/* 한 행의 출력을 끝냄		*/ 
		position -= vert_scale; 										/* position을 감소 			*/ 
	} 
	if(!axis) 															/* 수평축을 이미 출력했는가?*/
	{																	/* 아니면 지금 출력 		*/
		printf("+");
		for(bars = 0; bars < bar_count*(barwidth+space); bars++)
			printf("-"); 
			printf(">\n"); 
	} 
	free(blank); 														/* 여백 문자열의 메모리 해제 */ 
	free(column); 														/* 막대 문자열의 메모리 해제 */
	return 0; 		
} 			
