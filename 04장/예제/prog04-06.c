/* 프로그램 4.6 50% 무한루프 - 평균 구하기 */
#include <stdio.h>
#include <ctype.h> 											/* tolower() 함수를 사용하기 위해	*/

void main()
{ 
	char answer = 'N'; 										/* 루프를 계속할 것인지에 관한 사용자의 의사*/ 
	double total = 0.0; 									/* 입력한 값의 합계 						*/ 
	double value = 0.0; 									/* 입력한 값 								*/ 
	int count = 0; 											/* 입력한 값의 개수 						*/ 

	printf("\n이 프로그램은 여러분이 아무리 많은 데이터를 입력해도 평균을 구해줍니다."); 

	for( ;; ) 												/* 무한루프 				*/ 
	{ 
		printf("\n값을 입력하세요: "); 						/* 값을 입력하라는 지시문 	*/ 
		scanf("%lf", &value); 								/* 값을 읽어들임 			*/ 
		total += value; 									/* value를 total에 더함 	*/ 
		++count; 											/* count의 값을 1 증가시킴	*/ 
			
		/* 값을 더 입력할 의사가 있는지 검사 */
		printf("값을 더 입력하시겠어요?(Y/N): ");
		scanf("%c", &answer ); 								/* Y나 N을 읽어들임 						*/
		if( tolower(answer) == 'n' ) 						/* 사용자가 그만 입력하기를 원하는지 검사	*/ 
			break; 											/* 루프를 빠져나감 							*/ 
	} 		
	/* 평균을 소수점 이하 2자리까지 출력 */ 
	printf ("\n입력하신 값의 평균은 %.2lf입니다.\n", total/count ); 
} 
