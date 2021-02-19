/* ���α׷� 13.4 ��¥ ������ ���� �˾Ƴ��� */
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

	int i = 3; 												/* �Ͽ� ���� ���̻�			*/ 
	struct tm *OurT = NULL; 								/* tm ����ü�� ������ 		*/ 
	time_t Tval = 0; 										/* �޷½ð� 				*/ 

	Tval = time(NULL); 										/* �޷½ð��� ���� 			*/ 
	OurT = localtime(&Tval); 								/* tm ����ü ����� �� ����	*/ 

	switch( OurT->tm_mday ) 		
	{ 		
		case 1: case 21: case 31: 		
			i= 0; 											/* ���̻�� "st" ���� 		*/ 	
			break; 		
		case 2: case 22: 		
			i = 1; 											/* "nd" ���� 				*/ 	
			break; 		
		case 3: case 23: 		
			i = 2; 											/* "rd" ���� 				*/ 	
			break; 		
		default: 		
			i = 3; 											/* "th" ���� 				*/ 	
			break; 		
	} 		

	printf("\n���� ��¥: %s the %d%s %s %d", Day[OurT->tm_wday], 
				OurT->tm_mday, Suffix[i], Month[OurT->tm_mon], 1900 + OurT->tm_year);
printf("\n���� �ð�: %d : %d : %d", 
					OurT->tm_hour, OurT->tm_min, OurT->tm_sec ); 
} 
