/* 프로그램 10.5 scanf()로 문자 읽기 */ 
#include <stdio.h> 

void main() 
{ 
	char initial = ' '; 
	char name[80] = { 0 }; 
	char age[4] = { 0 }; 
	printf("이름의 이니셜을 입력하세요: "); 
	scanf("%c", &initial ); 
	printf("이름을 입력하세요: "); 
	scanf("%s", name ); 

	if(initial != name[0])
		printf("\n%s님, 이니셜을 잘못 입력하셨네요.", name);
	else
		printf("\n안녕하세요 %s님. 이니셜을 올바르게 입력하셨네요!", name );
	printf("\n이름과 나이를 쉼표로 구분해서 입력해주세요:\n" );
	scanf("%[^,] , %[0123456789]", name, age );
	printf("\n당신의 이름은 %s이고 나이는 %s살입니다.\n", name, age );
} 
