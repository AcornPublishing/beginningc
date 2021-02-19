/* 연습문제 13.1 2개의 값을 비교하는 매크로 */
/*
  이 매크로는 어떤 데이터형의 값에서도 동작한다는 장점이 있다. 값은 변수이어도
  되고, 상수, 표현식도 가능하다. double형 매개변수의 함수로도 같은 일을 할 수 있
  으나, 이 경우 인자를 반드시 double형으로 변환해야 한다. 그러나 이 매크로에서는
  두 인자가 다른 데이터형일 때만 형변환된다.
*/
#include <stdio.h>

#define COMPARE(x,y)   ((x)<(y)?-1:((x)==(y)?0:1))

void main()
{
  double a = 1.5;
  int n = 2;
  float z = 1.1f;
  printf("\n%lf(double)와 %f(float)의 비교결과: %d", a , z, COMPARE(a,z));
  printf("\n%lf(double)와 %d(int)의 비교결과: %d", a , n, COMPARE(a,n));
  printf("\n%d(int)와 %f(float)의 비교결과: %d", n , z, COMPARE(n,z));
  printf("\n표현식 \"n*a\"의 값인 %lf(double)와\n"
    " 표현식 \"n+1\"의 값인 %d(int)의 비교결과: %d", n*a , n+1, COMPARE(n*a,n+1));
  printf("\n");
}


