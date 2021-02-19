/* 프로그램 8.3 두 실수 값의 평균 */
#include <stdio.h>

/* 평균을 구하는 함수의 정의 */
float average(float x, float y)
{
	return (x + y)/2.0f;
}

/* 메인 프로그램 - 프로그램의 실행은 항상 여기에서 시작 */
void main()
{
	float average(float x, float y); 				/* 함수 원형 */ 

	float value1 = 0.0F;
	float value2 = 0.0F;
	float value3 = 0.0F;

	printf("실수를 2개 입력하세요. 두 값은 스페이스바를 눌러 구분하세요: ");
	scanf("%f %f", &value1, &value2);
	value3 = average(value1, value2);
	printf("\n두 값의 평균은 %f입니다.\n", value3);
} 
