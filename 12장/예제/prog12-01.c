/* ���α׷� 12.1 �� ���� �� ���ھ� ���Ͽ� ���� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{ 
	char mystr[80]; 											/* �Է� ���ڿ� 			*/ 
	int i = 0; 													/* ���� ī���� 			*/ 
	int lstr = 0; 												/* �Է� ���ڿ��� ����	*/ 
	int mychar = 0; 											/* ����� ���� 			*/ 
	FILE *pfile = NULL; 										/* ���� ������ 			*/ 
	char *filename = "C:\\myfile.txt"; 

	printf("\n���ϴ� ���ڿ��� �Է��ϼ���.\n");
	gets(mystr); 												/* ���ڿ��� ���� 		*/

	/* �� �� �ִ� �� ���� ����� */
	pfile = fopen(filename, "w"); 
	if(pfile == NULL)
	{
		printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
		abort();
	}

	lstr = strlen( mystr );
	for(i = lstr-1 ; i >= 0 ; i--)
		fputc(mystr[i], pfile); 								/* ���ڿ��� ������ ���Ͽ� ���� 	*/

	fclose(pfile); 												/* ���� �ݱ� 					*/ 
	/* �б� �뵵�� ���� ���� */
	pfile = fopen(filename, "r"); 
	if(pfile == NULL) 
	{ 
		printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename); 
		abort(); 
	} 

	/* ���Ͽ��� ���ڸ� �о� ����� */ 
	while((mychar = fgetc(pfile)) != EOF) 
		putchar(mychar); 										/* ���Ͽ� ��ϵ� ���ڸ� ���	*/ 
	putchar('\n'); 												/* �ٹٲ޹��� ���				*/ 

	fclose(pfile); 												/* ���� �ݱ� 					*/ 
	remove(filename); 											/* ������ ���� ����� 			*/ 
} 
