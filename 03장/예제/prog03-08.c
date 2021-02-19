/* 프로그램 3.8 행운 복권 */ 
#include <stdio.h> 

void main() 
{ 
	int choice = 0; 									/* 구매자가 선택한 수 							*/ 

	/* 선택한 번호 입력 */
	printf("\n1부터 10까지의 수 가운데 하나를 고르세요. 행운이 기다립니다! ");
	scanf("%d",&choice);

	/* 잘못 입력했는지 검사 */
	if((choice>10) || (choice <1))
		choice = 11; 									/* 잘못 선택했음을 알리는 메시지에 해당하는 수	*/

	switch(choice) 
	{ 
		case 7: 
			printf("\n축하합니다!\n고급 스포츠카 3종 세트에 당첨되셨습니다."); 
			break; 										/* 블록 끝으로 이동 							*/ 

		case 2:
			printf("\n고급 스포츠카 모형 3종 세트에 당첨되셨습니다.");
			break; 										/* 블록 끝으로 이동 							*/

		case 8:
			printf("\n고급 스포츠카 매장 평생 방문권에 당첨되셨습니다.");
			break; 										/* 블록 끝으로 이동 							*/

		case 11:
			printf("\n1부터 10 사이의 수를 입력하세요. 이 복권은 무효처리됩니다.");
														/* break문이 없으므로 다음 문장이 계속 실행됨	*/

		default: 
			printf("\n꽝! 다음기회에...\n"); 
			break; 										/* 새로운 case를 추가할 것을 대비한 break문		*/ 
	} 
} 
