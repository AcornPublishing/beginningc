/* ���α׷� 2.6 ��Ű�� ���̵� */
#include <stdio.h>

void main()
{
	int cookies = 45; 												/* �׸��� �ִ� ��Ű�� ���� 		 */ 
	int children = 7; 												/* ���̵��� �� 					 */ 
	int cookies_per_child = 0; 										/* ���� �� ���� ���� ��Ű�� ���� */ 
	int cookies_left_over = 0; 										/* ���� ��Ű�� ���� 			 */ 

	/* ��Ű�� ���� �����ָ� ���� �� ���� �� ���� ���ư����� ��� */ 
	cookies_per_child = cookies/children; 							/* ���� �� ���� �޴� ��Ű�� ���� */ 
	printf("%d���� ���̿� %d���� ��Ű�� �ֽ��ϴ�.", children, cookies); 
	printf("\n���� �� ���� ��Ű�� %d�� �ּ���.", cookies_per_child); 

	/* ��Ű�� �� �� ������ ��� */
	cookies_left_over = cookies%children; 
	printf("\n%d���� ��Ű�� ���ҽ��ϴ�.\n", cookies_left_over);
} 
