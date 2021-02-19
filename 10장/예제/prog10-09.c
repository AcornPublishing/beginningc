/* 프로그램 10.9 실수 출력 */ 
#include <stdio.h> 

void main() 
{ 
	float fp1 = 345.678f; 
 
	float fp2 = 1.234E6f;
	double fp3 = 234567898.0;
	double fp4 = 11.22334455e-6;

	printf("\n%f %+f %-10.4f %6.4f\n", fp1, fp2, fp1, fp2);
	printf("\n%e %+E\n", fp1, fp2);
	printf("\n%f %g %#+f %8.4f %10.4g\n", fp3,fp3, fp3, fp3, fp4);
} 
