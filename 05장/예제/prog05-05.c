/* 프로그램 5.5 & 연산자 */
#include<stdio.h>

void main()
{
	/* 정수형 변수 선언 */
	long a = 1L;
	long b = 2L;
	long c = 3L;

	/* 실수형 변수 선언 */
	double d = 4.0;
	double e = 5.0;
	double f = 6.0;

	printf("long형 변수는 %d바이트를 차지합니다.", sizeof(long));
	printf("\n다음은 long형 변수들의 주소입니다.");
	printf("\na의 주소는 %p이고, b의 주소는 %p이며,", &a, &b);
	printf("\nc의 주소는 %p입니다.", &c);
	printf("\n\ndouble형 변수는 %d바이트를 차지합니다.", sizeof(double));
	printf("\n다음은 double형 변수들의 주소입니다.");
	printf("\nd의 주소는 %p이고, e의 주소는 %p이며,", &d, &e);
	printf("\nf의 주소는 %p입니다.\n", &f);
}
