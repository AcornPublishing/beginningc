/* Program 6.5 ���ڿ� ���� - ��2ź */
#include <stdio.h>
#include <string.h>
#define STR_LENGTH 40

void main()
{
	char str1[STR_LENGTH] = "����� �״���"; 
	char str2[STR_LENGTH] = ",�װ��� �����δ�"; 

	if(STR_LENGTH > strlen(str1) + strlen(str2)) 		/* ������ ����Ѱ� ? 					*/ 
		printf("\n%s\n", strcat(str1, str2)); 			/* ����ϹǷ� ���ڿ��� �����ϰ� ����� 	*/ 
	else 
		printf("\n��׸��� �� �Ѹ��� ���� ���� ���� �븩����."); 
} 
