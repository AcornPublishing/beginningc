/* 연습문제 8.2 정수를 문자열로 반환하는 함수 */
#include <stdio.h>

/* 정수를 문자열로 변환하는 함수               */
/* 함수를 호출하는 쪽에서 메모리를 할당해야 함 */
/* 함수는 문자열을 반환해 표현식에서 활용할 수 */
/* 있도록 해야 한다.                           */
char* itoa(int n, char str[])
{
  int i = 0;               /* 루프 카운터        */
  int negative = 0;        /* 음의 정수인지 확인 */
  int length = 0;          /* 문자열의 길이      */
  int temp = 0;            /* 임시 저장소        */
 
  if(negative = (n<0))     /* 음의 정수인가?   */
    n = -n;                /* 양의 정수로 바꿈 */

  /* 역순으로 숫자를 만들어 냄 */
  do
  {
    str[i++] = '0'+n%10;    /* 맨 왼쪽 문자 만들기     */
    n /= 10;                /* 숫자 지움               */              
  }while(n>0);              /* 숫자가 없을 때까지 반복 */

  if(negative)              /* 음의 정수이면        */
    str[i++] = '-';         /* 마이너스 기호를 붙임 */
  str[i] = '\0';            /* 문자열 종료문자 연결 */
  length = i;               /* 길이를 저장          */

  /* 문자열을 반대로 뒤집음                 */
  /* 마지막 문자가 맨 앞으로, 두번째 문자가 */
  /* 뒤에서 두번째 문자로 이동하는 식       */
  for(i = 0 ; i<length/2 ;i++)
  {
    temp = str[i];
    str[i] = str[length-i-1];
    str[length-i-1] = temp;
  }
  return str;                /* 문자열 반환 */
}


void main()
{
   char str[15];              /* 정수를 변환한 문자열을 저장 */
   long testdata[] = { 30L, -98L, 0L, -1L, 999L, -12345L};  
   int i = 0;                /* 루프 제어변수      */

   for (i = 0 ; i< sizeof testdata/sizeof(long) ; i++)
     printf("입력한 정수는 %d이고, 변환한 문자열은 %s입니다.\n", testdata[i], itoa(testdata[i],str));
}

