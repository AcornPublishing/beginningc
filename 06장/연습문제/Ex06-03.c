/* 연습문제 6.3 임의로 출력되는 오늘의 명언 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
  char thoughts[][50] = {"낮말은 새가 듣고 밤말은 쥐가 듣는다",
                         "쇠 귀에 경 읽기",
                         "백지장도 맞들면 낫다",
                         "사공이 많으면 배가 산으로 올라간다",
                         "구르는 돌에는 이끼가 끼지 않는다",
                         "고기는 씹어야 맛이고 말은 해야 맛이다"};
 
  srand((unsigned int)time(NULL));

  printf("오늘의 명언\n\n%s\n", thoughts[rand()%(sizeof thoughts/sizeof thoughts[0])]);
}

