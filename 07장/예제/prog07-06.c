/* ���α׷� 7.6 �پ��� ���������� �迭 */ 
#include <stdio.h> 

void main() 
{ 
	long multiple[] = {1L, 2L, 3L}; 

	printf("ù��° ����� �ּҴ� %p�̰�, �� ���� %d�Դϴ�.\n", 
					multiple, *multiple); 
	printf("�ι�° ����� �ּҴ� %p�̰�, �� ���� %d�Դϴ�.\n", 
					multiple + 1, *(multiple + 1)); 
	printf("����° ����� �ּҴ� %p�̰�, �� ���� %d�Դϴ�.\n", 
					multiple + 2, *(multiple + 2)); 
	printf("    long���� %d����Ʈ�� �����մϴ�.\n", sizeof(long)); 
} 
