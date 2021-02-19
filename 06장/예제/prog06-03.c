/* Program 6.3 문자열 연결하기 */
#include <stdio.h>

void main()
{
	char str1[40] = "사느냐 죽느냐";
	char str2[40] = ",그것이 문제로다";
	int count1 = 0; 												/* str1의 길이 */
	int count2 = 0; 												/* str2의 길이 */

	/* 첫번째 문자열의 길이 계산 */
	while (str1[count1] != '\0') 									/* 문자열 종료문자를 만날 때까지 	*/
		count1++; 													/* count를 증가시킨다. 				*/

	/* 두번째 문자열의 길이 계산 */
	while (str2[count2] != '\0') 									/* 두번째 문자열에 있는 문자 개수 계산 */
		count2++;

	/* 두 문자열을 모두 수용하기 충분한 공간이 있는지 검사 */
	if(sizeof str1 < count1 + count2 + 1)
		printf("\n밥그릇에 쌀 한말을 담을 수는 없는 노릇이죠.");
	else
	{ 																/* 두번째 문자열을 첫번째 문자열의 끝에 복사	*/
		count2 = 0; 												/* str2의 인덱스를 0으로 초기화 				*/
		while(str2[count2] != '\0') 								/* 널 문자가 나올 때까지 str2을 str1에 복사		*/
			str1[count1++] = str2[count2++];
		str1[count1] = '\0'; 										/* 연결한 문자열 끝에 널 문자 추가				*/ 
		printf("\n%s\n", str1 ); 									/* 연결한 문자 출력 							*/ 
	} 
} 
