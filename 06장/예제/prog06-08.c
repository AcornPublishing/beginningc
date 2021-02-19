/* 프로그램 6.8 문자열에 있는 문자열 검사 */
#include <stdio.h>
#include <ctype.h>
void main()
{
	char buffer[80]; 										/* 입력 버퍼 						*/ 
	int i = 0; 												/* 버퍼 인덱스 						*/ 
	int num_letters = 0; 									/* 입력 문자열에 있는 글자의 개수 	*/ 
	int num_digits = 0; 									/* 입력 문자열에 있는 숫자의 개수 	*/ 

	printf("\n80문자 미만으로 원하는 문자열을 입력하세요:\n"); 
	gets(buffer); 											/* 문자열을 버퍼에 읽어들임 */ 

	while(buffer[i] != '\0') 		
	{ 			
		if(isalpha(buffer[i])) 		
			num_letters++; 									/* 글자 카운터를 증가 	*/ 
		if(isdigit(buffer[i++])) 		
			num_digits++; 									/* 숫자 카운터를 증가	*/ 
	} 			
	printf("\n문자열에는 %d개의 글자와 %d개의 숫자가 있습니다.\n", 
		num_letters, num_digits); 
} 
