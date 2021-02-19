/* 연습문제 9.4 하나 이상의 실수를 하나의 문자열로 변환 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char* to_string(int count, double first, ...);  /* 실수를 쉼표로 구분된 문자열로 변환하는 함수 */
char* fp_to_str(double x);                      /* x를 문자열로 변환하는 함수                  */
char* int_to_str(int n);                        /* n을 문자열로 변환하는 함수                  */ 

void main()
{
  char *str = NULL;                  /* 실수 문자열을 가리키는 포인터 */
  double values[] = { 1.245, -3.5, 6.758, 33.399, -1.02 };

  str = to_string(sizeof values/sizeof(double), values[0], values[1], values[2], values[3], values[4]);

  printf("변환한 문자열은 다음과 같습니다.\n%s\n", str);
 
  free(str);                         /* 문자열의 메모리 해제 */
}

/****************************************************************
 * 하나 이상의 실수를 받아들여 쉼표로 구분된 문자열로 변환하는  *
 * 함수. 이 함수는 메모리를 할당하며, 호출하는 쪽에서 해제해야  *
 * 한다.                                                        *
 ****************************************************************/
char* to_string(int count, double first, ...)
{
  va_list parg = NULL;          /* 정해지지 않은 인자를 가리키는 포인터 */
  char* str = NULL;             /* 결합된 문자열을 가리키는 포인터      */
  char *temp = NULL;            /* 임시 문자열 포인터                   */
  char *value_str = 0;          /* 값 문자열을 가리키는 포인터          */
  const char *separator = ",";  /* 값 문자열의 구분자                   */
  size_t separator_length = 0;  /* 구분자 문자열의 길이                 */
  size_t length = 0;            /* 문자열의 길이                        */
  int i = 0;                    /* 루프 카운터                          */

  separator_length = strlen(separator);

  va_start(parg,first);         /* 인자 포인터 초기화 */

  str = fp_to_str(first);       /* 첫번째 값 변환     */

  /* 나머지 인자를 받아들여 문자열로 변환하고 연결 */
  while(--count>0)
  {
    value_str = fp_to_str(va_arg(parg, double));    /* 다음 인자를 얻어옴 */
    length = strlen(str) + strlen(value_str) + separator_length +1;
    temp = (char*)malloc(length); /* 문자열을 저장할 메모리 할당 */
    strcpy(temp, str);            /* 이전 문자열 복사            */
    free(str);                    /* 이전 메모리 해제            */
    str = temp;                   /* 새 메모리 주소 저장         */
    temp = NULL;                  /* 포인터 초기화               */
    strcat(str,separator);        /* 구분자 연결                 */
    strcat(str,value_str);        /* 값 문자열 연결              */
    free(value_str);              /* 값 문자열의 메모리 해제     */
  }
  va_end(parg);                   /* parg 포인터 해제            */
  return str;
}

/***************************************************************************
 * 실수 인자를 문자열로 변환하는 함수                                      *
 * 결과값은 소수점 이하 2자리까지임                                        *
 * 메모리를 할당해 문자열을 저장하며, 호출하는 쪽에서 해제해야 함          *
 ***************************************************************************/
char* fp_to_str(double x)
{
  char *str = NULL;                 /* 문자열을 가리키는 포인터        */
  char *integral = NULL;            /* 실수부 문자열을 가리키는 포인터 */
  char *fraction = NULL;            /* 소수부 문자열을 가리키는 포인터 */
  size_t length = 0;                /* 필요한 전체 문자열 길이         */

  integral = int_to_str((int)x);    /* 부호를 포함한 정수부를 문자열로 변환 */

  /* x를 양수로 바꿈 */
  if(x<0)
    x = -x;
  /* 소수부를 문자열로 변환 */
  fraction = int_to_str((int)(100.0*(x+0.005-(int)x)));

  length = strlen(integral)+strlen(fraction)+2;  /* 소수점과 종료문자를 포함한 전체 길이 */

  /* 소수부는 2개의 숫자로 이뤄져야 함 */
  if(strlen(fraction)<2)
    ++length;

  str = (char*)malloc(length);        /* 전체 실수의 메모리 할당 */
  strcpy(str, integral);              /* 정수부 복사             */
  strcat(str, ".");                   /* 소수점 연결             */

  if(strlen(fraction)<2)              /* 소수부 숫자가 2개 미만일 경우 */
    strcat(str,"0");                  /* 0을 붙임                      */

  strcat(str, fraction);              /* 소수부 연결 */

  /* 메모리 해제 */
  free(integral);
  free(fraction);

  return str;
}

/***************************************************************************
 * 정수 인자를 문자열로 변환하는 함수.                                     *
 * 메모리를 할당해 문자열을 저장하며, 호출하는 쪽에서 해제해야 함          *
 ***************************************************************************/
char* int_to_str(int n)
{
  char *str = NULL;                    /* 문자열을 가리키는 포인터 */
  int length = 1;                      /* 문자열에 있는 문자 개수(최소 1개) */
  int temp = 0;
  int sign = 1;                        /* n의 부호를 표시 */

  /* 음수인지 확인 */
  if(n<0)
  {
    sign = -1;
    n = -n;
    ++length;                          /* 마이너스 기호가 들어갈 공간 */
  }

  /* length를 n의 숫자 개수만큼 증가시킴 */
  temp = n;
  do
  {
    ++length;
  }
  while((temp /= 10)>0);

  str = (char*)malloc(length);        /* 필요한 공간 할당   */

  if(sign<0)                          /* 음수이면           */
    str[0] = '-';                     /* 마이너스 기호 삽입 */

  str[--length] = '\0';               /* 종료문자 연결      */

  /* 숫자를 차례대로 추가 */
  do
  {
    str[--length] = '0'+n%10;
  }while((n /= 10) > 0);

  return str;
}
