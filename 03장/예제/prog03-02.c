/* 프로그램 3.2 if문을 이용해 할인 여부 결정하기 */ 
#include <stdio.h> 

void main() 
{ 
	const double unit_price = 5000.0; 								/* 제품 1개당 가격(원) */ 
	int quantity = 0; 
	printf("구입 수량을 입력하세요: "); 							/* 메시지 출력		   */ 
	scanf("%d", &quantity); 										/* 입력값을 읽어들임   */ 

	/* 주문 수량이 할인 대상에 해당하는지 검사 */ 
	if(quantity > 10) 												/* 5% 할인			   */ 
		printf("%d개를 구매하시면 %.0f원입니다.\n", quantity, quantity*unit_price*0.95); 
	else 															/* 할인 없음 		   */ 
		printf("%d개를 구매하시면 %.0f원입니다.\n", quantity, quantity*unit_price); 
} 
