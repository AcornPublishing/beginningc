/* ���α׷� 11.2 ����ü ���� */ 
#include <stdio.h>
#include <ctype.h>
void main() 		
{
	struct horse 																					/* ����ü ���� 			*/	
	{
		int age;
		int height;
		char name[20];
		char father[20];
		char mother[20];
	};	

	struct horse My_horses[50]; 											/* ����ü �迭 ����	*/
	int hcount = 0; 														/* ���� ���� �� 	*/
	int i = 0; 																/* ���� ī���� 		*/
	char test = '\0'; 														/* ���� ��Ÿ���� ��	*/

	for(hcount = 0; hcount < 50 ; hcount++ )
	{ 
		printf("\n%s���� �������� �Է��Ͻðڽ��ϱ�(Y/N)? ", hcount?"�ٸ� " : "" );
		scanf("%c", &test );
		if(tolower(test) == 'n')
			break;

		printf("\n���� �̸��� �Է��ϼ���: " );
		scanf("%s", My_horses[hcount].name ); 								/* ���� �̸� �Է� 	*/

		printf("\n%s�� ���̴�? ", My_horses[hcount].name );
		scanf("%d", &My_horses[hcount].age ); 								/* ���� ���� �Է� 	*/

		printf("\n%s�� Ű��(cm)? ", My_horses[hcount].name );
		/* ���� Ű �Է� */
		scanf("%d", &My_horses[hcount].height );

		printf("\n%s�� �ƺ���? ", My_horses[hcount].name );
		/* �ƺ��� �̸� �Է� */
		scanf("%s", My_horses[hcount].father ); 

		printf("\n%s�� ������? ", My_horses[hcount].name );
		/* ������ �̸� �Է� */
		scanf("%s", My_horses[hcount].mother ); 
	}

	/* �Է��� ���� Ȯ�� */
	for (i = 0 ; i < hcount ; i++ )
	{ 
		printf("\n\n%s�� ���̴� %d���̰� Ű�� %dcm�̸�,", 
						My_horses[i].name, My_horses[i].age, My_horses[i].height); 
		printf(" �ƺ��� %s�̰� ������ %s�Դϴ�.", My_horses[i].father, 
						My_horses[i].mother ); 
	} 
} 
