/* Program 7.12 �޸� ������ ���ڿ� ���� */
#include <stdio.h>
#define BUFFER_LEN 500

void main()
{
	char buffer[BUFFER_LEN]; 												/* ���ڿ��� ���� 			*/
	char *pS1 = NULL; 														/* ù��° ���ڿ��� ������ 	*/
	char *pS2 = NULL; 														/* �ι�° ���ڿ��� ������ 	*/
	char *pS3 = NULL; 														/* ����° ���ڿ��� ������ 	*/
	char *pbuffer = buffer; 												/* buffer�� ������ 			*/

	printf("\n�޽����� �Է��ϼ���.\n"); 
	pS1 = pbuffer; 															/* ù��° �޽����� �ּҸ� ���� 			*/ 
	while ((*pbuffer++ = getchar()) != '\n'); 								/* ����Ű�� ���� ������ �Է��� �޾Ƶ���	*/
	*(pbuffer - 1) = '\0'; 													/* �ι��� �߰� 							*/ 
	printf("\n�ٸ� �޽����� �Է��ϼ���.\n");
	pS2 = pbuffer; 															/* ù��° �޽����� �ּҸ� ���� 			*/
	while ((*pbuffer++ = getchar()) != '\n');								/* ����Ű�� ���� ������ �Է��� �޾Ƶ���	*/
	*(pbuffer - 1) = '\0'; 													/* �ι��� �߰� 							*/
	printf("\n�ٸ� �޽����� �Է��ϼ���.\n");
	pS3 = pbuffer; 															/* ù��° �޽����� �ּҸ� ���� 			*/
	while((*pbuffer++ = getchar()) != '\n'); 								/* ����Ű�� ���� ������ �Է��� �޾Ƶ���	*/
	*(pbuffer - 1) = '\0'; 													/* �ι��� �߰� 							*/
	printf("\n�Է��Ͻ� ���ڿ��� ������ �����ϴ�.\n\n%s\n%s\n%s", pS1, pS2, pS3);
	printf("\n������� ���� ������ ũ��� %d�����Դϴ�.\n", 
					&buffer[BUFFER_LEN - 1] - pbuffer + 1); 
} 
