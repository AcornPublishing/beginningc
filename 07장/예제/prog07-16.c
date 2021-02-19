/* ���α׷� 7.16 ������ ���� */ 		
#include <stdio.h> 															/* ǥ�� ����� ���̺귯��			*/
#include <string.h> 														/* ���ڿ� �Լ��� ���̺귯��			*/
#include <ctype.h> 															/* ���ڿ� ������ ���� ����			*/ 
#include <stdlib.h> 														/* ���ڿ��� ���� ��ȯ�ϱ� ���� ����	*/ 
#include <math.h>															/* power() �Լ��� ����� ���� ����	*/

void main() 		
{ 		
	char input[256]; 														/* �Է½�							*/
	char number_string[30]; 												/* �Է°����� ���� ���ڿ��� ����	*/ 
	char op = 0;															/* �����ڸ� ����					*/
		
	unsigned int index = 0; 												/* ���� �Է¹ް� �ִ� ������ �ε��� 				*/
	unsigned int to = 0; 													/* �Է¹��ڿ��� �ڱ��ڽſ��� �����ϱ� ���� �ε���	*/
	size_t input_length = 0; 												/* �Է¹��� ���ڿ��� ���� 							*/
	unsigned int number_length = 0; 										/* number_string�� ���ڿ� ���� 						*/ 
	double result = 0.0; 													/* ��� ��� 										*/ 
	double number = 0.0;													/* number_string�� ���� ����						*/

	printf("\n�� ���⿡�� ������ �Է��� ���� �����̽��� ������ �˴ϴ�.");
	printf("\n���Ŀ��� ������ ���� �����ڸ� �� �� �ֽ��ϴ�. ");
	printf("\n 						+, -, *, /, %%, ^(�ŵ�����)");
	printf("\n���� ������� �̿��� ������ �ϰ� �����ø� ���� �� �տ� =�� �Է��ϼ���.");
	printf("\n���⸦ �ݰ� ������ quit�� �Է��ϼ���.\n\n");

	/* ������ ���� ���� */ 
	while(strcmp(gets(input), "quit") != 0) 
	{ 
		input_length = strlen(input); 										/* �Է� ���ڿ��� ���̸� �˾Ƴ� 	*/ 

		/* ���ڿ� ���Ṯ�ڸ� ������ �Է� ���ڿ��� �ڱ��ڽ����� ������	*/ 
		/* ���鹮�ڸ� ��� �����Ѵ�. 									*/ 
		for(to = 0, index = 0 ; index<=input_length ; index++) 
			if(*(input+index) != ' ') 										/* �����̽��� �ƴϸ�	*/ 
				*(input+to++) = *(input+index); 							/* ���ڸ� ���� 			*/ 

		input_length = strlen(input); 										/* ���ο� ���ڿ� ���̸� �˾Ƴ� 	*/  
		index = 0; 															/* ù��° ���ڿ��� ���� 		*/ 

		if(input[index]== '=') 												/* ù��° ���ڰ� =�ΰ�?			*/ 
			index++; 														/* =�̸� �׳� �Ѿ			*/ 
		else 
		{ 																	/* =�� �ƴϸ� ���� �ǿ����� �˻�	*/ 
			/* ù��° �������� ���� �ǿ����ڿ� �ش��ϴ� ���� �˻� */

			/* ��ȣ�� �˻��ϰ� ������ */
			number_length = 0; 												/* ���� �ʱ�ȭ 		*/
			if(input[index]=='+' || input[index]=='-') 						/* +�� -�ΰ�? 		*/
				*(number_string+number_length++) = *(input+index++);		/* �׷��ٸ� ������	*/

			/* ������ ������ ���ڸ� ��� ���� */ 
			for( ; isdigit(*(input+index)) ; index++) 						/* �����ΰ�? 		*/
				*(number_string+number_length++) = *(input+index); 			/* �׷��ٸ� ������	*/

			/* �Ҽ��ΰ� ������ ������ */
			if(*(input+index)=='.') 										/* �Ҽ����ΰ�? 		*/
			{ 																/* �׷��ٸ� �Ҽ����� �� �ڿ� ������ ���ڸ� ���� 	*/
				*(number_string+number_length++) = *(input+index++); 		/* �Ҽ��� ���� 		*/ 

				for( ; isdigit(*(input+index)) ; index++) 					/* ���� ���� 		*/ 
					*(number_string+number_length++) = *(input+index);
			}
			*(number_string+number_length) = '\0'; 							/* ���ڿ� ���Ṯ�� ���� */
			/* ���� �ǿ����ڰ� ������ number_string�� ���̴� > 0�� �ȴ�. �� ��쿡��	*/
			/* number_string�� double�� ����ȯ�ؼ� ��꿡 Ȱ���� �� �ְ� �Ѵ�.			*/
			if(number_length>0) 
				result = atof(number_string); 								/* ù��° ���� result�� ����	*/
		}

		/* '������-��' ������ �˻� */
		for(;index < input_length;)
		{ 
			op = *(input+index++); 											/* �����ڸ� ������	*/
			/* ���� �ǿ����ڸ� �����ϰ� number�� ���� */
			number_length = 0; 												/* ���� �ʱ�ȭ 		*/

			/* ��ȣ�� �˻��� �� ���� */
			if(input[index]=='+' || input[index]=='-') 						/* +�� -�ΰ�? 		*/ 
				*(number_string+number_length++) = *(input+index++); 		/* �׷��ٸ� ����	*/

			/* ������ ������ ���ڴ� ��� ���� */
			for( ; isdigit(*(input+index)) ; index++) 						/* �� ���ڸ�		*/ 
				*(number_string+number_length++) = *(input+index); 			/* ������ 			*/ 

			/* �Ҽ��� ���� �κ��� ������ ���� */
			if(*(input+index)=='.') 										/* �Ҽ����ΰ�?		*/
			{ 																/* �Ҽ����� �� �ڿ� ������ ���ڸ� ����	*/
				*(number_string+number_length++) = *(input+index++); 		/* �Ҽ��� ����		*/
				for( ; isdigit(*(input+index)) ; index++) 					/* �� ���ڸ� 		*/
					*(number_string+number_length++) = *(input+index); 		/* ������ 			*/
			}
			*(number_string+number_length) = '\0'; 							/* ���ڿ� ����		*/ 

			/* double�� ��ȯ�� ��꿡�� ����� �� �ֵ��� �� */
			number = atof(number_string);

			/* ���� 'result op= number'�� ���� */
			switch(op)
			{ 
				case '+': 													/* ���� 	*/ 
					result += number; 
					break; 
				case '-': 													/* ���� 	*/ 
					result -= number; 
					break; 
				case '*': 													/* ���� 	*/ 
					result *= number; 
					break; 
				case '/': 													/* ������	*/ 
					/* �ι�° �ǿ����ڰ� 0���� �˻� */ 
					if(number == 0)  
						printf("\n\n\a0���� ������ ������ �߻��߽��ϴ�!\n"); 
					else 
						result /= number; 
					break; 
				case '%': 													/* ��ⷯ�� ������ - ������	*/ 
					/* �ι�° �ǿ����ڰ� 0���� �˻� */ 
					if((long)number == 0) 
						printf("\n\n\a0���� ������ ������ �߻��߽��ϴ�!\n");
					else
						result = (double)((long)result % (long)number);
						break; 
				case '^': 																									/* �ŵ�����	*/ 
					result = pow(result, number); 	
					break; 		
				default: 													/* �ùٸ��� ���� �����̳� Ʋ�� �Է°�	*/ 
					printf("\n\n\a�ùٸ��� ���� �����Դϴ�!\n"); 
			} 
		} 
		printf("= %f\n", result); 											/* ��� ���	*/ 
	}
} 
