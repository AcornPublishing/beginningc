/* 프로그램 9.8 명령행 인자를 받아들이는 프로그램 */
#include <stdio.h>
void main(int argc, char *argv[])
{
	int i = 0; 
	printf("프로그램 이름: %s\n", argv[0]); 
	for(i = 1 ; i<argc ; i++) 
		printf("\n인자 %d: %s", i, argv[i]); 
} 
