/* ���α׷� 3.11 ���� */ 
#include <stdio.h> 

void main() 
{ 	
	double number1 = 0.0; 												/* ù��° �ǿ������� �� : 10���� 			 */ 
	double number2 = 0.0; 												/* �ι�° �ǿ������� �� : 10���� 			 */ 
	char operation = 0; 												/* ������ : +, -, *, /, % ��� �ϳ����� �� */ 

	printf("\n������ �Է��ϼ���.\n"); 
	scanf("%lf %c %lf", &number1, &operation, &number2); 

	/* �Է°��� �˻��ϴ� �ڵ� */ 
	switch(operation) 
	{ 
		case '+': 														/* ���������� ������ �˻簡 �ʿ����		 */  
			printf("= %lf\n", number1 + number2);
			break; 

		case '-': 														/* ���������� ������ �˻簡 �ʿ����		 */ 
			printf("= %lf\n", number1 - number2);
			break; 

		case '*': 														/* ���������� ������ �˻簡 �ʿ����		 */ 
			printf("= %lf\n", number1 * number2);
			break;  

		case '/': 
			if(number2 == 0) 											/* �ι�° �ǿ����ڰ� 0���� �˻�				 */ 
				printf("\n\n\a0���� ������ ������ �߻��߽��ϴ�!\n"); 
			else
				printf("= %lf\n", number1 / number2);
			break;  

		case '%': 														/* �ι�° �ǿ����ڰ� 0���� �˻�				 */ 
			if((long)number2 == 0) 
				printf("\n\n\a0���� ������ ������ �߻��߽��ϴ�!\n"); 
			else
				printf("= %ld\n", (long)number1 % (long)number2);
			break; 

		default: 														/* �����ڰ� �ùٸ��� ���� ��� 				 */ 
			printf("\n\n\a�ùٸ��� ���� �����Դϴ�!\n"); 
	} 
}
