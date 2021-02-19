/* 연습문제 3.1 온도변환 */
#include <stdio.h>

void main()
{
  int choice = 0;
  double temperature = 0.0;
  printf("이 프로그램은 다음과 같은 일을 합니다:\n"
         "1. 섭씨를 화씨로 변환\n"
         "2. 화씨를 섭씨로 변환\n"
         "번호를 선택하세요(1 또는 2): ");
  scanf("%d", &choice);
 
  printf("온도를 %s 단위로 입력하세요: ",
                          (choice == 1 ?  "섭씨" : "화씨"));
  scanf("%lf", &temperature);

  if(choice == 1)
    printf("변환한 값은 화씨 %.2lf도입니다.\n", temperature*9.0/5.0+32.0);
  else
    printf("변환한 값은 섭씨 %.2lf도입니다.\n", (temperature-32.0)*5.0/9.0);
}
