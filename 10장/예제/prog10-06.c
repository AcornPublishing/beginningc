/* 프로그램 10.6 gets()를 이용해 문자열 읽기 */ 
#include <stdio.h> 

void main() 
{ 
	char initial[2] = {0}; 
	char name[80] = {0}; 

	printf("이니셜을 입력하세요: ");
	gets(initial);
	printf("이름을 입력하세요: " );
	gets(name);
	if(initial[0] != name[0])
		printf("\n%s님, 이니셜을 잘못 입력하셨네요.\n", name); 
	else 
		printf("\n안녕하세요 %s님. 이니셜을 올바르게 입력하셨네요!\n", name); 
} 
