/* ���α׷� 2.10 ���̺��� �ѷ��� ���� - �� �� �����ϰ� */ 
#include <stdio.h> 

void main() 
{ 	
	float diameter = 0.0f; 									/* ���̺��� ���� 		   */
	float radius = 0.0f; 									/* ���̺��� ������ 		   */
	const float Pi = 3.14159f; 								/* Pi�� ������ ������ ���� */

	printf("���̺��� ������ �Է��ϼ���:");
	scanf("%f", &diameter);
	radius = diameter/2.0f;
	printf("\n�ѷ��� %.2f�Դϴ�.", 2.0f*Pi*radius);
	printf("\n������ %.2f�Դϴ�.", Pi*radius*radius);
} 
