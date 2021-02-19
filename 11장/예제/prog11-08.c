/* ���α׷� 11.8 ����׷��� �׸��� */
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

typedef unsigned int uint; 												/* �������� ����	*/ 

/* �Լ����� */
int bar_chart(bar *pfirstbar, uint page_width, uint page_height, char *title);

int main() 
{ 	
	bar firstbar; 														/* ù��° bar ����ü 			*/ 
	bar *plastbar = NULL; 												/* ������ bar�� ����Ű�� ������	*/ 
	char value[80]; 													/* �Է� ���� 					*/ 
	char title[80]; 													/* �׷��� ���� 					*/ 

	printf("\n�׷����� ������ �Է��ϼ���: ");
	gets(title); 														/* �׷��� ������ �о���� 		*/
	for( ;; ) 															/* ���� �Է� ���� 				*/ 
	{ 
		printf("������ ���� �Է��ϼ���(�������� quit�� �Է�): "); 
		gets(value); 

		if(strcmp(value, "quit") == 0) 									/* quit�� �Է��ߴ°�?	*/ 
			break; 														/* �׷��ٸ� �Է��� ����	*/ 

		/* ���� ���븦 ���� */
		if(plastbar == NULL) 											/* ù��° �Է��ΰ�? 	*/ 
		{ 		
			firstbar.pnextbar = NULL; 									/* ���� �����͸� �ʱ�ȭ	*/ 
			plastbar = &firstbar; 										/* ù��° ����ü�� ���	*/ 
		} 		
		else 		
		{ 		
			/* �޸� Ȯ�� */ 		
			if((plastbar->pnextbar = malloc(sizeof(bar))) == NULL) 
			{
				printf("�޸𸮸� �Ҵ��� �� �����ϴ�.\n");
				return -1;
			}
			plastbar = plastbar->pnextbar; 								/* ���� ����ü�� ���� ����ü�� �� ����ü	*/
			plastbar->pnextbar = NULL; 									/* �� ����ü�� ���� ����ü�� NULL�� 		*/
		}
		plastbar->value = atof(value); 									/* ���� ���� */
	}

	/* ����׷����� �׸� */
	bar_chart(&firstbar, PAGE_WIDTH, PAGE_HEIGHT, title); 
	/* �׷����� ��� �׷����Ƿ� �Ҵ��� �޸𸮸� ��� ���� */
	while(firstbar.pnextbar != NULL)
	{
		plastbar = firstbar.pnextbar; 									/* ���� ����ü�� ����Ű�� �����͸� ����	*/
		firstbar.pnextbar = plastbar->pnextbar;							/* ���� ����ü�� ���� ����ü�� ����		*/
		free(plastbar); 												/* ���� �޸𸮸� ���� 					*/
	} 
	return 0; 
}


int bar_chart(bar *pfirstbar, uint page_width, uint page_height, char *title) 
{ 		
	bar *plastbar = pfirstbar; 											/* ���� ���븦 ����Ű�� ������ 		*/ 
	double max = 0.0; 													/* ������ �ִ밪 					*/ 
	double min = 0.0; 													/* ������ �ּҰ�					*/ 
	double vert_scale = 0.0; 											/* ���� ������ ���� ���� 			*/
	double position = 0.0;												/* �׷������� ������ �������� ��ġ	*/
	uint bar_count = 1; 												/* ������ ���� - �ּ��� 1������ ��	*/ 
	uint barwidth = 0; 													/* ������ �� 						*/ 
	uint space = 2; 													/* ���� ������ ���� 				*/ 
	uint i = 0; 														/* ���� ī���� 						*/ 
	uint bars = 0;														/* ������ ���� ī����				*/
	char *column = NULL; 												/* ���븦 �׸��� ���ڿ� 			*/ 
	char *blank = NULL; 												/* ���� �̿��� ������ �׸��� ���ڿ�	*/ 
	int axis = FALSE;													/* ���� �׷ȴ��� ǥ��				*/
	
	/* ������ �ִ밪�� �ּҰ��� �˻� */ 

	/* max�� min�� ��� ù��° ������ ������ ���� */
	max = min = plastbar->value; 
	while((plastbar = plastbar->pnextbar) != NULL)
	{
		bar_count++; 													/* bar_count�� 1 ������Ŵ		*/
		max = (max < plastbar->value)? plastbar->value : max;
		min = (min > plastbar->value)? plastbar->value : min;
	} 
	vert_scale = (max - min)/page_height; 								/* ���� ���� ���� ���̸� ���	*/ 

	/* Check bar width */
	if((barwidth = page_width/bar_count - space) < 1) 
	{
		printf("\n�׷��� ������ ���� �ʹ� �����ϴ�.\n");
		return -1;
	}

	/* ���븦 �׸� �� �ʿ��� ���ڿ��� ���� */ 

	/* �޸� Ȯ�� */
	if((column = malloc(barwidth + space + 1)) == NULL) 
	{
		printf("\nbarchart()���� �޸� �Ҵ翡 �����߽��ϴ�. ���α׷��� �����մϴ�.\n"); 
		abort();
	}

	for(i = 0 ; i < space ; i++)
		*(column+i)=' '; 												/* ���� ������ ������ �׸� 		*/ 
	for( ; i < space+barwidth ; i++) 
		*(column+i)='#'; 												/* ���ڸ� ����� ���븦 �׸�	*/ 
	*(column+i) = '\0'; 												/* ���ڿ� ���Ṯ�� �߰� 		*/  

	/* �� ĭ���� ����� ���ڿ��� ���� */ 

	/* �޸� Ȯ�� */
	if((blank = malloc(barwidth + space + 1)) == NULL) 
	{
		printf("\nbarchart()���� �޸� �Ҵ翡 �����߽��ϴ�. ���α׷��� �����մϴ�.\n"); 
		abort(); 
	} 

	for(i = 0 ; i < space+barwidth ; i++) 
		*(blank+i) = ' '; 												/* bar+space�� ����ŭ ������ ��	*/ 
	*(blank+i) = '\0'; 													/* ���ڿ� ���Ṯ�� �߰� 		*/ 
	printf("^ %s\n", title); 											/* �׷��� ���� ���				*/ 
 
	/* ����׷��� �׸��� */
	position = max;
	for(i = 0 ; i <= page_height ; i++)
	{
		/* �������� �׷��� �ϴ��� �˻� */
		if(position <= 0.0 && !axis)
		{
			printf("+"); 												/* ������ ���� 			*/ 
			for(bars = 0; bars < bar_count*(barwidth+space); bars++) 
				printf("-"); 											/* ������ ��� 			*/ 
			printf(">\n"); 
			axis = TRUE; 												/* ���� �׷����� ǥ��	*/ 
			position -= vert_scale;										/* position�� ����		*/ 
			continue; 
		}
		printf("|"); 													/* ������ ��� 			*/
		plastbar = pfirstbar; 											/* ù��° ���� ����		*/ 

		/* �������� ��� ���뿡 ���ʴ�� ���� */
		for(bars = 1; bars <= bar_count; bars++) 
		{
			/* position�� axis�� value ���̿� ������ column�� ����ϰ�	*/ 
			/* �׷��� ������ blank�� ��� 								*/ 
			printf("%s", position <= plastbar->value && 
							plastbar->value >= 0.0 && position > 0.0 ||
							position >= plastbar->value && 
							plastbar->value <= 0.0 && 
							position <= 0.0 ? column: blank);
			plastbar = plastbar->pnextbar; 
		} 
		printf("\n"); 													/* �� ���� ����� ����		*/ 
		position -= vert_scale; 										/* position�� ���� 			*/ 
	} 
	if(!axis) 															/* �������� �̹� ����ߴ°�?*/
	{																	/* �ƴϸ� ���� ��� 		*/
		printf("+");
		for(bars = 0; bars < bar_count*(barwidth+space); bars++)
			printf("-"); 
			printf(">\n"); 
	} 
	free(blank); 														/* ���� ���ڿ��� �޸� ���� */ 
	free(column); 														/* ���� ���ڿ��� �޸� ���� */
	return 0; 		
} 			
