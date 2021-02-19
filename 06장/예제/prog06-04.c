/* 프로그램 6.4 문자열의 배열 */
#include <stdio.h>

void main()
{
	char str[][40] = {
						"사느냐 죽느냐" ,
						",그것이 문제로다"
					 };
	int count1 = 0; 												/* 첫번째 문자열의 길이 */
	int count2 = 0; 												/* 두번째 문자열의 길이 */

	/* 첫번째 문자열의 길이 계산 */
	while (str[0][count1] != '\0') 
		count1++; 

	/* 두번째 문자열의 길이 계산 */
	while (str[1][count2] != '\0')
		count2++;

	/* 첫번째 행에 두 문자열을 모두 저장할 공간이 있는지 검사 */
	if(sizeof str[0] < count1 + count2 + 1)
		printf("\n밥그릇에 쌀 한말을 담을 수는 없는 노릇이죠.");
	else
	{ 																/* 두번째 문자열을 첫번째 문자열에 복사 */
		count2 = 0;
		while((str[0][count1++] = str[1][count2++]) != '\0'); 

		printf("\n%s\n", str[0]); 									/* 연결한 문자열 출력 */ 
	} 
} 
