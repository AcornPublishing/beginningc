/* 프로그램 12.2 속담은 계속된다 */ 
#include <stdio.h> 

void main() 
{ 
	char *proverbs[] = 
	{ 
		"티끌모아 태산.\n",
		"사공이 많으면 배가 산으로 올라간다.\n",
		"최후에 웃는 자가 진정한 승자다.\n"
	};

	char more[60] = "소 귀에 경읽기.\n";
	FILE *pfile = NULL; 												/* 파일 포인터		*/
	int i = 0; 															/* 루프 카운터		*/
	char *filename = "C:\\myfile.txt";

	/* myfile.txt가 존재하지 않을 경우 새 파일을 만듦 */
	pfile = fopen(filename, "w");
	if(pfile == NULL)
	{
		printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
		abort();
	}

	/* 처음 3개의 속담을 출력 */
	for(i = 0 ; i < sizeof proverbs/sizeof proverbs[0] ; i++)
		fputs(proverbs[i], pfile);
	fclose(pfile); 														/* 파일 닫기 					*/

	pfile = fopen(filename, "a"); 										/* 파일을 연결 용도로 다시 열기 */
	if(pfile == NULL)
	{
		printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename);
		abort();
	}

	fputs(more, pfile); 												/* 다른 속담을 씀			*/ 
	fclose(pfile); 														/* 파일을 닫음 				*/

	pfile = fopen(filename, "r"); 										/* 파일을 읽기 용도로 열기	*/ 
	if(pfile == NULL)
	{
		printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename); 
		abort(); 
	} 
	while(fgets(more, 60, pfile) != NULL) 								/* 속담을 읽고	*/ 
		printf("\n%s", more); 											/* 화면에 출력	*/ 

	fclose(pfile); 														/* 파일을 닫고	*/ 
	remove(filename); 													/* 제거함 		*/ 
} 
