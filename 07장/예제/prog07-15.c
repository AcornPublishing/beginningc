/* ���α׷� 7.15 ���ڿ� ���� */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define BUFFER_LEN 100 											/* �Է¹����� ���� 						*/
#define NUM_P 100 												/* ���ڿ� ������ �ִ밪 				*/
#define TRUE 1 
#define FALSE 0 

void main() 
{ 
	char buffer[BUFFER_LEN]; 									/* �Է� ���ڿ��� ������ ���� 			*/
	char *pS[NUM_P] = { NULL }; 								/* ���ڿ� �������� �迭 				*/
	char *pTemp = NULL; 										/* �ӽ� ������ 							*/
	int i = 0; 													/* ���� ī���� 							*/ 
	int sorted = FALSE; 										/* ���ڿ��� ���ĵ� �������� ǥ�� 		*/ 
	int last_string = 0; 										/* ���������� �Է��� ���ڿ��� �ε���	*/ 

	printf("\n���ڿ� �� �ٿ� �ϳ��� �Է��ϼ���. �ٹٲ��� �Ϸ��� Enter�� ��������.\n" 
					"���ڿ��� ��� �Է������� �� �ٿ��� Enter�� ������ �˴ϴ�.\n\n"); 
	while((*gets(buffer) != '\0') && (i < NUM_P)) 
	{ 
		pS[i] = (char*)malloc(strlen(buffer) + 1);
		if(pS[i]==NULL) 										/* �޸𸮰� �Ҵ���� �ʾҴ��� �˻�		*/
		{
			printf(" �޸𸮸� �Ҵ��� �� �����ϴ�. ���α׷��� �����մϴ�.\n"); 
			return;
		}
		strcpy(pS[i++], buffer);
	}
	last_string = i; 											/* ������ ���ڿ��� �ε��� ���� 			*/

	/* ���ڿ��� ������������ ���� */
	while(!sorted)
	{
		sorted = TRUE;
		for (i = 0 ; i < last_string - 1 ; i++)
			if(strcmp(pS[i], pS[i + 1]) > 0)
			{
				sorted = FALSE; 								/* ���� ���ĵ��� ���� ���� 				*/ 
				pTemp= pS[i]; 									/* ������ pS[i]��						*/ 
				pS[i] = pS[i + 1]; 								/* pS[i + 1]�� 							*/ 
				pS[i + 1] 	= pTemp; 							/* ���� �¹ٲ� 							*/ 
			}
		}

	/* ������ ���ڿ��� ��� */
	printf("\n�Է��Ͻ� ���ڿ��� ������ ����Դϴ�.\n\n");
	for (i = 0 ; i < last_string ; i++)
	{
		printf("%s\n", pS[i] );
		free( pS[i] );
		pS[i] = NULL;
	} 
} 
