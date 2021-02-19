/* 프로그램 12.3 형식있는 파일 I/O 해부하기 */ 
#include <stdio.h> 
#include <stdlib.h>
void main() 
{ 
	long num1 = 234567L; 											/* 입력값 				*/ 
	long num2 = 345123L; 
	long num3 = 789234L; 

	long num4 = 0L; 												/* 파일에서 읽어들인 값	*/
	long num5 = 0L;
	long num6 = 0L; 

	float fnum = 0.0f; 												/* 파일에서 읽어들인 값	*/ 
	int ival[6] = { 0 }; 											/* 파일에서 읽어들인 값	*/
	int i = 0; 														/* 루프 카운터 			*/ 
	FILE *pfile = NULL; 											/* 파일 포인터 			*/ 
	char *filename = "C:\\myfile.txt";

	pfile = fopen(filename, "w"); 									/* 기록할 파일 만들기 	*/
	if(pfile == NULL)
	{
		printf("%s를 여는 도중 오류가 발생했습니다. 프로그램을 종료합니다.", filename); 
		abort();
	}
	fprintf(pfile, "%6ld%6ld%6ld", num1, num2, num3); 				/* 파일 쓰기 		*/ 
	fclose(pfile); 													/* 파일 닫기 		*/ 
	printf("\n %6ld %6ld %6ld", num1, num2, num3);			 		/* 기록한 값을 출력	*/ 

	pfile = fopen(filename, "r"); 									/* 읽을 파일 열기 	*/ 
	fscanf(pfile, "%6ld%6ld%6ld", &num4, &num5 ,&num6);				/* 다시 값을 읽음 	*/ 
	printf("\n %6ld %6ld %6ld", num4, num5, num6); 					/* 읽은 값을 출력 	*/ 

	rewind(pfile); 													/* 파일의 시작위치로 이동 	*/
	fscanf(pfile, "%2d%3d%3d%3d%2d%2d%3f", &ival[0], &ival[1],		/* 다시 값을 읽음	*/
					&ival[2], &ival[3], &ival[4] , &ival[5], &fnum); 
	fclose(pfile); 													/* 파일을 닫고			*/ 
	remove(filename); 												/* 물리적 파일을 제거	*/ 

	/* 결과 출력 */
	printf("\n");
	for( i = 0 ; i < 6 ; i++ )
		printf("%sival[%d] = %d", i == 4 ? "\n\t" : "\t", i, ival[i]); 
	printf("\nfnum = %f\n", fnum); 
} 
