/* ���α׷� 2.7 float�� ���� �̿��� ������ */ 
#include <stdio.h> 

void main() 
{ 
	float plank_length = 10.0f; 					/* ������ ���� 				*/ 
	float piece_count = 4.0f; 						/* ���ڸ� ����� ���� ��	*/ 
	float piece_length = 0.0f; 						/* ����� ������ ���� 		*/ 

	piece_length = plank_length/piece_count; 
	printf("%f����¥�� ���ڸ� %f�������� ����ϸ� %f���Ͱ� �˴ϴ�.",
		plank_length, piece_count, piece_length); 
} 

