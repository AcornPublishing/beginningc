/* 프로그램 13.3 타이머 함수 실습 */
#include <stdio.h>
#include <time.h>

void main() 
{ 	
	long count = 100000000; 							/* 루프 반복 회수 				*/ 
	long i = 0; 										/* 루프 카운터 					*/ 
	time_t calendar = 0; 								/* 달력시간을 저장할 변수 		*/ 
	clock_t now = 0; 									/* 초기 클럭시간을 저장할 변수	*/ 
	int interval = 3; 									/* 초 단위의 시간 간격 			*/ 
	int elapsed = 0; 									/* 경과한 클럭 시간 			*/ 

	calendar = time(NULL); 								/* 현재 달력시간을 알아냄 		*/ 
	now = clock(); 										/* 현재 클럭시간을 알아냄 		*/ 
	printf("초기 클럭시간 = %d 	초기 달력시간 = %d\n", now, calendar);

	for(i = 0L ; i<count ; i++) 
	{
		elapsed = (clock()-now)/CLOCKS_PER_SEC;
		if(elapsed>=interval)
		{
			interval += 3;
			printf("\n경과한 시간 = %ld초  반복회수 = %ld", elapsed, i);
		}
	}

	printf("\n%ld번의 루프 반복에 소요된 CPU 시간은 %.2lf초입니다.\n",
					count, (double)(clock()-now)/CLOCKS_PER_SEC ); 
	printf("\n마지막 클럭시간 = %d  마지막 달력시간 = %d\n", 
					clock(), time(NULL)); 
	printf("\n지금까지 이 프로그램을 실행하는 데 걸린 시간은 %lf입니다.\n", 
					difftime(time(NULL), calendar)); 
} 
