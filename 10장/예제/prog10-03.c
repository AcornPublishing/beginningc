/* 프로그램 10.3 실수 입력 */ 
#include <stdio.h> 

void main() 
{ 
	float fp1 = 0.0f; 
	float fp2 = 0.0f; 
	float fp3 = 0.0f; 
	int k = 0; 

	k = scanf("%f %f %f", &fp1, &fp2, &fp3); 
	printf("\n반환값 = %d", k); 
	printf("\nfp1 = %f	fp2 = %f	fp3 = %f\n", fp1, fp2, fp3); 
} 
