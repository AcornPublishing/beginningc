/* 프로그램 2.16 데이터형의 크기 알아내기 */ 
#include <stdio.h> 

void main() 
{
	printf("\nchar형 변수는 %d바이트를 차지합니다.", sizeof(char)); 
	printf("\nshort형 변수는 %d바이트를 차지합니다.", sizeof(short)); 
	printf("\nint형 변수는 %d바이트를 차지합니다.", sizeof(int)); 
	printf("\nlong형 변수는 %d바이트를 차지합니다.", sizeof(long)); 
	printf("\nfloat형 변수는 %d바이트를 차지합니다.", sizeof(float)); 
	printf("\ndouble형 변수는 %d바이트를 차지합니다.", sizeof(double)); 
	printf("\nlong double형 변수는 %d바이트를 차지합니다.", sizeof(long double)); 
} 
