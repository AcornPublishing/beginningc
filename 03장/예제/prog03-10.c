/* ���α׷� 3.10 ��Ʈ������ �ǽ� */ 
#include <stdio.h> 

void main() 
{ 
	unsigned int original = 0xABC; 
	unsigned int result = 0; 
	unsigned int mask = 0xF; 					/* �� ������ 4�� ��Ʈ 	*/ 

	printf("\noriginal = %X", original); 

	/* result�� ù��° ���ڸ� ��� */
	result |= original&mask; 					/* original�� ������ 4�� ��Ʈ�� result�� ���� */

	/* �ι�° ���ڸ� ��� */
	original >>= 4; 							/* original�� ���������� 4ĭ �̵� 			  */
	result <<= 4; 								/* ���� ���ڰ� �� ������ ���� 			  */
	result |= original&mask; 					/* original�� ������ 4�� ��Ʈ�� result�� ���� */

	/* ����° ���ڸ� ��� */
	original >>= 4; 							/* original�� ���������� 4ĭ �̵� 			  */
	result <<= 4; 								/* ���� ���ڰ� �� ������ ���� 			  */
	result |= original&mask; 					/* original�� ������ 4�� ��Ʈ�� result�� ���� */
	printf("\t result = %X\n", result);
} 
