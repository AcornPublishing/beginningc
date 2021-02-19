/* 프로그램 2.4 간단한 계산 */ 
#include <stdio.h> 

void main() 
{ 	
	int Total_Pets; 									/* 전체 동물의 수	*/ 
	int Cats; 											/* 고양이의 수 		*/ 
	int Dogs; 											/* 강아지의 수 		*/ 
	int Ponies; 										/* 조랑말의 수 		*/ 
	int Others; 										/* 그 외 동물의 수	*/ 

	/* 종류별 동물의 수 설정 */
	Cats = 2;
	Dogs = 1;
	Ponies = 1;
	Others = 46;

	/* 전체 동물의 수 계산 */
	Total_Pets = Cats + Dogs + Ponies + Others;

	printf("동물은 모두 %d마리입니다.", Total_Pets); 	/* 결과 출력       */ 
} 
