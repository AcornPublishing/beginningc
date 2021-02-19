/* 프로그램 11.7 공용체의 동작방식 */ 
#include <stdio.h> 

void main() 
{ 
	union u_example 
	{ 
		float decval;
		int pnum;
		double my_value;
	} U1;

	U1.my_value = 125.5;
	U1.pnum = 10;
	U1.decval = 1000.5f;

	printf("\ndecval = %f pnum = %d my_value = %lf", 
			U1.decval, U1.pnum, U1.my_value ); 

	printf("\nU1의 크기 = %d\ndecval의 크기 = %d pnum의 크기 = %d "
			"my_value의 크기 = %d", sizeof U1, sizeof U1.decval, 
			sizeof U1.pnum, sizeof U1.my_value); 
} 
