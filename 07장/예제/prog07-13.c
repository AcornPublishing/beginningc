/* ���α׷� 7.13 ���ڿ��� ����Ű�� �������� �迭 */ 
#include <stdio.h>
#define BUFFER_LEN 500
void main()
{
	char buffer[BUFFER_LEN]; 											/* ���ڿ��� ���� 			*/
	char *pS[3] = { NULL }; 											/* ���ڿ� �������� �迭 	*/
	char *pbuffer = buffer; 											/* buffer�� ����Ű�� ������	*/
	int i = 0; 															/* ���� ī���� 				*/

	/* Ű����� ���ڿ��� �Է¹��� */ 
	for (i=0; i<3 ; i++) 
	{ 
		printf("\n%s�޽����� �Է��ϼ���.\n", i>0 ? "�ٸ� " : "" ); 
		*(pS + i) = pbuffer; 											/* ���ڿ��� ������ġ�� ���� 			*/ 

		while ((*pbuffer++ = getchar()) != '\n'); 						/* ����Ű�� ���� ������ �Է��� �޾Ƶ���	*/
		*(pbuffer - 1) = '\0'; 											/* ���Ṯ�� �߰� 						*/ 
		} 

	printf("\n�Է��Ͻ� ���ڿ��� ������ �����ϴ�.\n\n"); 
	for(i = 0 ; i<3 ; i++) 
		printf("%s\n", *(pS+i)); 

	printf("������� ���� ������ ũ��� %d�����Դϴ�.\n", 
					&buffer[BUFFER_LEN - 1] - pbuffer + 1); 
} 
