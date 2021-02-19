/* �������� 11.1 ���̸� ǥ���ϴ� ����ü */
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
    printf("���̸� �ߵ�, ��Ʈ, ��ġ�� �Է��ϼ���: ");
    scanf(" %d %d %d", &length.yards, &length.feet, &length.inches);
    total = add(total,length);
    printf("�� �Է��Ͻðڽ��ϱ�(y/n)?: ");
    scanf(" %c", &answer);
  }while(tolower(answer) == 'y');
  printf("�Է��Ͻ� ������ �հ�� ������ �����ϴ�. ");
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
  printf("%d�ߵ� %d��Ʈ %d��ġ", length.yards,length.feet, length.inches);
}
