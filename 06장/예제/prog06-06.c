/* ���α׷� 6.6 ���ڿ� �� */
#include <stdio.h>
#include <string.h>
void main() 
{ 
	char word1[20]; 													/* ù��° �ܾ ������ ���ڿ� */ 
	char word2[20]; 													/* �ι�° �ܾ ������ ���ڿ� */ 

	printf("\nù��° �ܾ �Է��ϼ���.\n1: ");
	scanf("%s", word1); 												/* ù��° �ܾ �Է¹��� */
	printf("�ι�° �ܾ �Է��ϼ���.\n2: "); 
	scanf("%s", word2); 												/* �ι�° �ܾ �Է¹��� */

	/* �� �ܾ ���� */
	if(strcmp(word1,word2) == 0)
		printf("�Ȱ��� �ܾ �ι� �Է��ϼ̽��ϴ�.\n");
	else
		printf("%s��(��) %s���� �ռ��ϴ�.\n", 
			(strcmp(word1, word2) < 0) ? word1 : word2, 
			(strcmp(word1, word2) < 0) ? word2 : word1); 
} 

