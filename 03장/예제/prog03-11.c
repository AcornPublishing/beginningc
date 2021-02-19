/* 프로그램 3.11 계산기 */ 
#include <stdio.h> 

void main() 
{ 	
	double number1 = 0.0; 												/* 첫번째 피연산자의 값 : 10진수 			 */ 
	double number2 = 0.0; 												/* 두번째 피연산자의 값 : 10진수 			 */ 
	char operation = 0; 												/* 연산자 : +, -, *, /, % 가운데 하나여야 함 */ 

	printf("\n계산식을 입력하세요.\n"); 
	scanf("%lf %c %lf", &number1, &operation, &number2); 

	/* 입력값을 검사하는 코드 */ 
	switch(operation) 
	{ 
		case '+': 														/* 덧셈에서는 별도의 검사가 필요없음		 */  
			printf("= %lf\n", number1 + number2);
			break; 

		case '-': 														/* 뺄셈에서는 별도의 검사가 필요없음		 */ 
			printf("= %lf\n", number1 - number2);
			break; 

		case '*': 														/* 곱셈에서는 별도의 검사가 필요없음		 */ 
			printf("= %lf\n", number1 * number2);
			break;  

		case '/': 
			if(number2 == 0) 											/* 두번째 피연산자가 0인지 검사				 */ 
				printf("\n\n\a0으로 나누는 오류가 발생했습니다!\n"); 
			else
				printf("= %lf\n", number1 / number2);
			break;  

		case '%': 														/* 두번째 피연산자가 0인지 검사				 */ 
			if((long)number2 == 0) 
				printf("\n\n\a0으로 나누는 오류가 발생했습니다!\n"); 
			else
				printf("= %ld\n", (long)number1 % (long)number2);
			break; 

		default: 														/* 연산자가 올바르지 않을 경우 				 */ 
			printf("\n\n\a올바르지 않은 연산입니다!\n"); 
	} 
}
