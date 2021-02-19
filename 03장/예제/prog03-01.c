/* 프로그램 3.1 간단한 if문 예제 */ 
#include <stdio.h> 

void main() 
{ 
	int number = 0; 
	printf("\n1부터 10 사이의 정수를 입력하세요: "); 
	scanf("%d",&number); 

	if (number > 5)
		printf("5보다 큰 수인 %d을(를) 입력하셨습니다.\n", number);

	if (number < 6) 
		printf("6보다 작은 수인 %d을(를) 입력하셨습니다.\n", number); 
} 
