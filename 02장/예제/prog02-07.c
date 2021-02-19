/* 프로그램 2.7 float형 값을 이용한 나눗셈 */ 
#include <stdio.h> 

void main() 
{ 
	float plank_length = 10.0f; 					/* 판자의 길이 				*/ 
	float piece_count = 4.0f; 						/* 판자를 등분할 조각 수	*/ 
	float piece_length = 0.0f; 						/* 등분한 조각의 길이 		*/ 

	piece_length = plank_length/piece_count; 
	printf("%f미터짜리 판자를 %f조각으로 등분하면 %f미터가 됩니다.",
		plank_length, piece_count, piece_length); 
} 

