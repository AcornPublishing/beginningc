/* ���α׷� 8.1 ������ ���� ª�� ���α׷� */
#include <stdio.h>

void main()
{
	int count1 = 1; 															/* �ٱ��� ��Ͽ��� ����	*/ 

	do 
	{
		int count2 = 0; 														/* ���� ��Ͽ��� ���� 	*/
		++count2;
		printf("\ncount1 = %d 			count2 = %d", count1,count2);
	}
	while( ++count1 <= 8 ); 

 
	/* count2�� ���̻� �������� ���� */ 

	printf("\ncount1 = %d\n", count1); 
} 
