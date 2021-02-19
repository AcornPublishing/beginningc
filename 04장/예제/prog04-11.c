/* 프로그램 4.11 숫자 뒤집기 */ 
#include <stdio.h> 
void main() 
{ 
	int number = 0; 									/* 순서를 뒤집을 양의 정수	*/ 
	int rebmun = 0; 									/* 순서를 뒤집은 결과 		*/ 
	int temp = 0; 										/* 임시저장소 				*/ 

	/* 숫자를 뒤집을 양의 정수 입력 */
	printf("\n양의 정수를 하나 입력하세요: ");
	scanf("%d", &number);

	temp = number; 										/* 임시저장소에 복사 		*/ 

	/* temp에 저장된 수를 뒤집음 */
	do
	{
		rebmun = 10*rebmun + temp % 10; 				/* 맨 오른쪽 숫자를 추가 	*/ 
		temp = temp/10; 								/* 맨 오른쪽 숫자를 제거 	*/ 
	} while (temp); 									/* temp>0이면 루프를 계속	*/ 

	printf ("\n\'양의 정수 %d\'(을)를 뒤집으면 \'%d 수정 의양\'.\n", number, rebmun ); 
} 
