/* ���α׷� 6.9 �ϳ��� ���ڿ����� �κй��ڿ� �˻��ϱ� */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{ 
	char text[100]; 										/* �˻��� ���ڿ��� �о���� �Է� ����	*/ 
	char substring[40]; 									/* ã�� ���ڿ��� �о���� �Է� ���� 	*/ 
	int i = 0; 												/* ���ڿ��� �ִ� ������ �ε��� 			*/ 

	printf("\n�˻��� ���ڿ��� 100�� �̳��� �Է��ϼ���:\n");
	gets(text);
	printf("\nã�� ���ڿ��� 40�� �̳��� �Է��ϼ���:\n");
	gets(substring);

	/* �� ���ڿ��� ��� �빮�ڷ� ��ȯ */
	for(i = 0 ; (text[i] = toupper(text[i])) != '\0' ; i++);
	for(i = 0 ; (substring[i] = toupper(substring[i])) != '\0' ; i++);
	printf("\nã���� �ϴ� ���ڿ��� �˻� ��� ���ڿ����� ã%s���ϴ�.", 
		((strstr(text, substring) == NULL) ? "�� ����" : "��")); 
} 
