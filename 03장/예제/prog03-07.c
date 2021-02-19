/* 프로그램 3.7 복잡한 신입사원 선발 기준 */
#include <stdio.h>

void main() 
{ 
	int age = 0; 											/* 지원자의 나이		*/ 
	int college = 0; 										/* 졸업한 학교의 코드	*/ 
	int subject = 0; 										/* 전공과목의 코드		*/ 
	int interview = 0; 										/* 합격은 1, 불합격은 0 */ 

	/* 지원자의 데이터를 입력받음 */
	printf("\n출신 대학은? 1.하버드, 2.예일, 3.기타: ");
	scanf("%d",&college);
	printf("\n전공 과목은? 1.화학, 2.경제학, 3.기타: ");
	scanf("%d", &subject);
	printf("\n지원자의 나이는? ");
	scanf("%d",&age);

	/* 지원자 선발 */ 
	if((age>25 && subject==1) && (college==3 || college==1)) 
		interview = 1; 
	if(college==2 &&subject ==1) 
		interview = 1; 
	if(college==1 && subject==2 && !(age>28)) 
		interview = 1; 
	if(college==2 && (subject==2 || subject==3) && age>25) 
		interview = 1; 

	/* 면접대상 선발여부 출력 */
	if(interview)
 
		printf("\n\n서류심사 합격 - 면접 대상자");
	else
		printf("\n\n서류심사 불합격");
}
