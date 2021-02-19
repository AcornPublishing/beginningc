/*연습문제 4.3 출력가능한 문자와 공백문자의 이름 출력 */
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
    printf("  %4d",ch);
    if(isgraph(ch))
      printf("               %c",ch);
    else
      switch(ch)
    {
        case '\n':
           printf("      줄바꿈문자",ch);
           break;
        case ' ':
           printf("        스페이스",ch);
           break;
        case '\t':
           printf("        수평 탭",ch);
           break;
        case '\v':
           printf("        수직 탭",ch);
           break;
         case '\f':
           printf("         폼피드",ch);
           break;
        default:
           printf("                ");
           break;

    }

  }
  printf("\n");
}

