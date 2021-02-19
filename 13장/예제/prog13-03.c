/* ���α׷� 13.3 Ÿ�̸� �Լ� �ǽ� */
#include <stdio.h>
#include <time.h>

void main() 
{ 	
	long count = 100000000; 							/* ���� �ݺ� ȸ�� 				*/ 
	long i = 0; 										/* ���� ī���� 					*/ 
	time_t calendar = 0; 								/* �޷½ð��� ������ ���� 		*/ 
	clock_t now = 0; 									/* �ʱ� Ŭ���ð��� ������ ����	*/ 
	int interval = 3; 									/* �� ������ �ð� ���� 			*/ 
	int elapsed = 0; 									/* ����� Ŭ�� �ð� 			*/ 

	calendar = time(NULL); 								/* ���� �޷½ð��� �˾Ƴ� 		*/ 
	now = clock(); 										/* ���� Ŭ���ð��� �˾Ƴ� 		*/ 
	printf("�ʱ� Ŭ���ð� = %d 	�ʱ� �޷½ð� = %d\n", now, calendar);

	for(i = 0L ; i<count ; i++) 
	{
		elapsed = (clock()-now)/CLOCKS_PER_SEC;
		if(elapsed>=interval)
		{
			interval += 3;
			printf("\n����� �ð� = %ld��  �ݺ�ȸ�� = %ld", elapsed, i);
		}
	}

	printf("\n%ld���� ���� �ݺ��� �ҿ�� CPU �ð��� %.2lf���Դϴ�.\n",
					count, (double)(clock()-now)/CLOCKS_PER_SEC ); 
	printf("\n������ Ŭ���ð� = %d  ������ �޷½ð� = %d\n", 
					clock(), time(NULL)); 
	printf("\n���ݱ��� �� ���α׷��� �����ϴ� �� �ɸ� �ð��� %lf�Դϴ�.\n", 
					difftime(time(NULL), calendar)); 
} 
