/* 프로그램 6.9 하나의 문자열에서 부분문자열 검색하기 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{ 
	char text[100]; 										/* 검색할 문자열을 읽어들일 입력 버퍼	*/ 
	char substring[40]; 									/* 찾을 문자열을 읽어들일 입력 버퍼 	*/ 
	int i = 0; 												/* 문자열에 있는 문자의 인덱스 			*/ 

	printf("\n검색할 문자열을 100자 이내로 입력하세요:\n");
	gets(text);
	printf("\n찾을 문자열을 40자 이내로 입력하세요:\n");
	gets(substring);

	/* 두 문자열을 모두 대문자로 변환 */
	for(i = 0 ; (text[i] = toupper(text[i])) != '\0' ; i++);
	for(i = 0 ; (substring[i] = toupper(substring[i])) != '\0' ; i++);
	printf("\n찾고자 하는 문자열을 검색 대상 문자열에서 찾%s습니다.", 
		((strstr(text, substring) == NULL) ? "지 못했" : "았")); 
} 
