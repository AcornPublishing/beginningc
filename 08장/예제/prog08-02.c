//* ���α׷� 8.2 ������ ���� ���� �� */
#include <stdio.h>
void main()
{
	int count = 0; 										/* �ٱ��� ��Ͽ��� ���� 			*/
	do
	{
		int count = 0; 									/* ���� �̸��� �Ǵٸ� ���� 			*/ 
		++count; 										/* �� ������ ���� count�� ����� 	*/ 
		printf("\ncount = %d ", count); 
	}
	while( ++count <= 8 ); 								/* �� ǥ������ �ٱ��� count�� �����*/

	/* ���� count�� �Ҹ��. ���⼭ count�� �ٱ��� count */ 
	printf("\ncount = %d\n", count); 
} 
