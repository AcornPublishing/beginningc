/* 프로그램 12.6 파일 뷰어 */
#include <stdio.h>
#include <ctype.h> 
#include <string.h> 

#define DISPLAY 80 															/* 출력할 행의 길이 	 */ 
#define PAGE_LENGTH 20 														/* 한 페이지당 행의 개수 */ 

int main(int argc, char *argv[]) 
{ 
	char filename[80]; 														/* 파일이름을 저장할 변수	*/ 
	FILE *pfile; 															/* 파일 포인터 				*/ 
	unsigned char buffer[DISPLAY/4 - 1]; 									/* 파일 입력 버퍼 			*/
	int count = 0; 															/* 버퍼에 있는 문자의 개수 	*/
	int lines = 0; 															/* 출력한 행의 개수 		*/
	int i = 0; 																/* 루프 카운터 				*/

	if(argc == 1) 															/* 명령행에 파일이름이 없나?	*/ 
	{ 			
		printf("파일이름을 입력하세요: "); 									/* 입력하라는 지시문을 출력		*/ 
		gets(filename); 													/* 입력된 파일이름을 읽음 		*/ 
	} 			
	else
		strcpy(filename, argv[1]); 											/* 두번째 명령행 문자열을 읽음	*/

	/* 파일을 문제없이 열수 있는가? */
	if((pfile = fopen(filename, "rb")) == NULL) 
	{
		printf("죄송합니다. %s 파일을 열 수 없습니다.", filename); 
		return -1;
	} 	
	while(!feof(pfile)) 													/* 파일 끝까지 계속 반복 		*/ 
	{ 
		if(count < sizeof buffer) 											/* 버퍼를 가득 채우지 않았으면	*/ 
			buffer[count++] = (unsigned char)fgetc(pfile); 					/* 문자를 하나 읽어들임 		*/ 
		else 
		{ 	/* 버퍼에 있는 데이터를 먼저 16진수 형식으로 출력 */ 
			for(count = 0; count < sizeof buffer; count++) 
				printf("%02X ", buffer[count]); 
			printf("| "); 													/* 열 구분문자 출력		*/ 

			/* 버퍼에 있는 데이터를 문자 형식으로 출력 */ 
			for(count = 0; count < sizeof buffer; count++) 
				printf("%c", isprint(buffer[count]) ? buffer[count]:'.'); 
			printf("\n"); 													/* 한 행이 끝남 		*/ 
			count = 0; 														/* count를 초기화		*/ 

			if(!(++lines%PAGE_LENGTH)) 										/* 페이지가 끝났는가?	*/ 
				if(getchar()=='E') 											/* 사용자 입력을 기다림	*/ 
					return 0; 												/* 사용자가 E를 눌렀음 	*/ 
		} 		
	} 		

	/* 마지막 행을 먼저 16진수 형식으로 출력 */
	for(i = 0; i < sizeof buffer; i++)
		if(i < count)
			printf("%02X ", buffer[i]); 									/* 16진수 출력		*/
		else
			printf(" "); 													/* 스페이스 출력 	*/
	printf("| "); 															/* 구분문자 출력	*/
 
	/* 마지막 행을 문자 형식으로 출력 */ 
	for(i = 0; i < count; i++)
		printf("%c",isprint(buffer[i]) ? buffer[i]:'.'); 					/* 문자 출력 */
	printf("\n"); 															/* 행을 끝냄 */
	fclose(pfile); 															/* 파일 닫기 */
	return 0; 		
} 			

