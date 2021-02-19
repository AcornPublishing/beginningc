/* 프로그램 10.1 형식이 있는 입력 실습 */ 
#include <stdio.h> 

void main() 
{ 
	int i = 0; 
	int j = 0; 
	int k = 0; 
	float fp1 = 0.0; 
	char word1[20] = " "; 
	char word2[20] = " "; 

	k = scanf("%f %d %d %[abcdefghijklmnopqrstuvwxyz] %*1d %s", 
						&fp1, &i , &j, word1, word2);
	printf("\n읽은 값의 개수 = %d\n", k);
	printf("\nfp1 = %f	i = %d	j = %d", fp1, i, j);
	printf("\nword1 = %s word2 = %s\n", word1, word2);
} 
