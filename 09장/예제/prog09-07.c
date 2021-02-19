/* ���α׷� 9.7 �������� ����� �̿��� ��� ����ϱ� */
#include <stdio.h>
#include <stdarg.h>

double average(double v1 , double v2,...);								/* �Լ����� */


 
void main() 
{ 
	double Val1 = 10.5, Val2 = 2.5; 
	int num1 = 6, num2 = 5; 
	long num3 = 12, num4 = 20; 

	printf("\n��� = %lf",	 average(Val1, 3.5, Val2, 4.5, 0.0));
	printf("\n��� = %lf",	 average(1.0, 2.0, 0.0));
	printf("\n��� = %lf\n", average((double)num2, Val2,(double)num1,
							    (double)num4,(double)num3, 0.0)); 
} 

/* �������� ���� ������ ������ ����� ����ϴ� �Լ� */
double average( double v1, double v2,...)
{
	va_list parg; 														/* �������� ����� ������	*/ 
	double sum = v1+v2; 												/* ������ �հ� 				*/ 
	double value = 0; 													/* ������ �� 				*/ 
	int count = 2; 														/* ������ ����				*/ 

	va_start(parg,v2); 													/* ���� ������ �ʱ�ȭ 		*/ 

	while((value = va_arg(parg, double)) != 0.0) 
	{
		sum += value;
		count++;
	}
	va_end(parg); 														/* �������� ���� ����		*/
	return sum/count;
} 
