/* 연습문제 10.1 키보드에서 특정 유형의 문자열 읽기 */
/*
유형 1: 하나 이상의 알파벳 소문자 다음에 하나의 숫자가 나오는 문자열 (예: number1) 
유형 2: 대문자로 시작하는 2개의 단어. 두 단어는 하이픈으로 연결됨 (예: Seven-Up) 
유형 3: 10진수 (예: 7.35) 
유형 4: 대문자, 소문자, 스페이스로 이뤄진 문자열 (예: East Hill)
유형 5: 스페이스와 숫자를 제외한 모든 문자로 이뤄진 문자열 (예: floating-point)

각 문자열이 이전 문자열에 없는 문자로 시작한다는 점을 활용하자. 따라서 각 문자열의
문자는 뒤따라 나오는 문자열의 첫번째 문자가 아님을 지정하면 된다.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
   char word1[50];
   char word2[50];
   char word3[50];
   char word4[50];
   char word5[50];
   char temp[50];
   int k = 0;

   printf("5개의 문자열을 입력하세요:\n");

   /* 처음에는 소문자, 나중에 숫자가 나오는 첫번째 문자열 */
   k = scanf(" %[abcdefghijklmnopqrstuvwxyz]%1[0123456789]", word1, temp);
   if(k<2)
   {
     printf("첫번째 문자열에서 오류 발생 - 프로그램 종료\n");
     exit(1);
   }
   strcat(word1,temp);

   /* 두번째 문자열. 대문자가 나오고, 그 뒤에 문자, 하이픈, 대문자, 
      문자가 나옴                                                
   */
   k = scanf(" %1[ABCDEFGHIJKLMNOPQRSTUVWXYZ]", word2);
   if(k<1)
   {
     printf("두번째 문자열에서 오류 발생 - 프로그램 종료\n");
     exit(1);
   }
   scanf("%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]", temp);
   strcat(word2,temp);
   k = scanf("%1[-]", temp);
   if(k<1)
   {
     printf("두번째 문자열에서 오류 발생 - 프로그램 종료\n");
     exit(1);
   }
   k = scanf(" %1[ABCDEFGHIJKLMNOPQRSTUVWXYZ]", temp);
   if(k<1)
   {
     printf("두번째 문자열에서 오류 발생 - 프로그램 종료\n");
     exit(1);
   }
   strcat(word2,temp);
   scanf("%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]", temp);
   strcat(word2,temp);

   /* 세번째 문자열. 10진수를 문자열로 읽어들인다.*/
   k = scanf(" %[0123456789.-]", word3);
   if(k<1)
   {
     printf("세번째 문자열에서 오류 발생 - 프로그램 종료\n");
     exit(1);
   }

   /* 네번째 문자열 */
   scanf("%[ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]", word4);
   if(k<1)
   {
     printf("네번째 문자열에서 오류 발생 - 프로그램 종료\n");
     exit(1);
   }

   /* 다섯번째 문자열. 줄바꿈 문자는 포함시키면 안됨 */
   scanf(" %[^ 0123456789\n]", word5);

   printf("입력한 문자열은 다음과 같습니다.\n%s  %s  %s  %s  %s\n",
            word1, word2, word3, word4, word5);
}

