/* ���α׷� 2.14 char���� �̿��� ������� */ 
#include <stdio.h> 

void main() 
{ 
	char first = 'A'; 
	char second = 'B'; 
	char last = 'Z'; 
	char number = 40; 

	char ex1 = first + 2; 					/* 'A'�� 2�� ����	*/
	char ex2 = second - 1; 					/* 'B'���� 1�� �� 	*/
	char ex3 = last + 2; 					/* 'Z'�� 2�� ���� 	*/ 

	printf("������ ��           	%-5c%-5c%-5c", ex1, ex2, ex3); 
	printf("\n���ڿ� �ش��ϴ� ��	%-5d%-5d%-5d", ex1, ex2, ex3); 
	printf("\n%d�� ���� %c�� �����ڵ��Դϴ�.\n", number, number); 
} 
