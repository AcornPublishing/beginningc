/* ���α׷� 6.11 ��й�ȣ �˻� */
#include <stdio.h>
#include <string.h>

void main() 
{ 
	/* ���⿡ �������� ��й�ȣ�� ��ȣȭ�� ���·� �Է��Ѵ�. 		*/ 
	/* �� ��ȣ�� �״�� ����ϰڴٸ�, ��ȣ�� AcornPublishing�̴�.	*/ 
	char encrypted[] = "NaDEyINAANaANAnwfgps"; 
	char password[80]; 														/* �Է� ���� 				*/ 
	char unencrypted[21]; 													/* ��ȣȭ���� ���� ��й�ȣ */ 
	int i = 0; 																/* ���� ī���� 				*/ 
	long code = 0; 															/* ��ȣȭ�� ���� ���� 		*/ 

	for( ;; ) { 
		strcpy(unencrypted, "abcdefghijklmnopqrst"); 						/* unencrypted �ʱ�ȭ 		*/ 
		printf("\n��ȣ�� �Է��ϼ���(20�� �̳�, ���鹮�� �ԷºҰ�):\n");
		scanf("%s", password); 												/* ��й�ȣ�� �о���� 		*/

		/* �Է¹��� ��й�ȣ�� �迭 unencrypted�� ���� */
		for(i = 0; i < 20 && password[i] != '\0'; i++)
			unencrypted[i] = password[i];

		/* ù��° ������ ��ȣȭ�� ���� �¼� ���� */
		code = 0;
		for (i = 0; i < 20; code += unencrypted[i++]);						/* �����ڵ��� ���� ��� 	*/

		code %= 	52; 													/* 52�� ���� ������ ��� 	*/ 
		code += code < 26 ? 'A' : ('a' - 26); 								/* ���ĺ� ����				*/ 

		for (i = 0; i < 20; i++)
		{
			code *= unencrypted[i]; 										/* ��ȣȭ�� ���ڸ� ���� 	*/ 
			code %= 52; 													/* 52�� ���� ������ ���	*/ 
			code += (code < 26) ? 'A' : ('a' - 26); 						/* ���ĺ� ���� 				*/ 
			password[i] = (char)code; 										/* ��ȣȭ�� ���� ����		*/ 
		}
		password[i] = '\0';
		if(!strcmp(password, encrypted))
		{
			printf("\n���ٱ����� ���εƽ��ϴ�.\n"); 
			break;
		}
		else
			printf("\n��й�ȣ�� �ùٸ��� �ʽ��ϴ�.\n"); 
	} 
} 
