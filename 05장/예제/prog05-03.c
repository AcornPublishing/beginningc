/* Program 5.3 10���� ���� ��� ���ϱ� - ���� ������� ���� ���� */ 
#include <stdio.h> 

void main() 
{ 	
	int numbers[10]; 												/* 10���� ���� ������ �迭	*/ 
	int count = 10; 												/* �о���� ���� ���� 		*/ 
	long sum = 0L; 													/* ������ ���� 				*/ 
	float average = 0.0f; 											/* ������ ��� 				*/ 
	int i = 0; 														/* ���� ī���� 				*/ 
		
	printf("\n10���� ������ �Է��ϼ���.\n"); 						/* �Է� ������Ʈ			*/ 
		
	/* ����� ���� ���� 10���� �о���� */
	for(i = 0; i < count; i ++)
	{
		printf("%2d> ",i+1);
		scanf("%d", &numbers[i]); 									/* ������ �о���� 			*/
		sum += numbers[i]; 											/* ������ sum�� ���� 		*/
	} 
	
	average = (float)sum/count; 									/* ��� ��� 				*/ 
	printf("\n�Է��� ���� 10���� ����� %f���Դϴ�.\n", average); 
} 
