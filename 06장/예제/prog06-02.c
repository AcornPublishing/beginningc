/* 프로그램 6.2 문자열의 길이 */
#include <stdio.h>

void main()
{
	char str1[40] = "To be or not to be";
	char str2[40] = ",그것이 문제로다";
	int count = 0; 													/* 문자열의 길이를 저장할 변수 			*/
	while (str1[count] != '\0') 									/* 문자열 종료문자가 나타날 때까지 		*/
		count++; 													/* count를 1씩 증가시킨다. 				*/ 
	printf("\n문자열 \"%s\"의 길이는 %d문자입니다.", str1, count);
	count = 0; 														/* 0으로 초기화해 다음 문자열을 준비함	*/ 

	while (str2[count] != '\0') 									/* 두번째 문자열에서 문자의 수를 계산 	*/ 
		count++; 		
	printf("\n문자열 \"%s\"의 길이는 %d문자입니다.\n", str2, count); 
} 
