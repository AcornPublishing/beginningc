/* 프로그램 13.2 assert() 실습 */
#undef NDEBUG 					/* assert()를 사용할 수 있게 함 */
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
