/* ���α׷� 8.3 �� �Ǽ� ���� ��� */
#include <stdio.h>

/* ����� ���ϴ� �Լ��� ���� */
float average(float x, float y)
{
	return (x + y)/2.0f;
}

/* ���� ���α׷� - ���α׷��� ������ �׻� ���⿡�� ���� */
void main()
{
	float average(float x, float y); 				/* �Լ� ���� */ 

	float value1 = 0.0F;
	float value2 = 0.0F;
	float value3 = 0.0F;

	printf("�Ǽ��� 2�� �Է��ϼ���. �� ���� �����̽��ٸ� ���� �����ϼ���: ");
	scanf("%f %f", &value1, &value2);
	value3 = average(value1, value2);
	printf("\n�� ���� ����� %f�Դϴ�.\n", value3);
} 
