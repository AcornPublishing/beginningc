/* ���α׷� 5.1 - 10���� ������ �������� �ʰ� ��� ���ϱ� */
#include <stdio.h>

void main() 
{ 
	int number = 0; 											/* ���� ������ ���� 	*/ 
	int count = 10; 											/* �о���� ���� ����	*/ 
	long sum = 0L; 												/* ���� �� 				*/ 
	float average = 0.0f; 										/* ���� ��� 			*/ 
	int i = 0; 													/* ���� ī���� 			*/ 

	/* ����� ���� 10���� ���� �о���� */
	for(i = 0; i < count; i ++)
	{
		printf("������ �Է��ϼ���: ");
		scanf("%d", &number); 								/* ���� �о���� 			*/
		sum += number; 										/* �о���� ���� sum�� ���� */
	} 

	average = (float)sum/count; 										/* ��� ���	*/ 

	printf("\n�л� 10���� ����� %f���Դϴ�.\n", average); 
} 
