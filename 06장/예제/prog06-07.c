/* ���α׷� 6.7 ���ڿ� �˻� �ǽ� */
#include <stdio.h>
#include <string.h>
void main()
{
	char str1[] = "This string contains the holy grail.";
	char str2[] = "the holy grail";
	char str3[] = "the holy grill";

	/* str1���� str2�� �˻� */
	if(strstr(str1, str2) == NULL)
		printf("\n\"%s\"�� ã�� ���߽��ϴ�.", str2);
	else
		printf("\n\"%s\"�� \"%s\"���� ã�ҽ��ϴ�.",str2, str1);

	/* str1���� str3�� �˻� */ 
	if(strstr(str1, str3) == NULL) 
		printf("\n\"%s\"�� ã�� ���߽��ϴ�.", str3); 
	else 
		printf("\n�� �޽����� ���̸� �� �Ǵµ�, ���� �߸��Ʊ���!"); 
} 
