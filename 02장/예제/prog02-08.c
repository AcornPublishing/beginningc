/* ���α׷� 2.8 ���̺��� �ѷ��� ���� */ 
#include <stdio.h> 
 
void main() 
{ 
	float radius = 0.0f; 										/* ���̺��� ������ */ 
	float diameter = 0.0f; 										/* ���̺��� ����   */ 
	float circumference = 0.0f; 								/* ���̺��� �ѷ�   */ 
	float area = 0.0f; 											/* ���̺��� ����   */ 
	float Pi = 3.14159265f; 

	printf("���̺��� ������ �Է��ϼ���:");
	scanf("%f", &diameter); 									/* Ű���忡 �Է��� ������ �о���� */
	radius = diameter/2.0f; 									/* ������ ���					   */
	circumference = 2.0f*Pi*radius; 							/* �ѷ� ���					   */
	area = Pi*radius*radius; 									/* ���� ���					   */

	printf("\n�ѷ��� %.2f�Դϴ�.", circumference);
	printf("n������ %.2f�Դϴ�.\n", area);
} 
