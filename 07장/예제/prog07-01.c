/* ���α׷� 7.1 �����͸� �̿��� ������ ���α׷� */ 
#include <stdio.h> 

void main() 
{ 	
	int number = 0; 										/* 0���� �ʱ�ȭ�� int�� ���� 			*/ 
	int *pointer = NULL; 									/* int�� ������ ����ų �� �ִ� ������	*/ 

	number = 10; 
	printf("\nnumber�� �ּ�: %p", &number); 				/* �ּ� ���*/
	printf("\nnumber�� ��: %d\n\n", number); 				/* �� ��� 	*/

	pointer = &number; 										/* pointer�� number�� �ּҸ� ����	*/

	printf("pointer�� �ּ�: %p", &pointer); 				/* �ּҸ� ��� 		*/
	printf("\npointer�� ũ��: %d����Ʈ", sizeof(pointer)); 	/* ũ�⸦ ��� 		*/
	printf("\npointer�� ��: %p", pointer); 					/* ��(�ּ�)�� ���	*/
	printf("\npointer�� ����Ű�� �ִ� ��: %d\n", *pointer); /* �ּҿ� �ִ� ��	*/ 
}
