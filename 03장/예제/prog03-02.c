/* ���α׷� 3.2 if���� �̿��� ���� ���� �����ϱ� */ 
#include <stdio.h> 

void main() 
{ 
	const double unit_price = 5000.0; 								/* ��ǰ 1���� ����(��) */ 
	int quantity = 0; 
	printf("���� ������ �Է��ϼ���: "); 							/* �޽��� ���		   */ 
	scanf("%d", &quantity); 										/* �Է°��� �о����   */ 

	/* �ֹ� ������ ���� ��� �ش��ϴ��� �˻� */ 
	if(quantity > 10) 												/* 5% ����			   */ 
		printf("%d���� �����Ͻø� %.0f���Դϴ�.\n", quantity, quantity*unit_price*0.95); 
	else 															/* ���� ���� 		   */ 
		printf("%d���� �����Ͻø� %.0f���Դϴ�.\n", quantity, quantity*unit_price); 
} 
