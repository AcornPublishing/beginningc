/* 연습문제 13.2 시간을 문자열로 */
#include <stdio.h>
#include <time.h>
#include <string.h>
#define TIME_24   1
#define TIME_12   0

char *get_time_string(int mode24);     /* 시간을 12/24시간 형식의 문자열로 반환하는 함수 */
char *int_to_str(unsigned int n);      /* 1개 또는 2개의 숫자로 이뤄진 정수를 문자열로 변환하는 함수 */
void main()
{
  printf("\n24시간제로 나타낸 시각 : %12s", get_time_string(TIME_24));
  printf("\n12시간제로 나타낸 시각 : %12s\n", get_time_string(TIME_12));
}

/* 시간을 12/24시간제로 나타낸 문자열을 반환하는 함수 */
/* 
   시간을 12/24시간제로 표현한 정적 문자열의 주소를 반환한다.
   함수를 호출할 때마다 정적 문자열의 내용을 덮어쓰게 된다.
   24시간제로 표현할 때는 인자로 1을, 12시간제는 0이 돼야 한다.
*/
char* get_time_string(int mode24) 
{
  static char time_str[12] = {0};   /* 시간을 저장할 문자열 */
  struct tm *now = NULL;
  int hour = 0;
  time_t time_value = 0;

  time_value = time(NULL);          /* 시간값 얻기                */
  now = localtime(&time_value);     /* 시간/날짜 구조체 얻기      */
  hour = now->tm_hour;              /* 시 값 저장                 */
  if(!mode24 && hour>12)            /* 12시간제일 경우 시 값 조정 */
    hour -= 12;

  strcpy(time_str, int_to_str(hour));
  strcat(time_str, ":");
  strcat(time_str, int_to_str(now->tm_min));
  strcat(time_str, ":");
  strcat(time_str, int_to_str(now->tm_sec));
  if(!mode24)
    strcat(time_str, now->tm_hour>24 ? " am" : " pm");
  return time_str;
}

/* 1개 또는 2개의 부호없는 정수를 길이가 2인 문자열로 변환하는 함수 */
/* 
   이 함수는 변환할 정수를 인자로 넘겨받음.
   정적 문자열의 주소를 반환함.
   앞서 호출해 만든 문자열은 다음 호출때 덮어쓰게 됨.
*/
char *int_to_str(unsigned int n)
{
  static char str[3];      /* 값을 문자열 형태로 저장할 변수 */
  str[1] = '0'+n%10;       /* 두번째 숫자를 알아냄           */
  n /= 10;
  str[0] = '0'+n%10;       /* 첫번째 숫자를 알아냄           */
  str[2] = '\0';           /* 종료문자 연결                  */

  return str;
}
