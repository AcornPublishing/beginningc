/* 프로그램 10.4 16진수, 8진수 값 읽기 */ 
#include <stdio.h> 

void main() 
{ 
	int i = 0; 
	int j = 0; 
	int k = 0; 
	int n = 0; 

	n = scanf(" %d %x %o", &i , &j, &k );
	printf("\n%d개의 값을 읽었습니다.", n);
	printf("\ni = %d 	j = %d 	k = %d\n", i, j, k );
} 
