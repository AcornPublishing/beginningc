/* ���α׷� 3.6 ���ż����� ���� ���� ������� ������ ������ */ 
#include <stdio.h> 

void main() 
{ 
	const double unit_price = 5000.0; 				/* ��ǰ �ϳ��� ���� 	   */ 
	const double discount1 = 0.05; 					/* 10�� �̻� ���Ž� ������ */ 
	const double discount2 = 0.1; 					/* 20�� �̻� ���Ž� ������ */ 
	const double discount3 = 0.15; 					/* 50�� �̻� ���Ž� ������ */ 
	double total_price = 0.0; 
	int quantity = 0; 

	printf("���� ������ �Է��ϼ���: "); 			/* �޽��� ��� 			   */
	scanf("%d", &quantity); 						/* �Է°��� �о���� 	   */

	total_price = quantity*unit_price*(1.0 -
					(quantity>=50 ? discount3 : (
						quantity>=20 ? discount2 : (
							quantity>=10 ? discount1 : 0.0))));

	printf("%d���� �����Ͻø� %.0f���Դϴ�.\n", quantity, total_price); 
} 
