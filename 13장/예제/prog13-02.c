/* ���α׷� 13.2 assert() �ǽ� */
#undef NDEBUG 					/* assert()�� ����� �� �ְ� �� */
#include <stdio.h>
#include <assert.h>

void main()
{ 
	int x = 0; 
	int y = 5; 

	for(x = 0 ; x < 20 ; x++) 
	{ 
		printf("\nx = %d	y = %d", x, y); 
		assert(x<y); 
	} 
} 
