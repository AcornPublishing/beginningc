/* 프로그램 6.6 문자열 비교 */
#include <stdio.h>
#include <string.h>
void main() 
{ 
	char word1[20]; 													/* 첫번째 단어를 저장할 문자열 */ 
	char word2[20]; 													/* 두번째 단어를 저장할 문자열 */ 

	printf("\n첫번째 단어를 입력하세요.\n1: ");
	scanf("%s", word1); 												/* 첫번째 단어를 입력받음 */
	printf("두번째 단어를 입력하세요.\n2: "); 
	scanf("%s", word2); 												/* 두번째 단어를 입력받음 */

	/* 두 단어를 비교함 */
	if(strcmp(word1,word2) == 0)
		printf("똑같은 단어를 두번 입력하셨습니다.\n");
	else
		printf("%s이(가) %s보다 앞섭니다.\n", 
			(strcmp(word1, word2) < 0) ? word1 : word2, 
			(strcmp(word1, word2) < 0) ? word2 : word1); 
} 

