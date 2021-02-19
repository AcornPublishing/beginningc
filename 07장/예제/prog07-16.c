/* 프로그램 7.16 개선된 계산기 */ 		
#include <stdio.h> 															/* 표준 입출력 라이브러리			*/
#include <string.h> 														/* 문자열 함수의 라이브러리			*/
#include <ctype.h> 															/* 문자열 구분을 위해 포함			*/ 
#include <stdlib.h> 														/* 문자열을 수로 변환하기 위해 포함	*/ 
#include <math.h>															/* power() 함수의 사용을 위해 포함	*/

void main() 		
{ 		
	char input[256]; 														/* 입력식							*/
	char number_string[30]; 												/* 입력값에서 숫자 문자열을 저장	*/ 
	char op = 0;															/* 연산자를 저장					*/
		
	unsigned int index = 0; 												/* 현재 입력받고 있는 문자의 인덱스 				*/
	unsigned int to = 0; 													/* 입력문자열을 자기자신에게 복사하기 위한 인덱스	*/
	size_t input_length = 0; 												/* 입력받은 문자열의 길이 							*/
	unsigned int number_length = 0; 										/* number_string의 문자열 길이 						*/ 
	double result = 0.0; 													/* 계산 결과 										*/ 
	double number = 0.0;													/* number_string의 값을 저장						*/

	printf("\n이 계산기에서 수식을 입력할 때는 스페이스를 눌러도 됩니다.");
	printf("\n수식에는 다음과 같은 연산자를 쓸 수 있습니다. ");
	printf("\n 						+, -, *, /, %%, ^(거듭제곱)");
	printf("\n이전 계산결과를 이용해 연산을 하고 싶으시면 수식 맨 앞에 =을 입력하세요.");
	printf("\n계산기를 닫고 싶으면 quit을 입력하세요.\n\n");

	/* 계산기의 메인 루프 */ 
	while(strcmp(gets(input), "quit") != 0) 
	{ 
		input_length = strlen(input); 										/* 입력 문자열의 길이를 알아냄 	*/ 

		/* 문자열 종료문자를 포함한 입력 문자열을 자기자신으로 복사해	*/ 
		/* 공백문자를 모두 제거한다. 									*/ 
		for(to = 0, index = 0 ; index<=input_length ; index++) 
			if(*(input+index) != ' ') 										/* 스페이스가 아니면	*/ 
				*(input+to++) = *(input+index); 							/* 문자를 복사 			*/ 

		input_length = strlen(input); 										/* 새로운 문자열 길이를 알아냄 	*/  
		index = 0; 															/* 첫번째 문자에서 시작 		*/ 

		if(input[index]== '=') 												/* 첫번째 문자가 =인가?			*/ 
			index++; 														/* =이면 그냥 넘어감			*/ 
		else 
		{ 																	/* =가 아니면 왼쪽 피연산자 검색	*/ 
			/* 첫번째 연산자의 왼쪽 피연산자에 해당하는 수를 검색 */

			/* 부호를 검사하고 복사함 */
			number_length = 0; 												/* 길이 초기화 		*/
			if(input[index]=='+' || input[index]=='-') 						/* +나 -인가? 		*/
				*(number_string+number_length++) = *(input+index++);		/* 그렇다면 복사함	*/

			/* 다음에 나오는 숫자를 모두 복사 */ 
			for( ; isdigit(*(input+index)) ; index++) 						/* 숫자인가? 		*/
				*(number_string+number_length++) = *(input+index); 			/* 그렇다면 복사함	*/

			/* 소수부가 있으면 복사함 */
			if(*(input+index)=='.') 										/* 소수점인가? 		*/
			{ 																/* 그렇다면 소수점과 그 뒤에 나오는 숫자를 복사 	*/
				*(number_string+number_length++) = *(input+index++); 		/* 소수점 복사 		*/ 

				for( ; isdigit(*(input+index)) ; index++) 					/* 숫자 복사 		*/ 
					*(number_string+number_length++) = *(input+index);
			}
			*(number_string+number_length) = '\0'; 							/* 문자열 종료문자 연결 */
			/* 왼쪽 피연산자가 있으면 number_string의 길이는 > 0이 된다. 이 경우에는	*/
			/* number_string을 double로 형변환해서 계산에 활용할 수 있게 한다.			*/
			if(number_length>0) 
				result = atof(number_string); 								/* 첫번째 수를 result에 저장	*/
		}

		/* '연산자-수' 조합을 검색 */
		for(;index < input_length;)
		{ 
			op = *(input+index++); 											/* 연산자를 가져옴	*/
			/* 다음 피연산자를 복사하고 number에 저장 */
			number_length = 0; 												/* 길이 초기화 		*/

			/* 부호를 검사한 뒤 복사 */
			if(input[index]=='+' || input[index]=='-') 						/* +나 -인가? 		*/ 
				*(number_string+number_length++) = *(input+index++); 		/* 그렇다면 복사	*/

			/* 다음에 나오는 숫자는 모두 복사 */
			for( ; isdigit(*(input+index)) ; index++) 						/* 각 숫자를		*/ 
				*(number_string+number_length++) = *(input+index); 			/* 복사함 			*/ 

			/* 소수점 이하 부분이 있으면 복사 */
			if(*(input+index)=='.') 										/* 소수점인가?		*/
			{ 																/* 소수점과 그 뒤에 나오는 숫자를 복사	*/
				*(number_string+number_length++) = *(input+index++); 		/* 소수점 복사		*/
				for( ; isdigit(*(input+index)) ; index++) 					/* 각 숫자를 		*/
					*(number_string+number_length++) = *(input+index); 		/* 복사함 			*/
			}
			*(number_string+number_length) = '\0'; 							/* 문자열 종료		*/ 

			/* double로 변환해 계산에서 사용할 수 있도록 함 */
			number = atof(number_string);

			/* 연산 'result op= number'를 실행 */
			switch(op)
			{ 
				case '+': 													/* 덧셈 	*/ 
					result += number; 
					break; 
				case '-': 													/* 뺄셈 	*/ 
					result -= number; 
					break; 
				case '*': 													/* 곱셈 	*/ 
					result *= number; 
					break; 
				case '/': 													/* 나눗셈	*/ 
					/* 두번째 피연산자가 0인지 검사 */ 
					if(number == 0)  
						printf("\n\n\a0으로 나누는 오류가 발생했습니다!\n"); 
					else 
						result /= number; 
					break; 
				case '%': 													/* 모듈러스 연산자 - 나머지	*/ 
					/* 두번째 피연산자가 0인지 검사 */ 
					if((long)number == 0) 
						printf("\n\n\a0으로 나누는 오류가 발생했습니다!\n");
					else
						result = (double)((long)result % (long)number);
						break; 
				case '^': 																									/* 거듭제곱	*/ 
					result = pow(result, number); 	
					break; 		
				default: 													/* 올바르지 않은 연산이나 틀린 입력값	*/ 
					printf("\n\n\a올바르지 않은 연산입니다!\n"); 
			} 
		} 
		printf("= %f\n", result); 											/* 결과 출력	*/ 
	}
} 
