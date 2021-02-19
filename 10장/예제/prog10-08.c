/* 프로그램 10.8 하나의 정수를 여러 형식으로 */
#include <stdio.h>
void main()
{
	int k = 678; 

	printf("%%d  %%o   %%x  %%X"); 					/* 제목으로 형식문자열을 출력 */
	printf("\n%d %o %x %X", k, k, k, k ); 			/* 값을 출력 */

	/* 제목으로 형식문자열을 출력한 뒤 값을 출력 */ 
	printf("\n\n%%8d      %%-8d     %%+8d     %%08d     %%-+8d"); 
	printf("\n%8d %-8d %+8d %08d %-+8d\n", k, k, k,	k, k ); 
} 					
