/* 프로그램 12.4 이진 파일을 이용한 소수 계산 예제 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h > 												/* 제곱근 함수 sqrt()를 사용하기 위함	*/

#define MEM_PRIMES 100 											/* 메모리에 있는 소수의 개수 			*/

/* 함수 원형 */
int test_prime(unsigned long N);
void put_primes(void);
int check(unsigned long buffer[], int count, unsigned long N);

/* 전역 변수 */
char myfile[] = "C:\\myfile.bin"; 								/* 물리적 파일의 이름	*/
FILE *pfile = NULL; 											/* 파일 포인터 			*/

unsigned long primes[MEM_PRIMES] = { 2UL,3UL,5UL }; 			/* 소수를 저장할 배열	*/ 
int index = 3; 													/* 배열 primes에서 비어있는 요소의 인덱스 	*/ 
int nrec = 0; 													/* 파일에 기록한 항목의 개수*/ 

void main() 
{ 	
	unsigned long trial = 5UL; 									/* 소수인지 검사할 수		*/ 
	long num_primes = 3L; 										/* 찾은 소수의 개수 		*/ 
	long total = 0L; 											/* 찾아야 할 소수의 개수	*/ 
	int i = 0; 													/* 루프 카운터 				*/ 

	printf("소수를 몇 개 보여드릴까요? 	"); 		
	scanf("%d", &total); 										/* 찾아야 할 소수의 개수를 입력	*/
	total = total<4 ? 4:total; 									/* 최소 4개의 소수를 찾게 함 	*/

	/* 소수를 찾아 저장하는 루프 */
	while(num_primes < total) 									/* 원하는 개수를 모두 찾을 때까지 루프 반복 */ 
	{
		trial += 2; 											/* 다음 값을 검사 					*/
		if(test_prime(trial)) 									/* trial이 소수인지 검사 			*/ 
		{ 														/* 양의 값이 반환되면 소수이므로 	*/ 
			primes[index++] = trial; 							/* 저장하고 						*/ 
			num_primes++; 										/* 찾은 소수의 개수를 1 증가시킴	*/ 

			if(index == MEM_PRIMES) 							/* 배열에 값이 모두 찼는지 검사 	*/ 
			{
				/* 파일이 문제없이 열렸는가? */
				if((pfile = fopen(myfile, "ab")) == NULL) 
				{ 												/* 파일을 열 수 없으므로 안내문을 출력하고 프로그램을 종료 	*/
					printf("\n%s을 열 수 없습니다.\n", myfile); 
					abort();
				}
				/* 배열을 파일에 기록 */
				fwrite(primes, sizeof(long), MEM_PRIMES, pfile); 

				fclose(pfile); 									/* 파일을 닫음	*/ 
				index = 0; 										/* 메모리에 있는 소수의 개수를 초기화 		*/ 
				nrec++; 										/* 파일에 기록된 소수의 개수를 1 증가시킴	*/ 
			} 
		} 
	} 

	if(total>MEM_PRIMES) 										/* 파일에 몇 개를 기록했다면 	*/ 
		put_primes(); 											/* 파일의 내용을 출력 			*/ 
	if(index) 													/* 메모리에 남아있는 항목을 출력*/ 
		for(i = 0; i<index ; i++)
		{ 
			if(i%5 == 0)
				printf("\n"); 									/* 소수 5개씩을 한 행에 출력함 	*/
			printf("%12lu", primes[i]); 						/* 소수 출력 					*/
		} 

	if(total>MEM_PRIMES) 										/* 파일을 사용했는가?	*/ 
		if(remove(myfile)) 										/* 그렇다면 지움 		*/ 
			printf("\%s을 삭제하지 못했습니다.\n", myfile); 	/* 삭제 실패 			*/ 
		else 		
			printf("\n%s 파일을 삭제했습니다.\n",myfile); 		/* 삭제 성공 			*/ 
} 		

/********************************************************************************
 * 메모리와 파일에 들어있는 소수를 사용, 주어진 수 N이 소수인지 검사하는 함수	*
 * 첫번째 매개변수 N - 검사할 값												*
 * 반환값 - 소수인 경우 양의 값, 소수가 아니면 0								*
 ********************************************************************************/ 
int test_prime(unsigned long N) 
{ 
	unsigned long buffer[MEM_PRIMES]; 							/* 파일에 기록된 소수를 담는 버퍼	*/ 

	int i = 0; 													/* 루프 카운터	*/ 
	int k = 0; 
	
	if(nrec > 0) 												/* 파일에 소수를 기록한 적이 있나?	*/ 
	{ 			
		if((pfile = fopen(myfile, "rb")) == NULL) 				/* 있다면 파일을 엶 				*/ 
		{
			printf("\n%s을 열 수 없습니다.\n", myfile);
			abort();
		}

		for(i = 0; i < nrec ; i++) 
		{ 	/* 먼저 파일에 있는 소수와 대조 검사 */ 
			/* 파일에 기록된 소수를 읽음 */ 
			fread(buffer, sizeof(long), MEM_PRIMES, pfile); 
			if((k = check(buffer, MEM_PRIMES, N)) >= 0) 		/* 소수인가, 아닌가? 			*/ 
			{ 
				fclose(pfile); 									/* 소수이므로 파일을 닫음 		*/ 
				return k; 										/* 소수이면 1, 소수가 아니면 0	*/ 
			} 
		} 
		fclose(pfile); 											/* 파일을 닫음 						*/ 
	} 
	return check(primes, index, N); 							/* 메모리에 저장된 소수와 대조 검사	*/ 
} 

/************************************************************************ 
 * 배열 pbuffer의 요소에서 정수 N의 제곱근보다 작거나 같은 값 가운데	*
 * 정수 N을 나눌 수 있는 것이 있는지 검사하는 함수.						*
 * 첫번째 매개변수 buffer - 소수의 배열									*
 * 두번째 매개변수 count - pbuffer에 있는 요소의 개수					*
 * 세번째 매개변수 N - 검사할 값										*
 * 반환값 - N이 소수이면 1, N이 소수가 아니면 0,						*
 * 				 검사가 더 필요하면 -1을 반환							*
 ************************************************************************/  
int check(unsigned long buffer[], int count, unsigned long N) 
{ 
	int i = 0; 													/* 루프 카운터					*/ 
	/* 상한값 설정 */ 
	unsigned long root_N = (unsigned long)(1.0 + sqrt((double)N)); 
	for(i = 0 ; i<count ; i++) 
	{ 	
		if(N % buffer[i] == 0UL ) 								/* 정확히 나눠지는가?			*/ 
			return 0; 											/* 그렇다면 소수가 아님 		*/ 

		if(buffer[i] > root_N) 									/* 나눌 수가 제곱근을 넘었는가?	*/ 
			return 1; 											/* 그렇다면 소수가 맞음 		*/ 
	} 			
	return -1; 													/* 검사가 더 필요함 			*/ 
} 			
