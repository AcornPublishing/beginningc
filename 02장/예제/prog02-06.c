/* 프로그램 2.6 쿠키와 아이들 */
#include <stdio.h>

void main()
{
	int cookies = 45; 												/* 그릇에 있는 쿠키의 개수 		 */ 
	int children = 7; 												/* 아이들의 수 					 */ 
	int cookies_per_child = 0; 										/* 아이 한 명이 받을 쿠키의 개수 */ 
	int cookies_left_over = 0; 										/* 남은 쿠키의 개수 			 */ 

	/* 쿠키를 골고루 나눠주면 아이 한 명에게 몇 개가 돌아가는지 계산 */ 
	cookies_per_child = cookies/children; 							/* 아이 한 명이 받는 쿠키의 개수 */ 
	printf("%d명의 아이와 %d개의 쿠키가 있습니다.", children, cookies); 
	printf("\n아이 한 명에게 쿠키를 %d개 주세요.", cookies_per_child); 

	/* 쿠키가 몇 개 남는지 계산 */
	cookies_left_over = cookies%children; 
	printf("\n%d개의 쿠키가 남았습니다.\n", cookies_left_over);
} 
