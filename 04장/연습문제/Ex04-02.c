/*연습문제 4.2 출력가능한 문자 출력 */
#include <stdio.h>
#include <ctype.h>

void main()
{
  int i = 0;                         /* 루프 카운터 */
  char ch = 0;                       /* 문자 코드값 */
  for(i = 0 ; i<128 ; i++)
  {
    ch = (char)i;
    if(ch%2==0)
      printf("\n");
    printf("  %4d    %c",ch,(isgraph(ch) ? ch : ' '));
  }
  printf("\n");
}

