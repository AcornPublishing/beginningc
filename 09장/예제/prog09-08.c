/* ���α׷� 9.8 ����� ���ڸ� �޾Ƶ��̴� ���α׷� */
#include <stdio.h>
void main(int argc, char *argv[])
{
	int i = 0; 
	printf("���α׷� �̸�: %s\n", argv[0]); 
	for(i = 1 ; i<argc ; i++) 
		printf("\n���� %d: %s", i, argv[i]); 
} 
