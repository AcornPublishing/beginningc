/* 연습문제 10.3 실수를 정해진 폭으로 출력하는 프로그램 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_COUNT 100

void show(double array[], size_t array_size, unsigned int field_width);

void main()
{
  double array[MAX_COUNT] = {0.0};
  int count = 0;
  char answer = 'n';
  do
  {
    printf("값을 입력하세요: ");
    scanf("%lf", &array[count++]);
    printf("더 입력하시겠습니까(y/n)?: ");
    scanf(" %c",&answer);
  }while(count<= MAX_COUNT && tolower(answer) == 'y');

  show(array, count, 12);
  
   printf("\n");
}

void show(double array[], size_t array_size, unsigned int field_width)
{
  char format[10] = "%";   /* 형식 문자열 저장 */
  char width_str[4];       /* 폭의 값을 문자열 형식으로 저장 */
  size_t i = 0;
  size_t j = 1;

  /* 폭의 값을 문자열로 저장 */
  do
  {
    width_str[i++] = '0'+field_width%10;
  }while((field_width /= 10) != 0);

  /* 폭 문자를 format에 역순으로 연결 */
  do
  {
    format[j++] = width_str[--i];
  }while(i>0);
  format[j] = '\0';
  strcat(format, "lf");     /* 실수의 지정자 연결 */

  /* 5개의 값을 한 줄에 출력 */
  for(j = 0 ; j<array_size ; j++)
  {
    if(j%5 == 0)
      printf("\n");
    printf(format, array[j]);
  }
}
