/* 프로그램 6.7 문자열 검색 실습 */
#include <stdio.h>
#include <string.h>
void main()
{
	char str1[] = "This string contains the holy grail.";
	char str2[] = "the holy grail";
	char str3[] = "the holy grill";

	/* str1에서 str2를 검색 */
	if(strstr(str1, str2) == NULL)
		printf("\n\"%s\"을 찾지 못했습니다.", str2);
	else
		printf("\n\"%s\"을 \"%s\"에서 찾았습니다.",str2, str1);

	/* str1에서 str3를 검색 */ 
	if(strstr(str1, str3) == NULL) 
		printf("\n\"%s\"을 찾지 못했습니다.", str3); 
	else 
		printf("\n이 메시지가 보이면 안 되는데, 뭔가 잘못됐군요!"); 
} 
