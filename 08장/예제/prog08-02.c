//* 프로그램 8.2 범위에 관해 조금 더 */
#include <stdio.h>
void main()
{
	int count = 0; 										/* 바깥쪽 블록에서 선언 			*/
	do
	{
		int count = 0; 									/* 같은 이름의 또다른 변수 			*/ 
		++count; 										/* 이 문장은 안쪽 count에 적용됨 	*/ 
		printf("\ncount = %d ", count); 
	}
	while( ++count <= 8 ); 								/* 이 표현식은 바깥쪽 count에 적용됨*/

	/* 안쪽 count는 소멸됨. 여기서 count는 바깥쪽 count */ 
	printf("\ncount = %d\n", count); 
} 
