/* ���α׷� 12.4 ���� ������ �̿��� �Ҽ� ��� ���� */
#include <stdio.h>
#include <stdlib.h>
#include <math.h > 												/* ������ �Լ� sqrt()�� ����ϱ� ����	*/

#define MEM_PRIMES 100 											/* �޸𸮿� �ִ� �Ҽ��� ���� 			*/

/* �Լ� ���� */
int test_prime(unsigned long N);
void put_primes(void);
int check(unsigned long buffer[], int count, unsigned long N);

/* ���� ���� */
char myfile[] = "C:\\myfile.bin"; 								/* ������ ������ �̸�	*/
FILE *pfile = NULL; 											/* ���� ������ 			*/

unsigned long primes[MEM_PRIMES] = { 2UL,3UL,5UL }; 			/* �Ҽ��� ������ �迭	*/ 
int index = 3; 													/* �迭 primes���� ����ִ� ����� �ε��� 	*/ 
int nrec = 0; 													/* ���Ͽ� ����� �׸��� ����*/ 

void main() 
{ 	
	unsigned long trial = 5UL; 									/* �Ҽ����� �˻��� ��		*/ 
	long num_primes = 3L; 										/* ã�� �Ҽ��� ���� 		*/ 
	long total = 0L; 											/* ã�ƾ� �� �Ҽ��� ����	*/ 
	int i = 0; 													/* ���� ī���� 				*/ 

	printf("�Ҽ��� �� �� �����帱���? 	"); 		
	scanf("%d", &total); 										/* ã�ƾ� �� �Ҽ��� ������ �Է�	*/
	total = total<4 ? 4:total; 									/* �ּ� 4���� �Ҽ��� ã�� �� 	*/

	/* �Ҽ��� ã�� �����ϴ� ���� */
	while(num_primes < total) 									/* ���ϴ� ������ ��� ã�� ������ ���� �ݺ� */ 
	{
		trial += 2; 											/* ���� ���� �˻� 					*/
		if(test_prime(trial)) 									/* trial�� �Ҽ����� �˻� 			*/ 
		{ 														/* ���� ���� ��ȯ�Ǹ� �Ҽ��̹Ƿ� 	*/ 
			primes[index++] = trial; 							/* �����ϰ� 						*/ 
			num_primes++; 										/* ã�� �Ҽ��� ������ 1 ������Ŵ	*/ 

			if(index == MEM_PRIMES) 							/* �迭�� ���� ��� á���� �˻� 	*/ 
			{
				/* ������ �������� ���ȴ°�? */
				if((pfile = fopen(myfile, "ab")) == NULL) 
				{ 												/* ������ �� �� �����Ƿ� �ȳ����� ����ϰ� ���α׷��� ���� 	*/
					printf("\n%s�� �� �� �����ϴ�.\n", myfile); 
					abort();
				}
				/* �迭�� ���Ͽ� ��� */
				fwrite(primes, sizeof(long), MEM_PRIMES, pfile); 

				fclose(pfile); 									/* ������ ����	*/ 
				index = 0; 										/* �޸𸮿� �ִ� �Ҽ��� ������ �ʱ�ȭ 		*/ 
				nrec++; 										/* ���Ͽ� ��ϵ� �Ҽ��� ������ 1 ������Ŵ	*/ 
			} 
		} 
	} 

	if(total>MEM_PRIMES) 										/* ���Ͽ� �� ���� ����ߴٸ� 	*/ 
		put_primes(); 											/* ������ ������ ��� 			*/ 
	if(index) 													/* �޸𸮿� �����ִ� �׸��� ���*/ 
		for(i = 0; i<index ; i++)
		{ 
			if(i%5 == 0)
				printf("\n"); 									/* �Ҽ� 5������ �� �࿡ ����� 	*/
			printf("%12lu", primes[i]); 						/* �Ҽ� ��� 					*/
		} 

	if(total>MEM_PRIMES) 										/* ������ ����ߴ°�?	*/ 
		if(remove(myfile)) 										/* �׷��ٸ� ���� 		*/ 
			printf("\%s�� �������� ���߽��ϴ�.\n", myfile); 	/* ���� ���� 			*/ 
		else 		
			printf("\n%s ������ �����߽��ϴ�.\n",myfile); 		/* ���� ���� 			*/ 
} 		

/********************************************************************************
 * �޸𸮿� ���Ͽ� ����ִ� �Ҽ��� ���, �־��� �� N�� �Ҽ����� �˻��ϴ� �Լ�	*
 * ù��° �Ű����� N - �˻��� ��												*
 * ��ȯ�� - �Ҽ��� ��� ���� ��, �Ҽ��� �ƴϸ� 0								*
 ********************************************************************************/ 
int test_prime(unsigned long N) 
{ 
	unsigned long buffer[MEM_PRIMES]; 							/* ���Ͽ� ��ϵ� �Ҽ��� ��� ����	*/ 

	int i = 0; 													/* ���� ī����	*/ 
	int k = 0; 
	
	if(nrec > 0) 												/* ���Ͽ� �Ҽ��� ����� ���� �ֳ�?	*/ 
	{ 			
		if((pfile = fopen(myfile, "rb")) == NULL) 				/* �ִٸ� ������ �� 				*/ 
		{
			printf("\n%s�� �� �� �����ϴ�.\n", myfile);
			abort();
		}

		for(i = 0; i < nrec ; i++) 
		{ 	/* ���� ���Ͽ� �ִ� �Ҽ��� ���� �˻� */ 
			/* ���Ͽ� ��ϵ� �Ҽ��� ���� */ 
			fread(buffer, sizeof(long), MEM_PRIMES, pfile); 
			if((k = check(buffer, MEM_PRIMES, N)) >= 0) 		/* �Ҽ��ΰ�, �ƴѰ�? 			*/ 
			{ 
				fclose(pfile); 									/* �Ҽ��̹Ƿ� ������ ���� 		*/ 
				return k; 										/* �Ҽ��̸� 1, �Ҽ��� �ƴϸ� 0	*/ 
			} 
		} 
		fclose(pfile); 											/* ������ ���� 						*/ 
	} 
	return check(primes, index, N); 							/* �޸𸮿� ����� �Ҽ��� ���� �˻�	*/ 
} 

/************************************************************************ 
 * �迭 pbuffer�� ��ҿ��� ���� N�� �����ٺ��� �۰ų� ���� �� ���	*
 * ���� N�� ���� �� �ִ� ���� �ִ��� �˻��ϴ� �Լ�.						*
 * ù��° �Ű����� buffer - �Ҽ��� �迭									*
 * �ι�° �Ű����� count - pbuffer�� �ִ� ����� ����					*
 * ����° �Ű����� N - �˻��� ��										*
 * ��ȯ�� - N�� �Ҽ��̸� 1, N�� �Ҽ��� �ƴϸ� 0,						*
 * 				 �˻簡 �� �ʿ��ϸ� -1�� ��ȯ							*
 ************************************************************************/  
int check(unsigned long buffer[], int count, unsigned long N) 
{ 
	int i = 0; 													/* ���� ī����					*/ 
	/* ���Ѱ� ���� */ 
	unsigned long root_N = (unsigned long)(1.0 + sqrt((double)N)); 
	for(i = 0 ; i<count ; i++) 
	{ 	
		if(N % buffer[i] == 0UL ) 								/* ��Ȯ�� �������°�?			*/ 
			return 0; 											/* �׷��ٸ� �Ҽ��� �ƴ� 		*/ 

		if(buffer[i] > root_N) 									/* ���� ���� �������� �Ѿ��°�?	*/ 
			return 1; 											/* �׷��ٸ� �Ҽ��� ���� 		*/ 
	} 			
	return -1; 													/* �˻簡 �� �ʿ��� 			*/ 
} 			
