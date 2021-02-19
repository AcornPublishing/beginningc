/* 프로그램 9.7 가변인자 목록을 이용해 평균 계산하기 */
#include <stdio.h>
#include <stdarg.h>

double average(double v1 , double v2,...);								/* 함수원형 */


 
void main() 
{ 
	double Val1 = 10.5, Val2 = 2.5; 
	int num1 = 6, num2 = 5; 
	long num3 = 12, num4 = 20; 

	printf("\n평균 = %lf",	 average(Val1, 3.5, Val2, 4.5, 0.0));
	printf("\n평균 = %lf",	 average(1.0, 2.0, 0.0));
	printf("\n평균 = %lf\n", average((double)num2, Val2,(double)num1,
							    (double)num4,(double)num3, 0.0)); 
} 

/* 정해지지 않은 개수의 인자의 평균을 계산하는 함수 */
double average( double v1, double v2,...)
{
	va_list parg; 														/* 가변인자 목록의 포인터	*/ 
	double sum = v1+v2; 												/* 인자의 합계 				*/ 
	double value = 0; 													/* 인자의 값 				*/ 
	int count = 2; 														/* 인자의 개수				*/ 

	va_start(parg,v2); 													/* 인자 포인터 초기화 		*/ 

	while((value = va_arg(parg, double)) != 0.0) 
	{
		sum += value;
		count++;
	}
	va_end(parg); 														/* 가변인자 과정 종료		*/
	return sum/count;
} 
