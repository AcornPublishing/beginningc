/* ���α׷� 2.17 ������ ���� ����ϱ� */ 
#include <stdio.h> 

void main() 
{ 
	long shorty = 0L; 							/* ��Ƽ���� ������ ���ٸ��� Ű			  */ 
	long lofty = 0L; 							/* ��Ƽ���� ������ �մٸ��� Ű			  */ 

	long shorty_to_lofty = 0; 					/* ��Ƽ���� ������ �մٸ��� ���ٸ��� �Ÿ� */ 
	long lofty_to_tree = 0L; 					/* ��Ƽ���� ������ ���ٸ��� ������ �Ÿ�   */ 

	float meter = 0.0f;
	long tree_height = 0L; 						/* ��Ƽ���� ������ ������ ����            */

	const long centis_per_meter = 100L; 

	/* �մٸ��� Ű�� �Է� */ 
	printf("�մٸ��� Ű�� ��Ƽ���� ������ �Է��ϼ���: "); 
	scanf("%ld", &lofty); 

	/* ���ٸ��� Ű�� �����̱��� �Է� */
	printf("���ٸ��� Ű�� ��Ƽ���� ������ �Է��ϼ���: "); 
	scanf("%ld", &shorty); 

	/* ���ٸ��� �մٸ��� ������ �Ÿ��� �Է� */
	printf("�մٸ��� ���ٸ��� �Ÿ��� ���� ������ �Է��ϼ���: ");
	scanf("%f", &meter);
	shorty_to_lofty = (long)(meter * centis_per_meter);

	/* ���ٸ��� ������ ������ �Ÿ��� �Է� */
	printf("���ٸ��� ������ �Ÿ��� ���� ������ �Է��ϼ���: ");
	scanf("%f", &meter);
	lofty_to_tree = (long)(meter * centis_per_meter);

	/* ������ ���̸� ��Ƽ���� ������ ��� */ 
	tree_height = shorty + (shorty_to_lofty + lofty_to_tree) * (lofty-shorty) /
 				  shorty_to_lofty;

	/* ������ ���̸� ����, ��Ƽ���� �������� ��� */ 
	printf("\n������ ���̴� %ldm %ldcm�Դϴ�.\n", 
			tree_height / centis_per_meter, tree_height % centis_per_meter); 
} 
