/* 프로그램 7.2 포인터의 정체 */ 
#include <stdio.h> 

void main() 
{ 
	long num1 = 0; 
	long num2 = 0; 
	long *pnum = NULL; 

	pnum = &num1; 											/* num1의 주소를 가져옴	*/
	*pnum = 2; 												/* num1의 값을 2로 설정	*/
	++num2; 												/* num2를 1 증가 		*/
	num2 += *pnum; 											/* num2에 num1을 더함 	*/

	pnum = &num2; 											/* num2의 주소를 가져옴				*/
	++*pnum; 												/* num2의 값을 간접적으로 증가시킴	*/ 

	printf ("\nnum1 = %ld   num2 = %ld   *pnum = %ld   *pnum + num2 = %ld\n", 
					num1, num2, *pnum, *pnum + num2); 
} 

