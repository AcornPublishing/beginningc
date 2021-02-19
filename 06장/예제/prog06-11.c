/* 프로그램 6.11 비밀번호 검사 */
#include <stdio.h>
#include <string.h>

void main() 
{ 
	/* 여기에 여러분의 비밀번호를 암호화한 형태로 입력한다. 		*/ 
	/* 이 암호를 그대로 사용하겠다면, 암호는 AcornPublishing이다.	*/ 
	char encrypted[] = "NaDEyINAANaANAnwfgps"; 
	char password[80]; 														/* 입력 버퍼 				*/ 
	char unencrypted[21]; 													/* 암호화하지 않은 비밀번호 */ 
	int i = 0; 																/* 루프 카운터 				*/ 
	long code = 0; 															/* 암호화한 문자 저장 		*/ 

	for( ;; ) { 
		strcpy(unencrypted, "abcdefghijklmnopqrst"); 						/* unencrypted 초기화 		*/ 
		printf("\n암호를 입력하세요(20자 이내, 공백문자 입력불가):\n");
		scanf("%s", password); 												/* 비밀번호를 읽어들임 		*/

		/* 입력받은 비밀번호를 배열 unencrypted에 복사 */
		for(i = 0; i < 20 && password[i] != '\0'; i++)
			unencrypted[i] = password[i];

		/* 첫번째 문자의 암호화를 위한 승수 설정 */
		code = 0;
		for (i = 0; i < 20; code += unencrypted[i++]);						/* 문자코드의 총합 계산 	*/

		code %= 	52; 													/* 52로 나눈 나머지 계산 	*/ 
		code += code < 26 ? 'A' : ('a' - 26); 								/* 알파벳 선택				*/ 

		for (i = 0; i < 20; i++)
		{
			code *= unencrypted[i]; 										/* 암호화할 문자를 곱함 	*/ 
			code %= 52; 													/* 52로 나눈 나머지 계산	*/ 
			code += (code < 26) ? 'A' : ('a' - 26); 						/* 알파벳 선택 				*/ 
			password[i] = (char)code; 										/* 암호화한 문자 저장		*/ 
		}
		password[i] = '\0';
		if(!strcmp(password, encrypted))
		{
			printf("\n접근권한이 승인됐습니다.\n"); 
			break;
		}
		else
			printf("\n비밀번호가 올바르지 않습니다.\n"); 
	} 
} 
