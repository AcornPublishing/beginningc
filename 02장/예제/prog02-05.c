/* ���α׷� 2.5 ��Ű�� ���� ��� */ 
#include <stdio.h> 

void main() 
{ 	
	int cookies = 5; 
	int cookie_calories = 125; 									/* ��Ű 1���� Į�θ� 		  */ 
	int total_eaten = 0; 										/* ���� ��Ű�� ��ü ����	  */ 

	int eaten = 2; 												/* ���� ��Ű�� ���� 		  */
	cookies = cookies - eaten; 									/* cookies���� ���� ������ �� */
	total_eaten = total_eaten + eaten;
	printf("\n���� ��Ű�� %d�� �Ծ����. ���� %d�� ���Ҿ��.",
		eaten, cookies); 

	eaten = 3; 													/* ���� ��Ű�� ���ο� ���� 	  */
	cookies = cookies - eaten; 									/* cookies���� ���� ������ �� */
	total_eaten = total_eaten + eaten;
	printf("\n���� ��Ű�� %d�� �� �Ծ����. ���� %d�� ���Ҿ��.\n",
		eaten, cookies); 
	printf("\n���ݱ��� ���� ��Ű�� ������ %dĮ�θ��Դϴ�.\n",
		total_eaten*cookie_calories); 
} 
