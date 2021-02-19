/* 프로그램 7.5B 배열과 포인터 2탄 */
#include <stdio.h>

void main()
{
	char multiple[] = "another string";
	printf("첫번째 요소 : %p\n", multiple); 
	printf("두번째 요소 : %p\n", multiple + 1);
	printf("세번째 요소 : %p\n", multiple + 2);
} 
