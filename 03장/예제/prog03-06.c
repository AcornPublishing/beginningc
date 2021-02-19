/* 프로그램 3.6 구매수량에 따라 여러 등급으로 할인율 나누기 */ 
#include <stdio.h> 

void main() 
{ 
	const double unit_price = 5000.0; 				/* 제품 하나당 가격 	   */ 
	const double discount1 = 0.05; 					/* 10개 이상 구매시 할인율 */ 
	const double discount2 = 0.1; 					/* 20개 이상 구매시 할인율 */ 
	const double discount3 = 0.15; 					/* 50개 이상 구매시 할인율 */ 
	double total_price = 0.0; 
	int quantity = 0; 

	printf("구입 수량을 입력하세요: "); 			/* 메시지 출력 			   */
	scanf("%d", &quantity); 						/* 입력값을 읽어들임 	   */

	total_price = quantity*unit_price*(1.0 -
					(quantity>=50 ? discount3 : (
						quantity>=20 ? discount2 : (
							quantity>=10 ? discount1 : 0.0))));

	printf("%d개를 구입하시면 %.0f원입니다.\n", quantity, total_price); 
} 
