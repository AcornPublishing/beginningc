/* 프로그램 10.2 형식제어문자열에 포함된 문자 */ 
#include <stdio.h> 

void main() 
{ 
	int i = 0; 
	int j = 0; 
	int k = 0; 
	float fp1 = 0.0; 

	k = scanf("fp1 = %f i = %d %d", &fp1, &i , &j);
	printf("\n읽은 값의 개수 = %d", k);
	printf("\nfp1 = %f\ti = %d\tj = %d\n", fp1, i, j);
} 
