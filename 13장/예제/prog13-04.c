/* 프로그램 13.4 날짜 데이터 쉽게 알아내기 */
#include <stdio.h>
#include <time.h>

void main()
{
	char *Day[7] = 	{	"Sunday" , "Monday", "Tuesday", "Wednesday", 
						"Thursday", "Friday", "Saturday"
					}; 

	char *Month[12] =	{	"January", "February", "March", "April", 
							"May", "June", "July", "August", 
							"September", "October", "November", "December" 
						}; 

	char *Suffix[] = { "st", "nd", "rd", "th" }; 

	int i = 3; 												/* 일에 붙을 접미사			*/ 
	struct tm *OurT = NULL; 								/* tm 구조체의 포인터 		*/ 
	time_t Tval = 0; 										/* 달력시간 				*/ 

	Tval = time(NULL); 										/* 달력시간을 얻음 			*/ 
	OurT = localtime(&Tval); 								/* tm 구조체 멤버의 값 결정	*/ 

	switch( OurT->tm_mday ) 		
	{ 		
		case 1: case 21: case 31: 		
			i= 0; 											/* 접미사로 "st" 선택 		*/ 	
			break; 		
		case 2: case 22: 		
			i = 1; 											/* "nd" 선택 				*/ 	
			break; 		
		case 3: case 23: 		
			i = 2; 											/* "rd" 선택 				*/ 	
			break; 		
		default: 		
			i = 3; 											/* "th" 선택 				*/ 	
			break; 		
	} 		

	printf("\n오늘 날짜: %s the %d%s %s %d", Day[OurT->tm_wday], 
				OurT->tm_mday, Suffix[i], Month[OurT->tm_mon], 1900 + OurT->tm_year);
printf("\n현재 시각: %d : %d : %d", 
					OurT->tm_hour, OurT->tm_min, OurT->tm_sec ); 
} 
