/* ���α׷� 2.12 �뵵�� �´� �������� ���� 2 */ 
#include <stdio.h> 

void main() 
{ 
	const float Revenue_per_150 = 4.5f; 
	short JanSold = 23500; 											/* 1���� �Ǹ��� ��ǰ 	  */ 
	short FebSold = 19300; 											/* 2���� �Ǹ��� ��ǰ 	  */ 
	short MarSold = 21600; 											/* 3���� �Ǹ��� ��ǰ 	  */ 
	float RevQuarter = 0.0f; 										/* 1�б� ����� 		  */ 

	long QuarterSold = JanSold + FebSold + MarSold;					/* 1�б� ��ü �Ǹŷ� ��� */ 

	/* ���� ��ǰ �Ǹŷ��� �б� ��ü �Ǹŷ��� ��� */
	printf("\n���� ��ǰ �Ǹŷ�\n 1��: %d\n 2��: %d\n 3��: %d",
					JanSold, FebSold, MarSold);
	printf("\n1�б� �� ��ǰ �Ǹŷ�: %ld",QuarterSold);

	/* 1�б� �� ������� ����ϰ� ����� */ 
	RevQuarter = QuarterSold/150*Revenue_per_150; 
	printf("\n1�б� ��ü �����: %.2f����\n",RevQuarter); 
} 
