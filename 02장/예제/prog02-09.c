/* ���α׷� 2.9 ���̺��� �ѷ��� ����*/
#include <stdio.h>
#define PI 3.14159f 					/* ��ȣ PI�� ���� */

void main() 
{ 
	float radius = 0.0f; 
	float diameter = 0.0f; 
	float circumference = 0.0f; 
	float area = 0.0f; 

	printf("���̺��� ������ �Է��ϼ���:");
	scanf("%f", &diameter);
	radius = diameter/2.0f;
	circumference = 2.0f*PI*radius;
	area = PI*radius*radius;
	printf("\n�ѷ��� %.2f�Դϴ�.", circumference);
	printf("\n������ %.2f�Դϴ�.", area);
} 
