/* 프로그램 3.10 비트연산자 실습 */ 
#include <stdio.h> 

void main() 
{ 
	unsigned int original = 0xABC; 
	unsigned int result = 0; 
	unsigned int mask = 0xF; 					/* 맨 오른쪽 4개 비트 	*/ 

	printf("\noriginal = %X", original); 

	/* result에 첫번째 숫자를 기록 */
	result |= original&mask; 					/* original의 오른쪽 4개 비트를 result에 삽입 */

	/* 두번째 숫자를 기록 */
	original >>= 4; 							/* original을 오른쪽으로 4칸 이동 			  */
	result <<= 4; 								/* 다음 숫자가 들어갈 공간을 만듦 			  */
	result |= original&mask; 					/* original의 오른쪽 4개 비트를 result에 삽입 */

	/* 세번째 숫자를 기록 */
	original >>= 4; 							/* original을 오른쪽으로 4칸 이동 			  */
	result <<= 4; 								/* 다음 숫자가 들어갈 공간을 만듦 			  */
	result |= original&mask; 					/* original의 오른쪽 4개 비트를 result에 삽입 */
	printf("\t result = %X\n", result);
} 
