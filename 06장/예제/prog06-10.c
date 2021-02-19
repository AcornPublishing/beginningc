/* 프로그램 6.10 비밀번호의 암호화 */ 
#include <stdio.h> 

void main() 
{ 
	char unencrypted[] = "abcdefghijklmnopqrst"; 						/* 기본 비밀번호 			*/ 
	char encrypted[21]; 												/* 암호화한 비밀번호 저장	*/ 
	char password[80]; 													/* 입력 버퍼 				*/ 
	int i = 0;															/* 루프 카운터				*/
	long code = 0L; 													/* 암호화한 문자 저장 		*/ 

	printf("\n암호를 입력하세요(20자 이내, 공백문자 입력불가):\n");
	scanf("%s", password); 												/* 암호를 입력받음 			*/

	/* 입력받은 비밀번호를 배열 unencrypted에 복사 */
	for(i = 0; i < 20 && password[i] != '\0'; i++)
		unencrypted[i] = password[i];

	/* 첫번째 문자의 암호화에 사용할 승수 설정 */
	code = 0;
	for (i = 0; i < 20; code += unencrypted[i++]); 						/* 문자코드의 총합 계산		*/
	code %= 52; 														/* 52로 나눈 나머지 		*/
	code += code < 26 ? 'A' : ('a' - 26); 								/* 해당하는 알파벳 선택		*/

	/* 비밀번호 문자열 암호화 */
	for (i = 0; i < 20; i++)
	{ 
		code *= unencrypted[i]; 										/* 암호화할 문자를 곱함 	*/ 
		code %= 52; 													/* 나머지 계산 				*/ 
		code += (code < 26) ? 'A' : ('a' - 26); 						/* 문자 선택 				*/ 
		encrypted[i] = (char)code; 										/* 암호화한 문자 저장 		*/ 
	} 		
	encrypted[i] = '\0'; 												/* 종료문자 연결 			*/ 

	printf("\n암호화한 비밀번호는 %s입니다.", encrypted); 
} 
