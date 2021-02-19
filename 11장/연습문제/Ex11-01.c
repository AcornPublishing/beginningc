/* 연습문제 11.1 길이를 표현하는 구조체 */
#include <stdio.h>
#include <ctype.h>

#define INCHES_PER_FOOT 12
#define FEET_PER_YARD    3

struct Length
{
  unsigned int yards;
  unsigned int feet;
  unsigned int inches;
};

struct Length add(struct Length first, struct Length second);
void show(struct Length length);

void main()
{
  char answer = 'n';
  struct Length length;
  struct Length total = { 0,0,0};
  int i = 0;
  do
  {
    printf("길이를 야드, 피트, 인치로 입력하세요: ");
    scanf(" %d %d %d", &length.yards, &length.feet, &length.inches);
    total = add(total,length);
    printf("더 입력하시겠습니까(y/n)?: ");
    scanf(" %c", &answer);
  }while(tolower(answer) == 'y');
  printf("입력하신 길이의 합계는 다음과 같습니다. ");
  show(total);
  printf("\n");
}

struct Length add(struct Length first, struct Length second)
{
  unsigned long inches = 0;
  struct Length sum;
  inches = first.inches + second.inches+
    INCHES_PER_FOOT*(first.feet+second.feet+FEET_PER_YARD*(first.yards+second.yards));
  sum.inches = inches%INCHES_PER_FOOT;
  sum.feet = inches/INCHES_PER_FOOT;
  sum.yards = sum.feet/FEET_PER_YARD;
  sum.feet %= FEET_PER_YARD;
  return sum;
}

void show(struct Length length)
{
  printf("%d야드 %d피트 %d인치", length.yards,length.feet, length.inches);
}
