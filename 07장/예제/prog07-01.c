/* 프로그램 7.1 포인터를 이용한 간단한 프로그램 */ 
#include <stdio.h> 

void main() 
{ 	
	int number = 0; 										/* 0으로 초기화한 int형 변수 			*/ 
	int *pointer = NULL; 									/* int형 변수를 가리킬 수 있는 포인터	*/ 

	number = 10; 
	printf("\nnumber의 주소: %p", &number); 				/* 주소 출력*/
	printf("\nnumber의 값: %d\n\n", number); 				/* 값 출력 	*/

	pointer = &number; 										/* pointer에 number의 주소를 저장	*/

	printf("pointer의 주소: %p", &pointer); 				/* 주소를 출력 		*/
	printf("\npointer의 크기: %d바이트", sizeof(pointer)); 	/* 크기를 출력 		*/
	printf("\npointer의 값: %p", pointer); 					/* 값(주소)을 출력	*/
	printf("\npointer가 가리키고 있는 값: %d\n", *pointer); /* 주소에 있는 값	*/ 
}
