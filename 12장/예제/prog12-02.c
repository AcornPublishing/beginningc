/* ���α׷� 12.2 �Ӵ��� ��ӵȴ� */ 
#include <stdio.h> 

void main() 
{ 
	char *proverbs[] = 
	{ 
		"Ƽ����� �»�.\n",
		"����� ������ �谡 ������ �ö󰣴�.\n",
		"���Ŀ� ���� �ڰ� ������ ���ڴ�.\n"
	};

	char more[60] = "�� �Ϳ� ���б�.\n";
	FILE *pfile = NULL; 												/* ���� ������		*/
	int i = 0; 															/* ���� ī����		*/
	char *filename = "C:\\myfile.txt";

	/* myfile.txt�� �������� ���� ��� �� ������ ���� */
	pfile = fopen(filename, "w");
	if(pfile == NULL)
	{
		printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
		abort();
	}

	/* ó�� 3���� �Ӵ��� ��� */
	for(i = 0 ; i < sizeof proverbs/sizeof proverbs[0] ; i++)
		fputs(proverbs[i], pfile);
	fclose(pfile); 														/* ���� �ݱ� 					*/

	pfile = fopen(filename, "a"); 										/* ������ ���� �뵵�� �ٽ� ���� */
	if(pfile == NULL)
	{
		printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename);
		abort();
	}

	fputs(more, pfile); 												/* �ٸ� �Ӵ��� ��			*/ 
	fclose(pfile); 														/* ������ ���� 				*/

	pfile = fopen(filename, "r"); 										/* ������ �б� �뵵�� ����	*/ 
	if(pfile == NULL)
	{
		printf("%s�� ���� ���� ������ �߻��߽��ϴ�. ���α׷��� �����մϴ�.", filename); 
		abort(); 
	} 
	while(fgets(more, 60, pfile) != NULL) 								/* �Ӵ��� �а�	*/ 
		printf("\n%s", more); 											/* ȭ�鿡 ���	*/ 

	fclose(pfile); 														/* ������ �ݰ�	*/ 
	remove(filename); 													/* ������ 		*/ 
} 
