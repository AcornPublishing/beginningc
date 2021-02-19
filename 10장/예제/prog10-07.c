/* 프로그램 10.7 다양한 형식의 정수 출력 */ 
#include <stdio.h> 

void main() 
{ 
	int i = 15; 
	int j = 345; 
	int k = 4567; 
	long li = 56789L; 
	long lj = 678912L; 
	long lk = 23456789L; 

	printf("\ni = %d  j = %d   k = %d  i = %6.3d  j = %6.3d  k = %6.3d\n", 
					i ,j, k, i, j, k); 	
	printf("\ni = %-d  j = %+d  k = %-d  i = %-6.3d  j = %-6.3d  k = %-6.3d\n",i ,j, k, i, j, k); 	
	printf("\nli = %d  lj = %d  lk = %d\n", li, lj, lk); 	
	printf("\nli = %ld  lj = %ld  lk = %ld\n", li, lj, lk); 	
} 			
