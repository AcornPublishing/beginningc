/* 프로그램 12.1 한 번에 한 문자씩 파일에 쓰기 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{ 
	char mystr[80]; 											/* 입력 문자열 			*/ 
	int i = 0; 													/* 루프 카운터 			*/ 
	int lstr = 0; 												/* 입력 문자열의 길이	*/ 
	int mychar = 0; 											/* 출력할 문자 			*/ 
	FILE *pfile = NULL; 										/* 파일 포인터 			*/ 
	char *filename = "C:\\myfile.txt"; 

	printf("\n원하는 문자열을 입력하세요.\n");
	gets(mystr); 												/* 문자열을 읽음 		*/

	/* 쓸 수 있는 새 파일 만들기 */
	pfile = fopen(filename, "w"); 
	if(pfile == NULL)
	{
		printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
		abort();
	}

	lstr = strlen( mystr );
	for(i = lstr-1 ; i >= 0 ; i--)
		fputc(mystr[i], pfile); 								/* 문자열을 뒤집어 파일에 쓰기 	*/

	fclose(pfile); 												/* 파일 닫기 					*/ 
	/* 읽기 용도로 파일 열기 */
	pfile = fopen(filename, "r"); 
	if(pfile == NULL) 
	{ 
		printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename); 
		abort(); 
	} 

	/* 파일에서 문자를 읽어 출력함 */ 
	while((mychar = fgetc(pfile)) != EOF) 
		putchar(mychar); 										/* 파일에 기록된 문자를 출력	*/ 
	putchar('\n'); 												/* 줄바꿈문자 출력				*/ 

	fclose(pfile); 												/* 파일 닫기 					*/ 
	remove(filename); 											/* 물리적 파일 지우기 			*/ 
} 
