/* ���α׷� 6.2 ���ڿ��� ���� */
#include <stdio.h>

void main()
{
	char str1[40] = "To be or not to be";
	char str2[40] = ",�װ��� �����δ�";
	int count = 0; 													/* ���ڿ��� ���̸� ������ ���� 			*/
	while (str1[count] != '\0') 									/* ���ڿ� ���Ṯ�ڰ� ��Ÿ�� ������ 		*/
		count++; 													/* count�� 1�� ������Ų��. 				*/ 
	printf("\n���ڿ� \"%s\"�� ���̴� %d�����Դϴ�.", str1, count);
	count = 0; 														/* 0���� �ʱ�ȭ�� ���� ���ڿ��� �غ���	*/ 

	while (str2[count] != '\0') 									/* �ι�° ���ڿ����� ������ ���� ��� 	*/ 
		count++; 		
	printf("\n���ڿ� \"%s\"�� ���̴� %d�����Դϴ�.\n", str2, count); 
} 
