/* Program 6.5 문자열 연결 - 제2탄 */
#include <stdio.h>
#include <string.h>
#define STR_LENGTH 40

void main()
{
	char str1[STR_LENGTH] = "사느냐 죽느냐"; 
	char str2[STR_LENGTH] = ",그것이 문제로다"; 

	if(STR_LENGTH > strlen(str1) + strlen(str2)) 		/* 공간이 충분한가 ? 					*/ 
		printf("\n%s\n", strcat(str1, str2)); 			/* 충분하므로 문자열을 연결하고 출력함 	*/ 
	else 
		printf("\n밥그릇에 쌀 한말을 담을 수는 없는 노릇이죠."); 
} 
