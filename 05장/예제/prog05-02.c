/* Program 5.2 10���� ���� ��� ���ϱ� - ��ٷο� ������� ���� ���� */ 
#include <stdio.h> 

void main() { 
	int number0 = 0, number1 = 0, number2 = 0, number3 = 0, number4 = 0; 
 
	int number5 = 0, number6 = 0, number7 = 0, number8 = 0, number9 = 0; 

	long sum = 0L; 											/* ���� ��		*/ 
	float average = 0.0f; 									/* ���� ���	*/ 
	/* ����� ���� 10���� ���� �о���� */
	printf("ó�� 5���� ������ �Է��ϼ���.\n");
	printf("������ ���� ���̿��� �����̽��� ���͸� ��������.\n");
	scanf("%d%d%d%d%d", &number0, &number1, &number2, &number3, &number4);
	printf("���� 5���� ������ �Է��ϼ���.\n");
	printf("������ ���� ���̿��� �����̽��� ���͸� ��������.\n");
	scanf("%d%d%d%d%d", &number5, &number6, &number7, &number8, &number9);
	/* ���� 10���� ������ ��� ������Ƿ�, ����� ����� �� �ִ� */
	sum = number0 + number1+ number2 + number3 + number4 +	
				number5 + number6 + number7 + number8 + number9;
	average = (float)sum/10.0f;

	printf("\n�Է��� ���� 10���� ����� %f���Դϴ�.\n", average); 
} 
