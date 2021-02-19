/* ���α׷� 12.6 ���� ��� */
#include <stdio.h>
#include <ctype.h> 
#include <string.h> 

#define DISPLAY 80 															/* ����� ���� ���� 	 */ 
#define PAGE_LENGTH 20 														/* �� �������� ���� ���� */ 

int main(int argc, char *argv[]) 
{ 
	char filename[80]; 														/* �����̸��� ������ ����	*/ 
	FILE *pfile; 															/* ���� ������ 				*/ 
	unsigned char buffer[DISPLAY/4 - 1]; 									/* ���� �Է� ���� 			*/
	int count = 0; 															/* ���ۿ� �ִ� ������ ���� 	*/
	int lines = 0; 															/* ����� ���� ���� 		*/
	int i = 0; 																/* ���� ī���� 				*/

	if(argc == 1) 															/* ����࿡ �����̸��� ����?	*/ 
	{ 			
		printf("�����̸��� �Է��ϼ���: "); 									/* �Է��϶�� ���ù��� ���		*/ 
		gets(filename); 													/* �Էµ� �����̸��� ���� 		*/ 
	} 			
	else
		strcpy(filename, argv[1]); 											/* �ι�° ����� ���ڿ��� ����	*/

	/* ������ �������� ���� �ִ°�? */
	if((pfile = fopen(filename, "rb")) == NULL) 
	{
		printf("�˼��մϴ�. %s ������ �� �� �����ϴ�.", filename); 
		return -1;
	} 	
	while(!feof(pfile)) 													/* ���� ������ ��� �ݺ� 		*/ 
	{ 
		if(count < sizeof buffer) 											/* ���۸� ���� ä���� �ʾ�����	*/ 
			buffer[count++] = (unsigned char)fgetc(pfile); 					/* ���ڸ� �ϳ� �о���� 		*/ 
		else 
		{ 	/* ���ۿ� �ִ� �����͸� ���� 16���� �������� ��� */ 
			for(count = 0; count < sizeof buffer; count++) 
				printf("%02X ", buffer[count]); 
			printf("| "); 													/* �� ���й��� ���		*/ 

			/* ���ۿ� �ִ� �����͸� ���� �������� ��� */ 
			for(count = 0; count < sizeof buffer; count++) 
				printf("%c", isprint(buffer[count]) ? buffer[count]:'.'); 
			printf("\n"); 													/* �� ���� ���� 		*/ 
			count = 0; 														/* count�� �ʱ�ȭ		*/ 

			if(!(++lines%PAGE_LENGTH)) 										/* �������� �����°�?	*/ 
				if(getchar()=='E') 											/* ����� �Է��� ��ٸ�	*/ 
					return 0; 												/* ����ڰ� E�� ������ 	*/ 
		} 		
	} 		

	/* ������ ���� ���� 16���� �������� ��� */
	for(i = 0; i < sizeof buffer; i++)
		if(i < count)
			printf("%02X ", buffer[i]); 									/* 16���� ���		*/
		else
			printf(" "); 													/* �����̽� ��� 	*/
	printf("| "); 															/* ���й��� ���	*/
 
	/* ������ ���� ���� �������� ��� */ 
	for(i = 0; i < count; i++)
		printf("%c",isprint(buffer[i]) ? buffer[i]:'.'); 					/* ���� ��� */
	printf("\n"); 															/* ���� ���� */
	fclose(pfile); 															/* ���� �ݱ� */
	return 0; 		
} 			

