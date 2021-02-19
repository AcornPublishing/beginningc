/* 프로그램 2.5 쿠키에 관한 계산 */ 
#include <stdio.h> 

void main() 
{ 	
	int cookies = 5; 
	int cookie_calories = 125; 									/* 쿠키 1개의 칼로리 		  */ 
	int total_eaten = 0; 										/* 먹은 쿠키의 전체 개수	  */ 

	int eaten = 2; 												/* 먹을 쿠키의 개수 		  */
	cookies = cookies - eaten; 									/* cookies에서 먹은 개수를 뺌 */
	total_eaten = total_eaten + eaten;
	printf("\n나는 쿠키를 %d개 먹었어요. 이제 %d개 남았어요.",
		eaten, cookies); 

	eaten = 3; 													/* 먹을 쿠키의 새로운 개수 	  */
	cookies = cookies - eaten; 									/* cookies에서 먹은 개수를 뺌 */
	total_eaten = total_eaten + eaten;
	printf("\n나는 쿠키를 %d개 더 먹었어요. 이제 %d개 남았어요.\n",
		eaten, cookies); 
	printf("\n지금까지 먹은 쿠키의 열량은 %d칼로리입니다.\n",
		total_eaten*cookie_calories); 
} 
