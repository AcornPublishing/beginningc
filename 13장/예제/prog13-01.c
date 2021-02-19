/* ���α׷� 13.1 ��ó���� �����ڸ� �̿��� ����� */
#include <stdio.h>
#include <stdlib.h>

#define random(NumValues) ((int)(((double)(rand())*(NumValues))/(RAND_MAX+1.0)))
#define test
#define testf

/* �Լ����� */
int sum(int, int);
int product(int, int);
int difference(int, int);

void main() 
{ 
	int i = 0; 												/* ���� ī���� 				*/ 
	int j = 0; 												/* �Լ� ������ ���� �ε���	*/ 
	int a = 10, b = 5; 										/* ���۰� 					*/ 
	int result = 0; 										/* ����� ������ ���� 		*/ 
	int (*pfun[3])(int, int); 								/* �Լ� ������ �迭 ����	*/ 

	/* ������ �ʱ�ȭ */
	pfun[0] = sum;
	pfun[1] = product;
	pfun[2] = difference;

	#ifndef notrandom
	srand((unsigned int)time(NULL)); 						/* ���� �ʱⰪ ���� 		*/
	#endif

	/* �Լ� �����Ͱ� ����Ű�� �Լ��� ���� */
	for(i = 0 ; i < 10 ; i++)
	{ 
		j = random(3); 										/* 0~2 ������ ���� ����		*/ 
		
		#ifdef test
		printf("\n���� = %d", j );
		if( j>2 )
		{
			printf("\n�ùٸ��� ���� �迭 �ε��� = %d", j);
			break;
		}
		#endif 

		result = pfun[j](a , b); 							/* ������ �Լ� ȣ�� 		*/ 
		printf("\nresult = %d", result );
	}
	result = pfun[1](pfun[0](a , b), pfun[2](a , b));
	printf("\n\n�հ� ���� �� = %d\n", result);
}

/* sum �Լ� ���� */
int sum(int x, int y)
{
	#ifdef testf
	printf("\nsum �Լ� ȣ���");
	#endif

		return x + y; 
} 

/* product �Լ� ���� */
int product( int x, int y )
{
	#ifdef testf
	printf("\nproduct �Լ� ȣ���.");
	#endif

	return x * y; 
} 

/* difference �Լ� ���� */
int difference(int x, int y)
{
	#ifdef testf
	printf("\ndifference �Լ� ȣ���");
	#endif

	return x - y; 
} 
