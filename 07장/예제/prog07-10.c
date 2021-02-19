/* 프로그램 7.10 모자치수 프로그램으로 포인터를 이해하자 */
#include <stdio.h>
#define TRUE 1
#define FALSE 0

void main()
{
	char size[3][12] = { 							/* 모자치수를 구성하는 문자	*/
		{'6', '6', '6', '6', '7', '7', '7', '7', '7', '7', '7', '7'},
		{'1', '5', '3', '7', ' ', '1', '1', '3', '1', '5', '3', '7'},
		{'2', '8', '4', '8', ' ', '8', '4', '8', '2', '8', '4', '8'}
	}; 

	int headsize[12] = 											/* 1/8인치 단위의 값 				*/
		{164,166,169,172,175,178,181,184,188,191,194,197};

	float cranium = 0.0; 										/* 10진수의 인치 단위로 잰 머리둘레	*/
	int your_head = 0; 											/* 1/8인치 단위의 머리 치수(정수) 	*/
	int i = 0; 													/* 루프 카운터 						*/
 
	int hat_found = FALSE; 										/* 맞는 모자를 발견했음을 알림 		*/
	int too_small = FALSE; 										/* 머리의 치수가 너무 작음을 알림 	*/

	/* 머리둘레를 입력 */
	printf("\n눈썹 바로 위에서 잰 인치 단위의 머리둘레를 "
		"십진수로 입력하세요: "); 
	scanf(" %f", &cranium); 
	/* 1/8인치 단위의 정수로 변환 */ 
	your_head = (int)(8.0*cranium); 
	/* headsize 검색 */ 
	for (i = 0 ; i < 12 ; i++) 
	{ 
		/* 배열 headsize에서 머리둘레 검색 */ 
		if(your_head > *(headsize+i))
			continue;

		/* 입력한 머리둘레가 headsize의 첫번째 요소보다 */ 
		/* 1/8인치 이상 작을 경우, 머리가 너무 작아		*/ 
		/* 맞는 모자가 없다고 판단한다. 				*/ 
		if((i == 0) && (your_head < (*headsize)-1))
		{
			printf("\n혹시 CD로 얼굴을 가릴 수 있다는 전설 속의 인물이신가요? "
				"안됐지만 맞는 모자가 없습니다.\n");
			too_small = TRUE;
			break; 												/* 루프 빠져나옴 */
		}

		/* 머리둘레가 headsize 배열의 현재 요소 값보다 			*/
		/* 1/8인치 이상 작을 경우 한칸 앞에 있는 요소의 값을	*/
		/* 모자치수로 결정한다 									*/
		if( your_head < *(headsize+i)-1 ) 
			i--; 

		printf("\n당신의 모자치수는 %c %c%c%c입니다.\n", 
			*(*size + i), *(size[1] + i), 
			(i==4)?' ' : '/', *(*size+24+i)); 
		hat_found=TRUE; 
		break;
	}
	if(!hat_found && !too_small)
		printf("\n요즘 유행하는 말로 큰바위 얼굴이라고 하는 분이시군요. " 
			"맞는 모자가 없습니다. 안되셨습니다.\n"); 
}
