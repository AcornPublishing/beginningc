/* ���α׷� 11.7 ����ü�� ���۹�� */ 
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

	printf("\nU1�� ũ�� = %d\ndecval�� ũ�� = %d pnum�� ũ�� = %d "
			"my_value�� ũ�� = %d", sizeof U1, sizeof U1.decval, 
			sizeof U1.pnum, sizeof U1.my_value); 
} 
