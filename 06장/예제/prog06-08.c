/* ���α׷� 6.8 ���ڿ��� �ִ� ���ڿ� �˻� */
#include <stdio.h>
#include <ctype.h>
void main()
{
	char buffer[80]; 										/* �Է� ���� 						*/ 
	int i = 0; 												/* ���� �ε��� 						*/ 
	int num_letters = 0; 									/* �Է� ���ڿ��� �ִ� ������ ���� 	*/ 
	int num_digits = 0; 									/* �Է� ���ڿ��� �ִ� ������ ���� 	*/ 

	printf("\n80���� �̸����� ���ϴ� ���ڿ��� �Է��ϼ���:\n"); 
	gets(buffer); 											/* ���ڿ��� ���ۿ� �о���� */ 

	while(buffer[i] != '\0') 		
	{ 			
		if(isalpha(buffer[i])) 		
			num_letters++; 									/* ���� ī���͸� ���� 	*/ 
		if(isdigit(buffer[i++])) 		
			num_digits++; 									/* ���� ī���͸� ����	*/ 
	} 			
	printf("\n���ڿ����� %d���� ���ڿ� %d���� ���ڰ� �ֽ��ϴ�.\n", 
		num_letters, num_digits); 
} 
