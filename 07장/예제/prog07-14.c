/* ���α׷� 7.14 ���ڿ� �Է��� �Ϲ�ȭ */
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_LEN 100 												/* �Է¹����� ���� 		*/
 
#define NUM_P 100 													/* ���ڿ��� �ִ� ���� 	*/ 

void main() 
{ 
	char buffer[BUFFER_LEN]; 										/* �Է¹��� 			*/ 
	char *pS[NUM_P] = { NULL }; 									/* ���ڿ� �������� �迭 */ 
	char *pbuffer = buffer; 										/* buffer�� ������ 		*/ 
	int i = 0; 														/* ���� ī���� 			*/ 
	int j = 0; 														/* ���� ī���� 			*/ 

	for (i = 0; i < NUM_P; i++) 
	{ 
		pbuffer = buffer ; 											/* �����͸� buffer�� ������ġ�� ���� */ 
		printf("\n%s�޽����� �Է��ϼ���. �Է��� ��ġ���� Enter�� ��������.\n", 
						i>0 ? "�ٸ� " : ""); 

		/* ���ڿ��� BUFFER_LEN ���ڱ��� �о���� */ 
		while ((pbuffer -buffer < BUFFER_LEN-1) && 
						((*pbuffer++ = getchar()) != '\n')); 

		/* �Է��� ���� �˸��� �� ���� �ִ��� �˻� */ 
		if((pbuffer -buffer) < 2) 
			break; 

		/* ���ڿ��� �ʹ� ���� ������ �˻� */
		if((pbuffer -buffer) == BUFFER_LEN && *(pbuffer-1)!= '\n')
		{
			printf("���ڿ��� �ʹ� ��ϴ�. �Է¹����� �ִ� %d�����Դϴ�.", 
							BUFFER_LEN); 
			i--; 
			continue; 
		} 
		*(pbuffer - 1) = '\0';  								/* �� ���� �߰� 							*/ 

		pS[i] = (char*)malloc(pbuffer-buffer); 					/* ���ڿ��� ������ �޸� �Ҵ� 				*/ 
		if (pS[i] == NULL) 										/* �޸𸮰� �Ҵ�ƴ��� �˻� 				*/ 
		{ 
			printf("\n�޸𸮰� �����մϴ�. ���α׷��� �����մϴ�."); 
			return; 											/* �޸� �Ҵ翡 ���������� ���α׷� ����	*/ 
		} 

		/* ���ڿ��� buffer���� �� �޸𸮷� ���� */ 
		for(j = 0 ; (*(pS[i] + j) = buffer[j]) != '\0' ; j++); 
	} 

	/* ���ڿ��� ��� ��� */
	printf("\n�Է��Ͻ� ���ڿ��� �������� ����մϴ�.\n");
	while (--i >= 0 )
	{
		printf("\n%s", *(pS + i) ); 							/* ������ ���ڿ����� ��� 					*/ 
		free(*(pS + i)); 										/* �Ҵ��� �޸� ���� 						*/ 
		*(pS + i) = NULL; 										/* ������ ���� �����͸� �ٽ� NULL�� ����	*/ 
	} 		
} 			
