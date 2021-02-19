/* 프로그램 8.1 범위에 관한 짧은 프로그램 */
#include <stdio.h>

void main()
{
	int count1 = 1; 															/* 바깥쪽 블록에서 선언	*/ 

	do 
	{
		int count2 = 0; 														/* 안쪽 블록에서 선언 	*/
		++count2;
		printf("\ncount1 = %d 			count2 = %d", count1,count2);
	}
	while( ++count1 <= 8 ); 

 
	/* count2는 더이상 존재하지 않음 */ 

	printf("\ncount1 = %d\n", count1); 
} 
