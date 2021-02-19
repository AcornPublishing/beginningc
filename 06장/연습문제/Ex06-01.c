/* 연습문제 6.1 정수를 단어로 */
#include <stdio.h>
#include <string.h>

void main()
{
  char *unit_words[] = {"영", "일","이","삼","사","오","육","칠","팔","구"};
  char hundred[] = "백";
  char ten[] = "십";
  char value_str[50] = "";
  int value = 0;                       /* 변환할 정수        */
  int digits[] = {0,0,0};              /* 입력받은 값의 숫자 */
  int i = 0;

  printf("1000보다 작은 정수를 입력하세요: ");
  scanf("%d",&value);
  if(value>=1000)
    value =999;
  else if(value<1)
    value = 1;

  while(value>0)
  {
    digits[i++] = value%10;
    value /= 10;
  }

  if(digits[2]>0)
  {
    if(digits[2]==1)
	  strcat(value_str, hundred);
	else
	  strcat(strcat(value_str,unit_words[digits[2]]), hundred);
  }

  if(digits[1]>0)
  {
	strcat(value_str, " ");
	if(digits[1]==1)
	  strcat(value_str, ten);
	else
	  strcat(strcat(value_str, unit_words[digits[1]]),ten);
  }

  if(digits[0]>0)
	strcat(strcat(value_str, " "), unit_words[digits[0]]);

  printf("입력하신 값은 %s입니다.", value_str);
}

