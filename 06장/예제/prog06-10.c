/* ���α׷� 6.10 ��й�ȣ�� ��ȣȭ */ 
#include <stdio.h> 

void main() 
{ 
	char unencrypted[] = "abcdefghijklmnopqrst"; 						/* �⺻ ��й�ȣ 			*/ 
	char encrypted[21]; 												/* ��ȣȭ�� ��й�ȣ ����	*/ 
	char password[80]; 													/* �Է� ���� 				*/ 
	int i = 0;															/* ���� ī����				*/
	long code = 0L; 													/* ��ȣȭ�� ���� ���� 		*/ 

	printf("\n��ȣ�� �Է��ϼ���(20�� �̳�, ���鹮�� �ԷºҰ�):\n");
	scanf("%s", password); 												/* ��ȣ�� �Է¹��� 			*/

	/* �Է¹��� ��й�ȣ�� �迭 unencrypted�� ���� */
	for(i = 0; i < 20 && password[i] != '\0'; i++)
		unencrypted[i] = password[i];

	/* ù��° ������ ��ȣȭ�� ����� �¼� ���� */
	code = 0;
	for (i = 0; i < 20; code += unencrypted[i++]); 						/* �����ڵ��� ���� ���		*/
	code %= 52; 														/* 52�� ���� ������ 		*/
	code += code < 26 ? 'A' : ('a' - 26); 								/* �ش��ϴ� ���ĺ� ����		*/

	/* ��й�ȣ ���ڿ� ��ȣȭ */
	for (i = 0; i < 20; i++)
	{ 
		code *= unencrypted[i]; 										/* ��ȣȭ�� ���ڸ� ���� 	*/ 
		code %= 52; 													/* ������ ��� 				*/ 
		code += (code < 26) ? 'A' : ('a' - 26); 						/* ���� ���� 				*/ 
		encrypted[i] = (char)code; 										/* ��ȣȭ�� ���� ���� 		*/ 
	} 		
	encrypted[i] = '\0'; 												/* ���Ṯ�� ���� 			*/ 

	printf("\n��ȣȭ�� ��й�ȣ�� %s�Դϴ�.", encrypted); 
} 
