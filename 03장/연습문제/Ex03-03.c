/* 연습문제 3.3 할인된 가격 계산 */
#include <stdio.h>

void main()
{
  	const int level1 = 30;           /* 30개 초과 구매분의 할인율은 discount1 */
	const int level2 = 50;           /* 50개 초과 구매분의 할인율은 discount2 */
	const double discount1 = 0.10;   /* 10% 할인 */
	const double discount2 = 0.15;   /* 15% 할인 */
	const double unit_price = 5000.;
	int quantity = 0;
	int qty_over_level1 = 0;
	int qty_over_level2 = 0;
	printf("원하는 수량을 입력하세요: ");
	scanf("%d", &quantity);

	if(quantity > level1)							/* 구매수량이 30개 이상이면 */
	{
		qty_over_level1 = quantity - level1;		/* 30개를 초과하는 수량 계산 */

		if(quantity > level2)						/* 구매수량이 50개 이상이면 */
		{
	  		qty_over_level2 = quantity - level2;	/* 50개를 초과하는 수량 계산 */
			qty_over_level1 = level2 - level1;		/* 이때 qty_over_level1은 자동으로 20개가 됨*/
		}
	}

	printf("\n%d개를 구입하시면 모두%.0lf원입니다.\n", quantity,
		unit_price*(quantity - discount1*qty_over_level1 - discount2*qty_over_level2));
}
